#ifndef TOTALSWINDOW_H
#define TOTALSWINDOW_H
 
#include <Qwidget.h>
#include <QMap.h>

#include <boost/shared_ptr.hpp>

class User;
class QwtPlotCurve;
class QwtPlot;
class QCheckBox;
class QComboBox;
class BarChartItem;
class DateSelectorWidget;

class TotalsWindow : public QWidget
{
	Q_OBJECT
public:
	TotalsWindow(boost::shared_ptr<User> user);
	~TotalsWindow();

private slots:
	void updatePlot();
	void recomputePlotData();

private:
	void computeHistogramData();
	void computeCurves();

	boost::shared_ptr<User> _user;

	BarChartItem* _hist_yearly_time;
	BarChartItem* _hist_yearly_dist;
	BarChartItem* _hist_weekly_time;
	BarChartItem* _hist_weekly_dist;
	BarChartItem* _hist_monthly_dist;
	BarChartItem* _hist_monthly_time;

	QwtPlot* _plot;

	QMap<int, double> _yearly_time; // year as int
	QMap<int, double> _yearly_dist; // year as int
	QMap<std::pair<int,int>, double> _monthly_time; // month as pair<year,month>
	QMap<std::pair<int,int>, double> _monthly_dist; // month as pair<year,month>
	QMap<std::pair<int,int>, double> _weekly_time; // week as pair<year, week num>
	QMap<std::pair<int,int>, double> _weekly_dist; // week as pair<year, week num>

	QCheckBox* _dist_cb;
	QCheckBox* _time_cb;
	QComboBox* _time_group_selector;

	DateSelectorWidget* _date_selector_widget;
};
 
#endif // TOTALSWINDOW_H