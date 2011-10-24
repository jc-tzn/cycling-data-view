#include "dataprocessing.h"
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>

/****************************************/
void DataProcessing::computePower()
{

}

/****************************************/
void DataProcessing::lowPassFilterSignal(
	const std::vector<double>& signal,
	std::vector<double>& filtered,
	int window_size)
{
	assert(signal.size() > 1);

	filtered.resize(signal.size());
	if (window_size > 2)
	{
		// Smooth altitude with averaging filter
		std::vector<double>::const_iterator signal_it = signal.begin();
		for (int i=0; i < (int)signal.size(); ++i)
		{
			int x = i - std::max(0, i - window_size/2);
			int y = std::min((int)signal.size(), i + window_size/2) - i;
			filtered[i] = std::accumulate(signal_it+i-x, signal_it+i+y,0.0)/double(x + y);	
		}
	}
	else
	{
		std::copy(signal.begin(),signal.end(), filtered.begin());
	}
}

/****************************************/
void DataProcessing::computeGradient(
	const std::vector<double>& alt,
	const std::vector<double>& dist,
	std::vector<double>& grad)
{
	assert(alt.size() == dist.size());
	assert(alt.size() > 1);

	// Compute gradient from altitude
	grad.resize(alt.size());
	for (unsigned int i=1; i < alt.size(); ++i)
	{
		if (dist[i] - dist[i-1] > 5)
			grad[i] = 100*(alt[i] - alt[i-1])/(dist[i] - dist[i-1]);
	}
}

/****************************************/
void DataProcessing::computeSpeed(
	const std::vector<double>& time,
	const std::vector<double>& dist,
	std::vector<double>& speed)
{
	assert(time.size() == dist.size());
	assert(time.size() > 2);

	// Compute speed from distance over time
	speed.resize(time.size());
	for (unsigned int i=2; i < time.size(); ++i)
	{
		if (time[i] - time[i-2] > 0)
			speed[i] = 3.6*(dist[i] - dist[i-2])/(time[i] - time[i-2]);
	}
}

/****************************************/
double DataProcessing::computeAverage(
	std::vector<double>::const_iterator& start,
	std::vector<double>::const_iterator& end)
{
	double avg = 0;
	if (end-start > 0)
		avg = std::accumulate(start, end,0.0)/double(end-start);
	return avg;
}

/****************************************/
double DataProcessing::computeNthPercentile(
		std::vector<double>::const_iterator& start,
		std::vector<double>::const_iterator& end,
		double N)
{
	assert(N > 0.0 && N < 1.0);

	double nth_percentile = 0.0;
	if (end-start > 0)
	{
		std::vector<double> sorted(end-start);
		std::copy(start, end, sorted.begin());
		std::sort(sorted.begin(), sorted.end());
		nth_percentile = *(sorted.begin() + (int)(N*(double)sorted.size()) );
	}
	return nth_percentile;
}
/****************************************/
double DataProcessing::computeMax(
	std::vector<double>::const_iterator& start,
	std::vector<double>::const_iterator& end)
{
	return *std::max_element(start, end);
}

/****************************************/
double DataProcessing::computeMin(
	std::vector<double>::const_iterator& start,
	std::vector<double>::const_iterator& end)
{
	return *std::min_element(start, end);
}

/****************************************/
double DataProcessing::computeGain(
	std::vector<double>::const_iterator& start,
	std::vector<double>::const_iterator& end)
{
	double gain = 0;
	for (std::vector<double>::const_iterator it=++start; it != end; ++it)
	{
		double val1 = *it;
		double val2 = *(it-1);
		if (val1 > val2)
			gain += val1 - val2;
	}
	return gain;
}

/****************************************/
double DataProcessing::computeLoss(
	std::vector<double>::const_iterator& start,
	std::vector<double>::const_iterator& end)
{
	double loss = 0;
	for (std::vector<double>::const_iterator it=++start; it != end; ++it)
	{
		double val1 = *it;
		double val2 = *(it-1);
		if (val1 < val2)
			loss += val2 - val1;
	}
	return loss;
}

/****************************************/
std::pair<int,int> DataProcessing::minutesFromSeconds(int seconds)
{
	std::pair<int,int> minutes(0,0);

	minutes.first = seconds/60;
	minutes.second = seconds%60;

	return minutes;
}

/****************************************/
double DataProcessing::kmFromMeters(double meters)
{
	return meters/1000.0;
}
