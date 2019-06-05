#include "ELodowka.h"
#include<algorithm>
#include"MyException.h"



ELodowka::ELodowka()
{
	try 
	{
		ingriedientList = fileManager.LoadElodowka();
	}
	catch (NoFileI e)
	{
		std::cout << e.what();
		system("PAUSE");
		exit(-1);
	}
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
	if (recipeList.empty()) return;

	bool gitgut = false;

	for (auto currentRecipe : recipeList)
	{
		gitgut = false;
		for (auto currentIngredient : currentRecipe.GetingriedientList())
		{
			gitgut = false;
			for (auto currentIngredientInFridge : ingriedientList)
			{
				if (currentIngredientInFridge >= currentIngredient)
				{
					gitgut = true;
					break;
					
				}
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
	try
	{
		fileManager.SaveElodowka(ingriedientList);
	}
	catch (NoFileO e)
	{
		std::cout << e.what();
		system("PAUSE");
		exit(-1);
	}
}

void ELodowka::DeleteIngredient(std::string name)
{
	ingriedientList.erase(std::find_if(ingriedientList.begin(), ingriedientList.end(), [&name](Ingredient& ing) {return ing.GetNazwa() == name; }));
	try
	{
		fileManager.SaveElodowka(ingriedientList);
	}
	catch (NoFileO e)
	{
		std::cout << e.what();
		system("PAUSE");
		exit(-1);
	}
}





