#ifndef TIMES_HPP
#define TIMES_HPP

#include <string>
#include <vector>

namespace ct
{

class Times
{
public:
	Times();
	~Times();	
	void log(float seconds);

	float getAverageOf(unsigned int n) const;
	float getBestSingle() const;
	float getWorstSingle() const;
	float getStdDevSession() const;
private:
	std::vector<float> historical;
	std::vector<float> session;

	const std::string filename = "saved-times.txt";

	//TODO function that parses the seconds and converts into HH:MM:SS format?
	
};

}

#endif