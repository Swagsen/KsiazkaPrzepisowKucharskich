#include "MenuManager.h"
#include<iostream>
#include"MyException.h"
#include"Validator.h"
#include<algorithm>

std::string input()
{
	std::string tmp;
	std::getline(std::cin, tmp);
	return tmp;
}

MenuManager::MenuManager()
{
	try
	{
		recipeManager.recipeList = fileManager.LoadAllRecipes();
	}
	catch (NoFileI e)
	{
		std::cout << e.what();
		system("PAUSE");
		exit(-1);
	}
}


MenuManager::~MenuManager()
{
}

void MenuManager::PrintMenu()
{
	for (int i = 1; i <= StateCount; i++)
	{
		std::cout << i << " - " << StateToString[i] << std::endl;
	}
}

void MenuManager::GetUserInput()
{
	std::string tmp;
	while (!Validator::CheckMenuChoice(tmp = input()))
	{
		std::cout << "zle :c, podaj jeszcze raz: ";
	}
	choice = std::stoi(tmp);
}

bool MenuManager::Update()
{
	system("CLS");
	PrintMenu();
	GetUserInput();

	switch (choice)
	{
	case wyswietlNazwyPrzepisow:
		system("cls");
		PrintAllRecipesNames();
		break;

	case wyswietlWszystkiePrzepisy:
		system("cls");
		PrintAllRecipes();
		break;

	case wyswietlPrzepis:
		system("cls");
		SearchByName();
		break;

	case dodaj:
		system("cls");
		AddRecipe();
		try
		{
			fileManager.SaveAllRecipes(recipeManager.recipeList);
		}
		catch (NoFileO e)
		{
			std::cout << e.what();
			system("PAUSE");
			exit(-1);
		}
		break;

	case usun:
		system("cls");
		DeleteRecipe();
		try
		{
			fileManager.SaveAllRecipes(recipeManager.recipeList);
		}
		catch (NoFileO e)
		{
			std::cout << e.what();
			system("PAUSE");
			exit(-1);
		}
		break;

	case szukaj:
		system("cls");
		SearchByCategory();
		break;

	case elodowka:
		system("cls");
		Elodowka_();
		break;

	case wyjdz:
		try
		{
			fileManager.SaveAllRecipes(recipeManager.recipeList);
		}
		catch (NoFileO e)
		{
			std::cout << e.what();
			system("PAUSE");
			exit(-1);
		}
		return false;
		break;
	}
	return true;
}

void MenuManager::PrintAllRecipesNames()
{
	recipeManager.PrintAllByNames();

	system("pause");
}

void MenuManager::PrintAllRecipes()
{
	recipeManager.PrintAll();

	system("pause");
}

void MenuManager::SearchByName()
{
	std::string nazwa;

	std::cout << "Podaj nazwe Przepisu: \n";
	while (!Validator::CheckName(nazwa = input())) { std::cout << "zle :c, podaj jeszcze raz: "; };

	try
	{
		std::cout << recipeManager.SearchByName(nazwa);
	}
	catch (NoRecipe& e)
	{
		std::cout << e.what();
	}

	system("pause");
}

void MenuManager::SearchByCategory()
{
	std::vector<Recipe> tmp = recipeManager.recipeList;
	std::string tmpString;

	std::cout << "napisz brak jesli jakies kryterium cie nieinteresuje\n";

	std::cout << "Podaj max czas Przygotowania: ";
	while (!Validator::CheckNumberF(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetCzasPrzygotowania() > std::stof(tmpString); }), tmp.end());

	std::cout << "Podaj min ocena: ";
	while (!Validator::CheckRating(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetOcena() < std::stoi(tmpString); }), tmp.end());

	std::cout << "Podaj max ocena: ";
	while (!Validator::CheckRating(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetOcena() > std::stoi(tmpString); }), tmp.end());

	std::cout << "Podaj min koszt: ";
	while (!Validator::CheckNumberF(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetKoszt() < std::stof(tmpString); }), tmp.end());

	std::cout << "Podaj max koszt: ";
	while (!Validator::CheckNumberF(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetKoszt() > std::stof(tmpString); }), tmp.end());

	std::cout << "Podaj kategoria: ";
	while (!Validator::CheckWord(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetKategoria() != tmpString; }), tmp.end());

	std::cout << "Podaj typ dania: ";
	while (!Validator::CheckWord(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetTypDania() != tmpString; }), tmp.end());

	std::cout << "Podaj Kuchnie: ";
	while (!Validator::CheckWord(tmpString = input()) && !Validator::CheckBrak(tmpString)) { std::cout << "zle :c, podaj jeszcze raz: "; }

	if (tmpString != "brak")
		tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [tmpString](Recipe recipe) {return recipe.GetKuchnia() != tmpString; }), tmp.end());

	if (tmp.empty())
	{
		std::cout << "\nbrak przepisow o spelniajacych kryteriach\n";
	}
	else
	{
		std::cout << "\nOto pasujace przepisy:\n";
		for (auto it : tmp) { std::cout << it.GetNazwa() << std::endl; }
	}

	system("pause");
}

void MenuManager::AddRecipe()
{
	std::string nazwa;
	float czasPrzygotowania;
	int ocena;
	float koszt;
	std::string kategoria;
	std::string typDania;
	std::string kuchnia;
	int iloscSkladnikow;
	std::string opis;
	std::string sposobPrzygotowania;
	float ilosc;
	float cena;
	std::string jednostka;


	std::string tmp;

	std::cout << "Podaj nazwe Przepisu: ";
	while (!Validator::CheckName(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } nazwa = tmp;
	std::cout << "Podaj czas przygotowania (min): ";
	while (!Validator::CheckNumberF(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } czasPrzygotowania = std::stof(tmp);
	std::cout << "Podaj ocene: ";
	while (!Validator::CheckRating(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } ocena = std::stoi(tmp);
	std::cout << "Podaj koszt: ";
	while (!Validator::CheckCost(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } koszt = std::stof(tmp);
	std::cout << "Podaj kategorie: ";
	while (!Validator::CheckWord(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } kategoria = tmp;
	std::cout << "Podaj typ dania: ";
	while (!Validator::CheckWord(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } typDania = tmp;
	std::cout << "Podaj Kuchnie: ";
	while (!Validator::CheckWord(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } kuchnia = tmp;
	std::cout << "Podaj ilosc skladnikow: ";
	while (!Validator::CheckIngredientCount(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } iloscSkladnikow = std::stoi(tmp);
	std::cout << "Podaj opis: ";
	while (!Validator::CheckDescription(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } opis = tmp;
	std::cout << "Podaj sposob przygotowania: ";
	while (!Validator::CheckDescription(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } sposobPrzygotowania = tmp;

	Recipe recipe(nazwa, czasPrzygotowania, ocena, iloscSkladnikow, koszt, kategoria, typDania,
		kuchnia, opis, sposobPrzygotowania);


	for (int i = 0; i < iloscSkladnikow; i++)
	{
		std::cout << "Podaj nazwe " << i + 1 << " skladnika: ";
		while (!Validator::CheckName(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } nazwa = tmp;
		std::cout << "Podaj ilosc:";
		while (!Validator::CheckNumberF(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } ilosc = std::stof(tmp);
		std::cout << "Podaj cene: ";
		while (!Validator::CheckNumberF(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } cena = std::stof(tmp);
		std::cout << "Podaj jednostke(kg/ml/szt/g): ";
		while (!Validator::CheckUnit(tmp = input())) { std::cout << "zle :c, podaj jeszcze raz: "; } jednostka = tmp;

		recipe.AddIngredient(Ingredient(nazwa, ilosc, cena, jednostka));
	}

	recipeManager.AddRecipe(recipe);

	std::cout << "Przepis pomyslnie dodano!\n";
	system("pause");
}

void MenuManager::DeleteRecipe()
{
	std::string nazwa;

	std::cout << "Podaj nazwe Przepisu do usuniecia: ";

	while (!Validator::CheckName(nazwa = input())) { std::cout << "zle :c, podaj jeszcze raz: "; }

	try
	{
		recipeManager.DeleteRecipe(recipeManager.SearchByName(nazwa));
	}
	catch (NoRecipe& e)
	{
		std::cout << e.what();
	}

	std::cout << "Przepis pomyslnie usunieto!\n";
	system("pause");
}

void MenuManager::Elodowka_()
{
	eLodowkaManager = new ELodowkaMenuManager(recipeManager.recipeList);

	while (eLodowkaManager->Update()){}
}

std::string MenuManager::StateToString[] =
{
	"Menu",
	"Wyswietl Nazwy Przepisow",
	"Wyswietl Wszystkie Przepisy",
	"Wyswietl Przepis",
	"Dodaj",
	"Usun",
	"Szukaj",
	"Elodowka",
	"Wyjdz",
};

