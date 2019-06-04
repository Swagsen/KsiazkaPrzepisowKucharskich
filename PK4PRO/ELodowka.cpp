#include "ELodowka.h"
#include<algorithm>



ELodowka::ELodowka()
{
	ingriedientList = fileManager.WczytajElodowke();
}


ELodowka::~ELodowka()
{
}

void ELodowka::Display()
{
	if (ingriedientList.empty())
	{
		std::cout << "brak skladnikow w lodowce\n";
		return;
	}

	for (auto it = ingriedientList.begin(); it != ingriedientList.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void ELodowka::SearchRecipes(std::vector<Recipe> recipeList)
{
	//if (recipeList.empty()) return;

	bool gitgut = false;

	for (auto currentRecipe : recipeList)
	{
		gitgut = false;
		for (auto currentIngredient : currentRecipe.GetingriedientList())
		{
			gitgut = false;
			for (auto currentIngredientInFridge : ingriedientList)
			{
				//std::find_if(currentRecipe.GetingriedientList().begin(), currentRecipe.GetingriedientList().end(), [&currentIngredient](Ingredient& ing) {return currentIngredient >= ing; });
				if (currentIngredientInFridge >= currentIngredient)
				{
					gitgut = true;
					break;
					
				}
				//else gitgut = false;
			}

			if (gitgut == false)
				break;

		}

		if (gitgut)
			RecipeAbleToMake.push_back(currentRecipe);
			
	}
	if (RecipeAbleToMake.empty())
	{
		std::cout << "nie znaleziono przepisu ;c" << std::endl;
	}
	else {
		for (auto it : RecipeAbleToMake)
		{
			std::cout << it << std::endl;
		}
	}

}

void ELodowka::AddIngredient(Ingredient ingredient)
{
	ingriedientList.push_back(ingredient);
	fileManager.ZapiszElodowke(ingriedientList);
}

void ELodowka::DeleteIngredient(std::string name)
{
	ingriedientList.erase(std::find_if(ingriedientList.begin(), ingriedientList.end(), [&name](Ingredient& ing) {return ing.GetNazwa() == name; }));
	fileManager.ZapiszElodowke(ingriedientList);
}

void ELodowka::MakeRecipe(std::string name)
{
}




