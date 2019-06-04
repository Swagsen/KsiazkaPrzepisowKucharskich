#include<vector>
#include"Recipe.h"

#pragma once
class RecipeManager
{
private:
	
public:
	std::vector<Recipe> recipeList;
	RecipeManager();
	~RecipeManager();

	void AddRecipe(Recipe recipe);
	void DeleteRecipe(Recipe recipe);
	void PrintAllByNames();
	void PrintAll();
	Recipe SearchByName(std::string name);
};

