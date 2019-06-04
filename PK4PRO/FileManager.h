#pragma once
#include"Ingredient.h"
#include"Recipe.h"
#include<vector>

class FileManager
{
public:
	FileManager();
	~FileManager();

	std::vector<Recipe> WczytajWszsytkiePrzepisy();
	Recipe WczytajPrzepis(std::string name);

	void ZapiszWszsytkiePrzepisy(std::vector<Recipe> recipeList);
	void ZapiszPrzepis(Recipe recipe);

	std::vector<Ingredient> WczytajElodowke();
	void ZapiszElodowke(std::vector<Ingredient> ingredientList);

};

