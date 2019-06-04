#pragma once
#include<string>

static class Validator
{
public:
	static bool CheckMenuChoice(std::string tmp);
	static bool CheckName(std::string tmp);
	static bool CheckRating(std::string tmp);
	static bool CheckCost(std::string tmp);
	static bool CheckWord(std::string tmp);
	static bool CheckIngredientCount(std::string tmp);
	static bool CheckNumberF(std::string tmp);
	static bool CheckUnit(std::string tmp);
	static bool CheckDescription(std::string tmp);
	static bool CheckBrak(std::string tmp);
	static bool CheckMenuElodowkaChoice(std::string tmp);
};

