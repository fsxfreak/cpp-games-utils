#include <Times.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>

namespace ct
{

Times::Times()
{
	historical.push_back(2.21223f);
	historical.push_back(2.232323f);
}

Times::~Times()
{

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

	float sum;
	for (auto &e : copy)
		sum += e;
	return copy.size() != 0 ? sum / copy.size() : 0;
}

}

