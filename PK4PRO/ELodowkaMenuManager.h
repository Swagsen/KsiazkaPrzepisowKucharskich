#pragma once
#include<string>
#include"ELodowka.h"
#include"Recipe.h"
#include<vector>


class ELodowkaMenuManager
{
private:
	static enum State
	{
		menu,
		wyswietlSkladniki,
		szukajPrzepisow,
		dodajSkladnik,
		usunSkladnik,
		wyjdz,
	};

	const int StateCount = 5;
	static std::string StateToString[];

	int choice;

	ELodowka elodowka;

	std::vector<Recipe> recipeList;

public:

	ELodowkaMenuManager(std::vector<Recipe> _recipeList);
	~ELodowkaMenuManager();

	void PrintMenu();

	void GetUserInput();

	bool Update();

	void PrintAllIngredients();

	void SearchRecipes();

	void AddIngrediente();

	void DeleteIngredient();

};

