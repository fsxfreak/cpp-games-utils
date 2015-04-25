#ifndef TIMES_HPP
#define TIMES_HPP

#include <string>
#include <vector>

namespace ct
{

class Times
{
public:
	Times();	//TODO parse the saved times file into historical
	~Times();	//TOOD append session times to file
	void log(float seconds);

	float getAverageOf(unsigned int n);
	float getBestSingle();
	float getWorstSingle();
	float getStdDevSession();
private:
	std::vector<float> historical;
	std::vector<float> session;

	const std::string filename = "saved-times.txt";

	//TODO function that parses the seconds and converts into HH:MM:SS format?
	
};

}

#endif