#include<iostream>
#include<cstdint>
#include<random>
#include<string>

#include "Check.h"

enum game
{
	make_number = 1, solve_number
};

enum level
{
	eazy = 1, medium, hard
};

std::int32_t getNumberInRange(const std::int32_t min, const std::int32_t max);
void solveNumber();

int main()
{
	std::int16_t answerMenu{};
	char answerExit{};
	char answerRange[2]{ 'y','n' };

	while (true)
	{
		answerMenu = getIntAnswerInRange("Do you want to make(1) or solve(2) number: ", 1, 2);
		
		switch (answerMenu)
		{
		case game::make_number:
			std::cout << "Make number\n";
			break;
		case game::solve_number:
		{
			solveNumber();
			break;
		}
		default:
			std::cout << error::DEFAULT_BLOCK << '\n';
		}

		answerExit = getCharAnswerInRange("Do you vant to play again (y/n)?: ", answerRange, sizeof(answerRange) / sizeof(answerRange[0]));
		if (answerExit == 'n')
			break;
	}

	std::cout << "Thanks for playing, good bye!\n";

	return 0;
}

std::int32_t getNumberInRange(const std::int32_t min, const std::int32_t max)
{
	std::random_device rd;
	std::mt19937 mers(rd());

	return mers() % (max - min + 1) + min;
}

void solveNumber()
{
	std::int16_t answerLevel{}, tryes{};

	answerLevel = getIntAnswerInRange("Chose level easy(1), medium(2), hard(3): ", 1, 3);
	std::int32_t numberMin{ 1 }, numberMax(100);

	switch (answerLevel)
	{
	case level::eazy:
		tryes = 9;
		break;
	case level::medium:
		tryes = 7;
		break;
	case level::hard:
		tryes = 5;
		break;
	default:
		tryes = 0;
	}

	std::int32_t guessNumber{ getNumberInRange(numberMin,numberMax) }, answerNumber{};
	std::cout << guessNumber << '\n';

	do
	{
		answerNumber = getIntAnswerInRange("You have " + std::to_string(tryes) + " to guess number: ", numberMin, numberMax);
		if (guessNumber == answerNumber)
			break;
		
		std::cout << "Your guess is too " << ((answerNumber > guessNumber) ? "high" : "low") << '\n';
		--tryes;
	} while (tryes > 0);

	if (tryes)
		std::cout << "Congratulations, you win!\n";
	else
		std::cout << "Sorry, you loose, the correct number is " << guessNumber << '\n';
}