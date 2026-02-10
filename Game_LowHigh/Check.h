#pragma once

#include<cstdint>
#include<string>
#include<iostream>

enum error
{
	INVALID_VALUE, DEFAULT_BLOCK, MAX
};

const std::string errors[error::MAX]
{
	"Error, invalid value, try again!",
	"Error, default block!"
};

bool checkRange(const std::int32_t answer, const std::int32_t min, const std::int32_t max);

int getIntAnswerInRange(const std::string& output, const std::int32_t min, const std::int32_t max);

char getCharAnswerInRange(const std::string& output, const char range[], const std::int16_t size);