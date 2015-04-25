#include <Scramble.hpp>

#include <algorithm>
#include <array>
#include <random>
#include <ctime>

namespace ct
{

std::mt19937 mt(std::time(0));

std::string generateScramble()
{
	const std::array<std::string, 18> MOVES = {
		"F", "F\'", "F2",
		"B", "B\'", "B2",
		"L", "L\'", "L2",
		"R", "R\'", "R2",
		"U", "U\'", "U2",
		"D", "D\'", "D2"
	};

	const int SCRAMBLE_LENGTH = 30;
	std::string scramble;

	std::uniform_int_distribution<int> dist(0, MOVES.size() - 1);

	int lastRandIndex = -1;
	for (int i = 0; i < SCRAMBLE_LENGTH; i++)
	{
		int randIndex = dist(mt);
		if ((lastRandIndex % 3 == 0 && (randIndex - 1) % 3 == 0)
		 || (randIndex % 3 == 0 && (lastRandIndex - 1) % 3 == 0))
		{
			i--;
			continue;
		}

		lastRandIndex = randIndex;
		scramble += MOVES[randIndex] + ' ';
	}

	return scramble;
}

}