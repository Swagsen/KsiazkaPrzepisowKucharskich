#pragma once
#include<string>
#include<vector>
#include"Ingredient.h"
#include<iostream>

class Recipe
{
private:
	std::string nazwa;
	float czasPrzygotowania;
	int ocena;
	float koszt;
	std::string kategoria;
	std::string typDania;
	std::string kuchnia;
	std::string opis;
	std::string sposobPrzygotowania;

	int iloscSkladnikow;
	std::vector<Ingredient> ingriedientList;

public:
	Recipe(std::string nazwa, float czasPrzygotowania, int ocena, int iloscSkladnikow, float koszt, std::string kategoria,
		std::string typDania, std::string kuchnia, std::string opis, std::string sposobPrzygotowania);

	Recipe();
	~Recipe();

	void DodajSkladnik(std::string _nazwa, float _ilosc, float _cena, std::string _jednostka);
	void DodajSkladnik(Ingredient ingredient);
	//void Wyswietl();
	//bool operator==(Recipe& recipe);

	//bool operator<(Recipe& const recipe)const
	//{
	//	return(this->nazwa < recipe.GetName());
	//}

	friend std::ostream& operator<<(std::ostream& stream, Recipe recipe);




	std::string GetNazwa() { return  nazwa; };
	float GetCzasPrzygotowania() { return czasPrzygotowania; }
	int GetOcena() { return ocena; }
	float GetKoszt() { return koszt; }
	std::string GetKategoria() { return kategoria; }
	std::string GetTypDania() { return typDania; }
	std::string GetKuchnia() { return kuchnia; }
	int GetIloscSkladnikow() { return iloscSkladnikow; }
	std::string GetOpis() { return opis; }
	std::string GetSposobPrzygotowania() { return sposobPrzygotowania; }
	std::vector<Ingredient> GetingriedientList() { return ingriedientList; };

};

