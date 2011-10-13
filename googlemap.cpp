#include "googlemap.h"
#include "datalog.h"

#include <QWebView.h>
#include <QWebPage.h>
#include <QWebFrame.h>
#include <QDir.h>
#include <QComboBox.h>
#include <qtgui/qvboxlayout>

#include <sstream>
#include <iostream>

using namespace std;

#define UNDEFINED_IDX -1

/******************************************************/
/* Helper class to fool google maps to give desktop view*/
class ChromePage : public QWebPage
{
	virtual QString userAgentForUrl(const QUrl& url) const {
	 return "Chrome/1.0";
	}
};

/******************************************************/
GoogleMap::GoogleMap()
{
	_view = new QWebView();
	_view->setPage(new ChromePage()); // hack required to get google maps to display for a desktop, not touchscreen
	_selection_begin_idx = UNDEFINED_IDX;
	_selection_end_idx = UNDEFINED_IDX;

	// Selection for path colour scheme
	_path_colour_scheme = new QComboBox();
	_path_colour_scheme->insertItem(0,"None");
	_path_colour_scheme->insertItem(1,"Heart Rate");
	_path_colour_scheme->insertItem(2,"Speed");
	_path_colour_scheme->insertItem(3,"Gradient");
	_path_colour_scheme->insertItem(4,"Cadence");
	_path_colour_scheme->insertItem(4,"Power");
	connect(_path_colour_scheme,SIGNAL(currentIndexChanged(int)), this, SLOT(definePathColour()));

	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(_view);
	layout->addWidget(_path_colour_scheme);
	//resize(700,270);
}

/******************************************************/
GoogleMap::~GoogleMap()
{

}

/******************************************************/
void GoogleMap::displayRide(DataLog* data_log)
{
	_data_log = data_log;

	ostringstream page;
	createPage(page);
	_view->setHtml(QString::fromStdString(page.str()));
	show();
}

/******************************************************/
void GoogleMap::setMarkerPosition(int idx)
{
	if (idx > 0 && idx < _data_log->numPoints())
	{
		double ltd = _data_log->ltd(idx);
		double lgd = _data_log->lgd(idx);

		ostringstream stream;
		stream << "setMarker(" << ltd << "," << lgd << ");";
		_view->page()->mainFrame()->evaluateJavaScript(QString::fromStdString(stream.str()));
	}
}

/******************************************************/
void GoogleMap::setSelection(int idx_start, int idx_end)
{
	ostringstream stream;
	stream << "var coords = [" << endl
		<< defineCoords(idx_start, idx_end) << endl // create a path from GPS coords
		<< "];" << endl
		<< "setSelectionPath(coords);";
	_view->page()->mainFrame()->evaluateJavaScript(QString::fromStdString(stream.str()));
}

/******************************************************/
void GoogleMap::beginSelection(int idx_begin)
{
	_selection_begin_idx = idx_begin;
}

/******************************************************/
void GoogleMap::endSelection(int idx_end)
{
	_selection_end_idx = idx_end;
	if (_selection_end_idx > _selection_begin_idx)
	{
		setSelection(_selection_begin_idx,_selection_end_idx);
	}
	else
	{
		setSelection(_selection_end_idx,_selection_begin_idx);
	}
}

/******************************************************/
void GoogleMap::zoomSelection(int idx_start, int idx_end)
{
	if (idx_start == 0 && idx_end == _data_log->numPoints()-1) // check if zoomed to full view
	{
		_selection_begin_idx = UNDEFINED_IDX;
		_selection_end_idx = UNDEFINED_IDX;

		ostringstream stream;
		stream << "deleteSelectionPath();";
		_view->page()->mainFrame()->evaluateJavaScript(QString::fromStdString(stream.str()));
	}
	else // handle the case where zooming out, but not to full view
	{
		_selection_begin_idx = idx_start;
		_selection_end_idx = idx_end;
		setSelection(_selection_begin_idx,_selection_end_idx);
	}
}

/******************************************************/
void GoogleMap::moveSelection(int delta_idx)
{
	int i = std::max(_selection_begin_idx - delta_idx, 0);
	int j = std::min(_selection_end_idx - delta_idx, _data_log->numPoints());
	setSelection(i, j);
}

/******************************************************/
void GoogleMap::moveAndHoldSelection(int delta_idx)
{
	_selection_begin_idx = std::max(_selection_begin_idx - delta_idx, 0);
	_selection_end_idx = std::min(_selection_end_idx - delta_idx, _data_log->numPoints());
	setSelection(_selection_begin_idx,_selection_end_idx);
}

/******************************************************/
void GoogleMap::definePathColour()
{
	ostringstream stream;
	stream.precision(2); // only need low precision
	stream.setf(ios::fixed,ios::floatfield);

	stream << "var key = [" << endl;

	double factor;
	for (int i=0; i < _data_log->numPoints()-1; ++i) // one less key since there is one more polyline segment in the path
	{
		double key = 0.0;
		switch (_path_colour_scheme->currentIndex())
		{
		case 0: // none
			key = 1.0;
			break;
		case 1: // heart rate
			factor = 0.9;
			if (_data_log->maxHeartRate() > 0)
				key = ((_data_log->heartRate(i)/_data_log->maxHeartRate())*(1.0+factor) ) - factor;
			break;
		case 2: // speed
			factor = 0.1;
			if (_data_log->maxSpeed())
				key = ((_data_log->speed(i)/_data_log->maxSpeed())*(1.0+factor) ) - factor;
			break;
		case 3: // gradient
			if (_data_log->maxGradient())
				key = (_data_log->gradient(i)/(_data_log->maxGradient()*0.5 + 0.00001) ) + 0.5;
			break;
		case 4: // cadence
			factor = 0.9;
			if (_data_log->maxCadence())
				key = ((_data_log->cadence(i)/_data_log->maxCadence())*(1.0+factor) ) - factor, 0.0;
			break;
		case 5: // power
			factor = 0.7;
			if (_data_log->maxPower())
				key = ((_data_log->power(i)/_data_log->maxPower())*(1.0+factor) ) - factor;
			break;
		}
		key = std::max(key,0.0);
		key = std::min(key,1.0);
		stream << key << ", ";
	}

	stream << "];" << endl; 
	stream << "strokeRidePath(key);";
	_view->page()->mainFrame()->evaluateJavaScript(QString::fromStdString(stream.str()));
}

/******************************************************/
std::string GoogleMap::defineCoords(int idx_start, int idx_end)
{
	ostringstream stream;
	stream.precision(6); // set precision so we plot lat/long correctly
	stream.setf(ios::fixed,ios::floatfield);

	for (int i = idx_start; i < idx_end; ++i)
	{
		stream << "new google.maps.LatLng(" << _data_log->ltd(i) << "," << _data_log->lgd(i) << ")," << endl;
	}

	return stream.str();
}

/******************************************************/
void GoogleMap::createPage(std::ostringstream& page)
{
	ostringstream oss;
    oss.precision(6); // set precision so we plot lat/long correctly
	oss.setf(ios::fixed,ios::floatfield);

	oss << "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "<head>" << endl
		<< "<meta name=\"viewport\" content=\"initial-scale=1.0, user-scalable=no\" />" << endl
		<< "<style type=\"text/css\">" << endl
		<< "html { height: 100% }" << endl
		<< "body { height: 100%; margin: 0; padding: 0 }" << endl
		<< "#map_canvas { height: 100% }" << endl
		<< "</style>" << endl
		<< "<script type=\"text/javascript\"" << endl
	    << "src=\"http://maps.googleapis.com/maps/api/js?v=3.1&sensor=true\">" << endl
		<< "</script>" << endl
		<< "<script type=\"text/javascript\">" << endl
		
		// Global variables
		<< "var map;" << endl
		<< "var marker;" << endl
		<< "marker = new google.maps.Marker();" << endl
		<< "var selected_path;" << endl
		<< "var colours = [\"00FF00\", \"0CF200\", \"19E500\", \"26D800\", \"32CC00\", \"3FBF00\", \"4CB200\", \"59A500\", \"669900\", \"728C00\", \"7F7F00\", \"8C7200\", \"996600\", \"A55900\", \"B24C00\", \"BF3F00\", \"CC3300\", \"D82600\", \"E51900\", \"F20C00\", \"FF0000\"];" << endl // colour table, from green to red in 20 steps
		<< "var ride_path = new Array();" << endl

		// Function initialise
		<< "function initialize() {" << endl
		<< "selected_path = new google.maps.Polyline({strokeColor: \"#000000\",strokeOpacity: 1.0, strokeWeight: 5, zIndex: 1});" << endl
		<< "map = new google.maps.Map(document.getElementById(\"map_canvas\"), {mapTypeId: google.maps.MapTypeId.ROADMAP});" << endl
		<< "var ride_coords = [" << defineCoords(0, _data_log->numPoints()) << "];" << endl // create a path from GPS coords
		<< "for (i=0;i<ride_coords.length-1;i++) {" << endl
		<< "path = [ride_coords[i], ride_coords[i+1]];" << endl
		<< "ride_path[i] = new google.maps.Polyline({path: path, strokeColor: \"#FF0000\", strokeOpacity: 1.0, strokeWeight: 3, zIndex: 2, map: map });" << endl
		<< "}" << endl
		<< "var bounds = new google.maps.LatLngBounds();" << endl
		<< "for (var i = 0, len = ride_coords.length; i < len; i++) {" << endl
		<< "bounds.extend (ride_coords[i]);" << endl
		<< "}" << endl
		<< "map.fitBounds(bounds);" << endl
		<< "}" << endl

		// Function setMarker
		<< "function setMarker(ltd,lgd) {" << endl
		<< "var lat_lng = new google.maps.LatLng(ltd ,lgd);" << endl
		<< "marker.setPosition(lat_lng);" << endl
		<< "marker.setMap(map);" << endl
		<< "}" << endl

		// Function deleteMarker
		<< "function deleteMarker() { " << endl
		<< "marker.setMap(null);" << endl
		<< "}" << endl

		// Function setSelectionPath
		<< "function setSelectionPath(coords) { " << endl
		<< "selected_path.setPath(coords);" << endl
		<< "selected_path.setMap(map);" << endl
		<< "}" << endl

		// Function deleteSelectionPath
		<< "function deleteSelectionPath() {" << endl
		<< "selected_path.setMap(null);" << endl
		<< "}" << endl

		// Function to stroke ride path (ie colour it) according to key vector (0 <= key[i] <= 1)
		<< "function strokeRidePath(key) {" << endl
		<< "if (key.length == ride_path.length) {" << endl
		<< "for (i=0; i<ride_path.length-1; i++) {" << endl
		<< "ride_path[i].setOptions({strokeColor: colourFromFraction(key[i])});" << endl
		<< "}" << endl
		<< "}" << endl
		<< "}" << endl

		// Function to convert num to hex (0 <= frac <= 1.0)
		<< "function colourFromFraction(frac) {" << endl
		<< "index = frac*colours.length" << endl
		<< "if (Math.round(index) == colours.length)" << endl
		<< "return colours[colours.length-1];" << endl
		<< "else" << endl
		<< "return colours[Math.round(index)];" << endl
		<< "}" << endl

		// Function to convert num to hex
		<< "function decimalToHex(d, padding) {" << endl
		<< "var hex = Number(d).toString(16);" << endl
		<< "padding = typeof (padding) === \"undefined\" || padding === null ? padding = 2 : padding;" << endl
		<< "while (hex.length < padding) {" << endl
		<< "hex = \"0\" + hex;" << endl
		<< "}" << endl
		<< "return hex;" << endl
		<< "}" << endl
		
		<< "</script>" << endl
		<< "</head>" << endl
		<< "<body onload=\"initialize()\">" << endl
		<< "<div id=\"map_canvas\" style=\"width:100%; height:100%\"></div>" << endl
		<< "</body>" << endl
		<< "</html>" << endl;

	page << oss.str();
}


