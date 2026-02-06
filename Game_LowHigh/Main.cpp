#include<iostream>
#include<cstdint>
#include<random>

std::int32_t getNumberInRange(const std::int32_t min, const std::int32_t max)
{
	std::random_device rd;
	std::mt19937 mers(rd());

	return mers() % (max - min + 1) + min;
}

bool checkIntAnswer(const std::int16_t answer, const std::int16_t min, const std::int16_t max)
{
	return (answer >= min && answer <= max);
}

int main()
{
	std::int16_t answer{};
	do
	{
		std::cout << "Do you want to make(1) or solve(2) number: ";
		std::cin >> answer;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Error, invalid try again!\n";
		}
	} while (checkIntAnswer(answer, 1, 2));


	return 0;
}