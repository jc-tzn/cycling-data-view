#ifndef DATALOG_H
#define DATALOG_H

#include <qstring.h>
#include <qmap.h>
#include <vector>

class DataLog
 {
 public:
	DataLog();
	~DataLog();

	void resize(int size);

	QString& name() { return _name; };
	QString& date() { return _date; };
	double& totalTime() { return _total_time; };
	double& totalDist() { return _total_dist; };
	double& maxSpeed() { return _max_speed; };
	double& maxHeartRate() { return _max_heart_rate; };
	double& maxGradient() { return _max_gradient; };
	double& maxCadence() { return _max_cadence; };
	double& maxPower() { return _max_power; };
	double& avgSpeed() { return _avg_speed; };
	double& avgHeartRate() { return _avg_heart_rate; };
	double& avgGradient() { return _avg_gradient; };
	double& avgCadence() { return _avg_cadence; };
	double& avgPower() { return _avg_power; };
	int& numPoints() { return _num_points; };

	double& time(int idx);
	double& ltd(int idx);
	double& lgd(int idx);
	double& alt(int idx);
	double& dist(int idx);
	double& heartRate(int idx);
	double& cadence(int idx);
	double& speed(int idx);
	double& gradient(int idx);
	double& power(int idx);
	double& altMap(int idx);
	double& altSmooth(int idx);

	std::vector<double>& time() { return _time; }
	std::vector<double>& ltd() { return _ltd; }
	std::vector<double>& lgd() { return _lgd; }
	std::vector<double>& alt() { return _alt; }
	std::vector<double>& dist() { return _dist; }
	std::vector<double>& heartRate() { return _heart_rate; }
	std::vector<double>& cadence() { return _cadence; }
	std::vector<double>& speed() { return _speed; }
	std::vector<double>& gradient() { return _gradient; }
	std::vector<double>& power() { return _power; }
	std::vector<double>& altMap() { return _alt_map; }
	std::vector<double>& altSmooth() { return _alt_smooth; }

	// Compute mappings from time to index and dist to index
	void computeMaps();
	// Return the index at the specified time
	int indexFromTime(double time);
	// Return the index at the specified distance
	int indexFromDist(double dist);

 private:

	// Summary data
	QString _name;
	QString _date;
	double _total_time;
	double _total_dist;
	double _max_speed;
	double _max_heart_rate;
	double _max_gradient;
	double _max_cadence;
	double _max_power;
	double _avg_speed;
	double _avg_heart_rate;
	double _avg_gradient;
	double _avg_cadence;
	double _avg_power;
	int _num_points;

	// The vectors of data
	std::vector<double> _time; //sec
	std::vector<double> _ltd; //deg
	std::vector<double> _lgd; //deg
	std::vector<double> _alt; //m
	std::vector<double> _dist; //m
	std::vector<double> _heart_rate; //bpm
	std::vector<double> _cadence; //rpm
	std::vector<double> _speed; //kmh
	std::vector<double> _gradient; //%
	std::vector<double> _power; //W
	std::vector<double> _alt_map; //m
	std::vector<double> _alt_smooth; //m

	QMap<double,int> _time_to_index;
	QMap<double,int> _dist_to_index;
 };

#endif // DATALOG_H