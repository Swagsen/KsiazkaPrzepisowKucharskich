#include "Validator.h"
#include <regex>

bool Validator::CheckName(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[a-zA-Z\\s]+"));
}

bool Validator::CheckRating(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[1-5]{1}"));
}

bool Validator::CheckCost(std::string tmp)
{
	return std::regex_match(tmp, std::regex("([0-9]+).([0-9]{1,2})|[0-9]+"));
}

bool Validator::CheckWord(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[a-zA-Z]+"));
}

bool Validator::CheckDescription(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[a-zA-Z\\s,.]+"));
}

bool Validator::CheckIngredientCount(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[1-9]{1,3}"));
}

bool Validator::CheckNumberF(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[0-9]{1,5}[.][0-9]{1,8}|[1-9]{1,5}"));
}

bool Validator::CheckUnit(std::string tmp)
{
	return std::regex_match(tmp, std::regex("([kK][Gg])|([mM][Ll])|([Ss][Zz][Tt])|([Gg])"));
	//return std::regex_match(tmp, std::regex("[kK][Gg]"));
}

bool Validator::CheckMenuChoice(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[1-8]{1}"));
}

bool Validator::CheckBrak(std::string tmp)
{
	return std::regex_match(tmp, std::regex("brak"));
}

bool Validator::CheckMenuElodowkaChoice(std::string tmp)
{
	return std::regex_match(tmp, std::regex("[1-5]{1}"));
}
