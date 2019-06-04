#include "ELodowkaMenuManager.h"
#include "Validator.h"

std::string Iinput()
{
	std::string tmp;
	//std::cin >> tmp;
	std::getline(std::cin, tmp);
	return tmp;
}

ELodowkaMenuManager::ELodowkaMenuManager(std::vector<Recipe> _recipeList)
{
	recipeList = _recipeList;
}


ELodowkaMenuManager::~ELodowkaMenuManager()
{
}

void ELodowkaMenuManager::PrintMenu()
{
	for (int i = 1; i <= StateCount; i++)
	{
		std::cout << i << " - " << StateToString[i] << std::endl;
	}

}

void ELodowkaMenuManager::GetUserInput()
{
	//std::cin.sync();
	//std::cin.clear();
	//std::cin.ignore(INT_MAX, '\n');

	std::string tmp;
	while (!Validator::CheckMenuElodowkaChoice(tmp = Iinput()))
	{
		std::cout << "zle :c, podaj jeszcze raz: ";
	}
	choice = std::stoi(tmp);
}

bool ELodowkaMenuManager::Update()
{
	system("CLS");
	PrintMenu();
	GetUserInput();

	switch (choice)
	{
	case wyswietlSkladniki:
		system("cls");
		PrintAllIngredients();
		break;

	case szukajPrzepisow:
		system("cls");
		SearchRecipes();
		break;

	case dodajSkladnik:
		system("cls");
		AddIngrediente();
		//fileManager.ZapiszElodowke(ingriedientList);
		break;

	case usunSkladnik:
		system("cls");
		DeleteIngredient();
		//fileManager.ZapiszWszsytkiePrzepisy(ksiazkaPrzepisow);
		break;


	case wyjdz:
		//fileManager.ZapiszWszsytkiePrzepisy(ksiazkaPrzepisow);
		return false;
		break;
	}
	return true;
}

void ELodowkaMenuManager::PrintAllIngredients()
{
	elodowka.Display();

	system("pause");
}

void ELodowkaMenuManager::SearchRecipes()
{
	elodowka.SearchRecipes(recipeList);

	system("pause");
}

void ELodowkaMenuManager::AddIngrediente()
{
	std::string nazwa;
	float ilosc;
	float cena;
	std::string jednostka;


	std::string tmp;


	std::cout << "Podaj nazwe skladnika: ";
	while (!Validator::CheckName(tmp = Iinput())) { std::cout << "zle :c, podaj jeszcze raz: "; } nazwa = tmp;
	std::cout << "Podaj ilosc:";
	while (!Validator::CheckNumberF(tmp = Iinput())) { std::cout << "zle :c, podaj jeszcze raz: "; } ilosc = std::stof(tmp);
	std::cout << "Podaj cene: ";
	while (!Validator::CheckNumberF(tmp = Iinput())) { std::cout << "zle :c, podaj jeszcze raz: "; } cena = std::stof(tmp);
	std::cout << "Podaj jednostke(kg/ml/szt/g): ";
	while (!Validator::CheckUnit(tmp = Iinput())) { std::cout << "zle :c, podaj jeszcze raz: "; } jednostka = tmp;

	elodowka.AddIngredient(Ingredient(nazwa, ilosc, cena, jednostka));

	std::cout << "Skladnik pomyslnie dodano!\n";
	system("pause");
}

void ELodowkaMenuManager::DeleteIngredient()
{
	std::string nazwa;

	std::cout << "Podaj nazwe Skladnika do usuniecia: ";

	while (!Validator::CheckName(nazwa = Iinput())) { std::cout << "zle :c, podaj jeszcze raz: "; }

	elodowka.DeleteIngredient(nazwa);

	std::cout << "Przepis pomyslnie usunieto!\n";
	system("pause");
}

std::string ELodowkaMenuManager::StateToString[] =
{
	"Menu",
	"Wyswietl Skladniki",
	"Szukaj Przepisow",
	"Dodaj Skladnik",
	"Usun Skladnik",
	"Wyjdz",
};