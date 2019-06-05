#pragma once
#include<vector>
#include"Ingredient.h"
#include"Recipe.h"
#include "FileManager.h"

class ELodowka
{
	   	 
	std::vector<Ingredient> ingriedientList;

	std::vector<Recipe> RecipeAbleToMake;

	FileManager fileManager;

public:
	ELodowka();
	~ELodowka();

	void Display();

	void SearchRecipes(std::vector<Recipe> recipeList);

	void AddIngredient(Ingredient ingredient);

	void DeleteIngredient(std::string name);
};

