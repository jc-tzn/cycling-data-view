#ifndef GOOGLEMAP_H
#define GOOGLEMAP_H

#include "datalog.h"

#include <qtxml/qdomdocument>
#include <qtcore/qobject>
#include <qtcore/qpoint>
#include <QWebView.h>
#include <qmap.h>

//class DataLog;

class GoogleMap : public QObject
{
	Q_OBJECT

 public:
	GoogleMap();
	~GoogleMap();

	// Display the ride route on a google map
	void displayRide(DataLog* data_log);

private slots:
	// Set marker in google map
	void setMarkerPosition(int idx);
	// Call when user begins to highlight a seletection (to highlight path on the map)
	void beginSelection(int idx_begin);
	// Call when a user has complted highlighting a selection (to highlight path on the map)
	void endSelection(int idx_end);
	// Call when a user defines a selection to zoom (to highlight path on the map)
	void zoomSelection(int idx_start, int idx_end);
	// Call when a user moves the selected region (to highlight path on the map)
	void moveSelection(int delta_idx);
	// Call when a user completes moving the selected region (to highlight path on the map)
	void moveAndHoldSelection(int delta_idx);
	// Stroke the ride path according to user selected parameter
	void definePathColour();

 private:
	void createPage(std::ostringstream& page);
	// Create sting decription of lat/long between first and last iterators
	std::string defineCoords(int idx_start, int idx_end);
	// Draw the path between the start and end time on the map
	void setSelection(int idx_start, int idx_end);

	// The window to display google maps
	QWebView *_view;
	// Map to define association between time and lat/long
	QMap<double, std::pair<double, double> > _time_v_ltd_lgd;
	// The start index of selection to highlight
	int _selection_begin_idx;
	// The end index of selection to highlight
	int _selection_end_idx;
	// Pointer to the data log
	DataLog* _data_log;
};

#endif // GOOGLEMAP_H