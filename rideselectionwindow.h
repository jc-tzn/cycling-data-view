#ifndef RIDESELECTIONWINDOW_H
#define RIDESELECTIONWINDOW_H

#include <QWidget.h>

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

class QTreeView;
class QStandardItemModel;
class QModelIndex;
class QLabel;
class TcxParser;
class FitParser;
class DataLog;
class User;
class LogDirectorySummary;

class RideSelectionWindow : public QWidget
 {
	 Q_OBJECT
 public:
	RideSelectionWindow();
	~RideSelectionWindow();

	void setUser(boost::shared_ptr<User> user);
	void refresh();
	boost::shared_ptr<DataLog> currentDataLog();

 signals:
	void displayRide(boost::shared_ptr<DataLog> data_log);
	void displayLap(int lap_index);

private slots:
	void rideSelected(const QModelIndex& index);

 private:
	void populateTableWithRides();
	void formatTreeView();
	bool parse(const QString filename, boost::shared_ptr<DataLog> data_log);

	QTreeView* _tree;
	QStandardItemModel* _model;
	QLabel* _head_label;
	
	TcxParser* _tcx_parser;
	FitParser* _fit_parser;

	boost::shared_ptr<DataLog> _current_data_log;
	boost::scoped_ptr<LogDirectorySummary> _log_dir_summary;
 };

#endif // RIDESELECTIONWINDOW_H