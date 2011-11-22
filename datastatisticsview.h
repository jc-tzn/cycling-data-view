#ifndef DATASTATISTICSVIEW_H
#define DATASTATISTICSVIEW_H

#include <qtgui/qwidget>

class QTableWidget;
class QLabel;
class DataLog;
class User;

class DataStatisticsView : public QWidget
 {
	 Q_OBJECT
 public:
	DataStatisticsView();
	~DataStatisticsView();

	void displayRide(DataLog* data_log, User* user);

 public slots:
	void displayCompleteRideStats();
	void displaySelectedRideStats(int idx_start, int idx_end);
	void deleteSelection();
	
 private:
	void clearTable();
	void clearTotalsColumn();
	void clearSelectionColumn();

	QTableWidget* _table;
	QLabel* _head_label;
	DataLog* _data_log;
	User* _user;
 };

#endif // DATASTATISTICSVIEW_H