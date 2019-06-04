#include "FileManager.h"
#include<fstream>
#include"MyException.h"



FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

std::vector<Recipe> FileManager::WczytajWszsytkiePrzepisy()
{
	std::ifstream plNazwy;
	plNazwy.open("NazwyPrzepisow.txt");

	if (plNazwy.bad())
		throw NoFileI();

	if (plNazwy.fail())
		throw NoFileI();

	std::string nazwa;
	std::vector<Recipe> tmp;

	while (!plNazwy.eof())
	{
		std::getline(plNazwy, nazwa);
		if (nazwa == "")
			throw NoFileI();

		tmp.push_back(WczytajPrzepis(nazwa));
	}


	plNazwy.close();
	return tmp;
}

Recipe FileManager::WczytajPrzepis(std::string name)
{
	std::ifstream plo;
	plo.open(name + ".txt");

	if (plo.fail())
		throw NoFileI();

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


	std::getline(plo, nazwa);
	plo >> czasPrzygotowania;
	plo >> ocena;
	plo >> koszt;
	plo >> kategoria;
	plo >> typDania;
	plo >> kuchnia;
	plo >> iloscSkladnikow;
	std::getline(plo, opis);
	std::getline(plo, opis);
	std::getline(plo, sposobPrzygotowania);


	Recipe recipe(nazwa, czasPrzygotowania, ocena, iloscSkladnikow, koszt, kategoria, typDania, kuchnia, opis, sposobPrzygotowania);

	for (int i = 0; i < iloscSkladnikow; i++)
	{
		plo >> nazwa;
		plo >> ilosc;
		plo >> cena;
		plo >> jednostka;
		recipe.DodajSkladnik(Ingredient(nazwa, ilosc, cena, jednostka));

	}

	plo.close();
	return recipe;

}

void FileManager::ZapiszWszsytkiePrzepisy(std::vector<Recipe> recipeList)
{
	std::ofstream plNazwy;
	plNazwy.open("NazwyPrzepisow.txt");

	if (plNazwy.bad())
		throw NoFileO();


	for (int i = 0; i < recipeList.size(); i++)
	{
		plNazwy << recipeList[i].GetNazwa();

		if (i != recipeList.size() - 1)
			plNazwy << std::endl;

		ZapiszPrzepis(recipeList[i]);
	}

	plNazwy.close();
}

void FileManager::ZapiszPrzepis(Recipe recipe)
{
	std::ofstream plo;
	plo.open(recipe.GetNazwa() + ".txt");

	if (plo.bad())
		throw NoFileO();

	plo << recipe.GetNazwa() << std::endl;
	plo << recipe.GetCzasPrzygotowania() << std::endl;
	plo << recipe.GetOcena() << std::endl;
	plo << recipe.GetKoszt() << std::endl;
	plo << recipe.GetKategoria() << std::endl;
	plo << recipe.GetTypDania() << std::endl;
	plo << recipe.GetKuchnia() << std::endl;
	plo << recipe.GetIloscSkladnikow() << std::endl;
	plo << recipe.GetOpis() << std::endl;
	plo << recipe.GetSposobPrzygotowania() << std::endl;

	for (int i = 0; i < recipe.GetingriedientList().size(); i++)
	{
		plo << recipe.GetingriedientList()[i].GetNazwa() << std::endl;
		plo << recipe.GetingriedientList()[i].GetIlosc() << std::endl;
		plo << recipe.GetingriedientList()[i].GetCena() << std::endl;
		plo << recipe.GetingriedientList()[i].GetJednostka() << std::endl;
	}
	plo.close();
}

std::vector<Ingredient> FileManager::WczytajElodowke()
{
	std::ifstream pli;
	pli.open("skladnikiWlodowce.txt");

	if (pli.bad())
		throw NoFileI();

	if (pli.fail())
		throw NoFileI();
	
	std::string nazwa;
	float ilosc;
	float cena;
	std::string jednostka;

	int ingredientCount;
	pli >> ingredientCount;


	std::vector<Ingredient> ingredientList;

	for (int i = 0; i < ingredientCount; i++)
	{
		pli >> nazwa;
		pli >> ilosc;
		pli >> cena;
		pli >> jednostka;

		ingredientList.push_back(Ingredient(nazwa, ilosc, cena, jednostka));

	}
	pli.close();

	return ingredientList;
}

void FileManager::ZapiszElodowke(std::vector<Ingredient> ingredientList)
{
	std::ofstream plo;
	plo.open("skladnikiWlodowce.txt");

	if (plo.bad())
		throw NoFileO();

	plo << ingredientList.size() << std::endl;

	for (int i = 0; i < ingredientList.size(); i++)
	{
		plo << ingredientList[i].GetNazwa() << std::endl;
		plo << ingredientList[i].GetIlosc() << std::endl;
		plo << ingredientList[i].GetCena() << std::endl;
		plo << ingredientList[i].GetJednostka() << std::endl;
	}
	plo.close();
}
