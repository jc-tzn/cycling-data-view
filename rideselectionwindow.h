#ifndef RIDESELECTIONWINDOW_H
#define RIDESELECTIONWINDOW_H

#include <QWidget.h>

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

	void setUser(User* user);
	void refresh();
	DataLog* currentDataLog();

 signals:
	void displayRide(DataLog* data_log);
	void displayLap(int lap_index);

private slots:
	void rideSelected(const QModelIndex& index);

 private:
	void populateTableWithRides();
	void formatTreeView();
	bool parse(const QString filename, DataLog* data_log);

	QTreeView* _tree;
	QStandardItemModel* _model;
	QLabel* _head_label;
	
	TcxParser* _tcx_parser;
	FitParser* _fit_parser;

	DataLog* _current_data_log;
	LogDirectorySummary* _log_dir_summary;
 };

#endif // RIDESELECTIONWINDOW_H