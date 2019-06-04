#pragma once
#include<exception>

class NoRecipe : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Nie Znaleziono Przepisu \n";
	}
};

