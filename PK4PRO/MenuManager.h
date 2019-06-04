#pragma once
#include<string>
#include"RecipeManager.h"
#include"FileManager.h"
#include"ELodowkaMenuManager.h"

class MenuManager
{
private:
	static enum State
	{
		menu,
		wyswietlNazwyPrzepisow,
		wyswietlWszystkiePrzepisy,
		wyswietlPrzepis,
		dodaj,
		usun,
		szukaj,
		elodowka,
		wyjdz,
	};

	const int StateCount = 8;
	static std::string StateToString[];

	int choice;

	RecipeManager recipeManager;
	FileManager fileManager;
	ELodowkaMenuManager *eLodowkaManager;


public:
	MenuManager();
	~MenuManager();

	void PrintMenu();

	void GetUserInput();

	bool Update();
	   	 
	   	 

	void PrintAllRecipesNames();

	void PrintAllRecipes();

	void SearchByName();

	void SearchByCategory();

	void AddRecipe();

	void DeleteRecipe();

	void Elodowka_();

};


