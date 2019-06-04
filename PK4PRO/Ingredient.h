#pragma once
#include<string>
#include<iostream>


class Ingredient
{
private:

	std::string nazwa;
	float ilosc;
	float cena;
	std::string jednostka;

public:
	Ingredient(std::string _nazwa, float _ilosc, float _cena, std::string _jednostka);
	~Ingredient();

	friend std::ostream& operator<<(std::ostream& stream, Ingredient igredient);

	bool operator>=(const Ingredient& ingredient);

	std::string GetNazwa() { return  nazwa; };
	float GetIlosc() { return ilosc; };
	float GetCena() { return cena; };
	std::string GetJednostka() { return jednostka; };
};

