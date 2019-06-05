#include "Ingredient.h"
#include<iostream>

Ingredient::Ingredient(std::string _nazwa, float _ilosc, float _cena, std::string _jednostka): 
	nazwa(_nazwa), ilosc(_ilosc), cena(_cena), jednostka(_jednostka)
{
}

Ingredient::~Ingredient()
{
}

bool Ingredient::operator>=(const Ingredient & ingredient)
{
	if (nazwa != ingredient.nazwa)
		return false;

	if (ilosc < ingredient.ilosc)
		return false;

	if (jednostka != ingredient.jednostka)
		return false;

	return true;
}

std::ostream& operator<<(std::ostream& stream, Ingredient igredient)
{
	stream <<  "    Nazwa: " << igredient.nazwa << std::endl;
	stream <<  "    Ilosc: " << igredient.ilosc << igredient.jednostka << std::endl;
	stream <<  "    Cena:  " << igredient.cena << "zl\n\n";
	
	return stream;
}
