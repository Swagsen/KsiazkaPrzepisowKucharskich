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


class NoFileI : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Problem z otwarciem pliku \n";
	}
};

class NoFileO : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Problem z zapisem pliku \n";
	}
};
