#include "Recipe.h"



Recipe::Recipe(std::string _nazwa, float _czasPrzygotowania, int _ocena, int _iloscSkladnikow, float _koszt, std::string _kategoria,
	std::string _typDania, std::string _kuchnia, std::string _opis, std::string _sposobPrzygotowania) : nazwa(_nazwa), czasPrzygotowania(_czasPrzygotowania), ocena(_ocena),
	iloscSkladnikow(_iloscSkladnikow), koszt(_koszt), kategoria(_kategoria), typDania(_typDania), kuchnia(_kuchnia), opis(_opis), sposobPrzygotowania(_sposobPrzygotowania)
{
}

Recipe::Recipe()
{
}

Recipe::~Recipe()
{
}

void Recipe::DodajSkladnik(Ingredient ingredient)
{
	ingriedientList.push_back(ingredient);
}

//bool Recipe::operator==(Recipe & recipe)
//{
//
//	return (this->nazwa == recipe.GetName());
//}

//bool Recipe::operator<(Recipe& const recipe)const
//{
//
//	return (this->nazwa < recipe.GetName() );
//}

//bool operator<(Recipe& recipe1, Recipe& recipe2)
//{
//
//	return (recipe1.GetName() < recipe2.GetName());
//}

void Recipe::DodajSkladnik(std::string _nazwa, float _ilosc, float _cena, std::string _jednostka)
{
	ingriedientList.push_back(Ingredient(_nazwa, _ilosc, _cena, _jednostka));
}

std::ostream& operator<<(std::ostream& stream, Recipe recipe)
{
	stream << "Nazwa: " << recipe.nazwa << std::endl;
	stream << "Czas przygotowania: " << recipe.czasPrzygotowania << "min" << std::endl;
	stream << "Ocena:" << recipe.ocena << std::endl;
	stream << "Koszt: " << recipe.koszt << std::endl;
	stream << "Kategoria: " << recipe.kategoria << std::endl;
	stream << "Typ Dania: " << recipe.typDania << std::endl;
	stream << "Kuchnia: " << recipe.kuchnia << std::endl;
	stream << "Ilosc skladnikow: " << recipe.iloscSkladnikow << std::endl;
	stream << "Lista skladnikow: \n\n";

	for (auto it = recipe.ingriedientList.begin(); it != recipe.ingriedientList.end(); it++)
	{
		stream << *it;
	}

	return stream;
}
