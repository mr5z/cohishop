// CoffeeShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Shop.h"

int main()
{
	Shop shop;
	shop.PrintIntroMessage();
	while (true)
	{
		shop.PrintMenuMessage();
		std::string input = Debug::ReadLine();
		if (input == "1")
		{
			shop.StartNewOrder();
		}
		else if (input == "2")
		{
			Debug::ClearScreen();
		}
		else if (input == "3")
		{
			shop.PrintExitMessage();
			Debug::ReadLine();
			break;
		}
		else
		{
			Debug::Log("Invalid input");
		}
	}
}