#include<iostream>
#include<cstdint>
#include<random>
#include<string>

#include "Check.h"

enum game
{
	make_number = 1, solve_number
};

std::int32_t getNumberInRange(const std::int32_t min, const std::int32_t max);

int main()
{
	std::int32_t menuAnswer{};
	
	while (true)
	{
		menuAnswer = getIntAnswerInRange("Do you want to make(1) or solve(2) number: ", 1, 2);
		
		switch (menuAnswer)
		{
		case game::make_number:
			std::cout << "Make number\n";
			break;
		case game::solve_number:
			std::cout << "Solve number\n";
			break;
		default:
			std::cout << error::DEFAULT_BLOCK << '\n';
		}
	}

	return 0;
}

std::int32_t getNumberInRange(const std::int32_t min, const std::int32_t max)
{
	std::random_device rd;
	std::mt19937 mers(rd());

	return mers() % (max - min + 1) + min;
}