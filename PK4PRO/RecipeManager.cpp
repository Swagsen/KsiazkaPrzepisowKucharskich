#include "RecipeManager.h"
#include<iostream>
#include"MyException.h"
#include<algorithm>

RecipeManager::RecipeManager()
{
}

RecipeManager::~RecipeManager()
{
}

void RecipeManager::AddRecipe(Recipe recipe)
{
	recipeList.push_back(recipe);
}

void RecipeManager::DeleteRecipe(Recipe recipe)
{
	//for (auto it = recipeList.begin(); it != recipeList.end(); it++)
	//{

	//	if (*it == recipe)
	//	{
	//		it--;
	//		recipeList.erase(it+1);
	//		return;
	//	}
	//} 

	recipeList.erase(std::find_if(recipeList.begin(), recipeList.end(), [&recipe](Recipe& rec) {return rec.GetNazwa() == recipe.GetNazwa(); }));
}

void RecipeManager::PrintAllByNames()
{
	for (auto it : recipeList)
	{
		std::cout << it.GetNazwa() << std::endl;
	}
}

void RecipeManager::PrintAll()
{
	for (auto it = recipeList.begin(); it != recipeList.end(); it++)
	{
		std::cout << *it;
	}
}


Recipe RecipeManager::SearchByName(std::string name)
{
	for (auto it : recipeList)
	{
		if (it.GetNazwa() == name)
			return it;
	}

	throw NoRecipe();
}

