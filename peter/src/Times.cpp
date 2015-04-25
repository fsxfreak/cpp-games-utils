#include <Times.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>

namespace ct
{

Times::Times()
{
	historical.push_back(2.21f);
	historical.push_back(2.23f);
}

Times::~Times()
{

}

void Times::log(float seconds)
{
	session.push_back(seconds);
}

float Times::getAverageOf(unsigned int n)
{
	int numHistorical = n - session.size();

	std::vector<float> copy;

	if (historical.size() > 0)
		std::copy (historical.end() - numHistorical, historical.end()
				 , std::back_inserter(copy));
	if (session.size() > 0)
		std::copy (session.size() >= n + numHistorical
				    ? session.end() - n + numHistorical
				    : session.begin()
			     , session.end()
			     , std::back_inserter(copy));

	for (unsigned int i = 0; i < copy.size(); i++)
	{
		std::cout << copy[i] << ", ";
	}
	std::cout << std::endl;

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

