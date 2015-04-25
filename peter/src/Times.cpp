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

}

