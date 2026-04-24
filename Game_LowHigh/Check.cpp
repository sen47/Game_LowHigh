#include "Check.h"

bool checkRange(const std::int32_t answer, const std::int32_t min, const std::int32_t max)
{
	return (answer >= min && answer <= max);
}

int getIntAnswerInRange(const std::string& output, const std::int32_t min, const std::int32_t max)
{
	while (true)
	{
		std::cout << output;
		std::int32_t input;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << errors[error::INVALID_VALUE] << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if (checkRange(input, min, max))
				return input;
			else
			{
				std::cout << errors[error::INVALID_VALUE] << '\n';
			}
		}
	}
}

char getCharAnswerInRange(const std::string& output, const char range[], const std::int16_t size)
{
	while (true)
	{
		std::cout << output;
		char input;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << error::INVALID_VALUE << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n');
			for (int i = 0; i < size; ++i)
				if (range[i] == input)
					return input;

			std::cout << errors[error::INVALID_VALUE] << '\n';
		}
	}
}
