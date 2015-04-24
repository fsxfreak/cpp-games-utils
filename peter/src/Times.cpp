#include <Times.hpp>
#include <fstream>

namespace ct
{

Times::Times()
{

}

Times::~Times()
{

}

void Times::log(float seconds)
{
	session.push_back(seconds);
}

sf

float Times::getAverageOf(int n)
{
	int numHistorical = n - session.size();

	std::vector<float> copy(n);
	//take last numHistorical elements off of history
	//fill rest with sesion

	copy.erase(std::max_element(copy.begin(), copy.end()));
	copy.erase(std::min_element(copy.begin(), copy.end()));

	float sum;
	for (auto &e : copy)
		sum += e;

	return e / copy.size();
}

}

