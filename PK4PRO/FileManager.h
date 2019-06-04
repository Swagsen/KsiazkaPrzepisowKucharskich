#pragma once
#include"Ingredient.h"
#include"Recipe.h"
#include<vector>

class FileManager
{
public:
	FileManager();
	~FileManager();

	std::vector<Recipe> LoadAllRecipes();
	Recipe LoadRecipe(std::string name);

	void SaveAllRecipes(std::vector<Recipe> recipeList);
	void SaveRecipe(Recipe recipe);

	std::vector<Ingredient> LoadElodowka();
	void SaveElodowka(std::vector<Ingredient> ingredientList);

};

