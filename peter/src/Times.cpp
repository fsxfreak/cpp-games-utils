#include <cfloat>
#include <Times.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

namespace ct
{

Times::Times()
{
	std::ifstream savedTimes(filename, std::ifstream::in);
	std::string allSavedTimes;
	std::getline(savedTimes, allSavedTimes);

	float element;
	std::stringstream ss(allSavedTimes);
	while (ss >> element)
	{
		historical.push_back(element);
		if (ss.peek() == ',') ss.ignore();
	}
	savedTimes.close();
}

Times::~Times()
{
	std::ofstream savedTimes(filename, std::ofstream::out | std::ofstream::app);
	for (auto &e : session)
		savedTimes << e << ',';
	savedTimes.close();
}

void Times::log(float seconds) { session.push_back(seconds); }

float Times::getAverageOf(unsigned int n)
{
	//let this mark the first time that I got fucked by unsigned
	unsigned int nHistorical = session.size() < n ? n - session.size() : 0;

	if ((historical.size() < nHistorical)
	 || (historical.size() + session.size() < n))
		return 0;

	std::vector<float> copy;

	std::copy (historical.end() - nHistorical, historical.end()
			 , std::back_inserter(copy));
	std::copy (session.end() - n + nHistorical
			 , session.end()
			 , std::back_inserter(copy));

	if (copy.size() > 2)
	{
		copy.erase(std::max_element(copy.begin(), copy.end()));
		copy.erase(std::min_element(copy.begin(), copy.end()));
	}

	float sum = 0;
	for (auto &e : copy)
		sum += e;
	return copy.size() != 0 ? sum / copy.size() : 0;
}

float Times::getBestSingle() 
{
	float bestHistorical = *std::min_element(historical.begin(), historical.end());
	auto sess = std::min_element(session.begin(), session.end());
	float bestSession = FLT_MAX;
	if (sess != session.end())
		bestSession = *sess;
	return bestHistorical < bestSession ? bestHistorical : bestSession;
}

float Times::getWorstSingle() 
{
	float worstHistorical = *std::max_element(historical.begin(), historical.end());
	auto sess = std::max_element(session.begin(), session.end());
	float worstSession = FLT_MIN;
	if (sess != session.end())
		worstSession = *sess;
	return worstHistorical > worstSession ? worstHistorical : worstSession;
}

float Times::getStdDevSession()
{
	if (session.size() == 0)
		return 0;

	float mean = 0;
	for (auto &e : session) mean += e;
	mean /= session.size();

	float stddev = 0;
	for (auto &e : session)
	{
		stddev += (e - mean) * (e - mean);
	}
	stddev /= session.size();

	return stddev;
}

}

