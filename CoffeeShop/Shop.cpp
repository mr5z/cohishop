#include <iostream>
#include <vector>
#include "Shop.h"

Shop::Shop()
{
	availableProducts.clear();
	availableProducts.push_back(Product("Kopiko", 1, 125));
	availableProducts.push_back(Product("Nescafe", 1, 130));
	availableProducts.push_back(Product("Barako", 1, 140));
	availableProducts.push_back(Product("Latte", 1, 125));
	availableProducts.push_back(Product("Espresso", 1, 100));
	availableProducts.push_back(Product("Decaffeinato", 1, 110));
	availableProducts.push_back(Product("Doppio", 1, 125));
	availableProducts.push_back(Product("Lungo", 1, 85));
	availableProducts.push_back(Product("Moccacino", 1, 75));
	availableProducts.push_back(Product("Marocchino", 1, 95));
	availableProducts.push_back(Product("Ginseng", 1, 130));
	availableProducts.push_back(Product("Caffelatte", 1, 115));
}

void Shop::StartNewOrder()
{
	std::vector<Product> order;
	do
	{
		Product product = GetProductDetails();
		order.push_back(product);
		Debug::Log("Type 'done' if you're done else, just hit enter to enter new product.");
		std::string input = Debug::ReadLine();
		if (input == "done")
			break;
	} while (true);
	double totalPrice = GetTotalPrice(order);
	Debug::Log("Total price: " + std::to_string(totalPrice));
	int payment = AskPayment(order);
	PrintOrderSummary(order, payment);
}

Product Shop::GetProductDetails()
{
	std::string productName;
	while (true)
	{
		productName = AskProductName();
		if (!IsProductAvailable(productName))
		{
			Debug::Log("Sorry. The item you typed does not seem to exist. Please type a enter a new one.");
		}
		else
		{
			break;
		}
	}
	int quantity = AskProductQuantity();
	Product* product = GetProductByName(productName);
	return Product(product->name(), quantity, product->price());
}

std::string Shop::AskProductName()
{
	Debug::Log("Please enter the product name:");
	while (true)
	{
		std::string productName = Debug::ReadLine();
		if (productName != "")
		{
			return productName;
		}
		else
		{
			Debug::Log("Invalid product name");
		}
	}
}

int Shop::AskProductQuantity()
{
	Debug::Log("Please enter the quantity:");
	while (true)
	{
		int quantity = Debug::ReadInt();
		if (quantity > 0)
		{
			return quantity;
		}
		else
		{
			Debug::Log("Invalid quantity. Please enter again.");
		}
	}
}

int Shop::AskPayment(std::vector<Product> order)
{
	Debug::Log("Please enter the payment amount:");
	int payment = GetPayment(order);
	return payment;
}

int Shop::GetPayment(std::vector<Product> order)
{
	double totalPrice = GetTotalPrice(order);
	while (true)
	{
		int payment = Debug::ReadInt();
		if (payment < totalPrice)
		{
			Debug::Log("Insufficient payment. Please enter a higher amount than " + std::to_string(totalPrice));
		}
		else
		{
			return payment;
		}
	}
}

void Shop::PrintOrderSummary(std::vector<Product> order, int payment)
{
	Debug::ClearScreen();
	Debug::Log("------------------------------------");
	Debug::Log("Order summary");
	Debug::Log("------------------------------------");

	Debug::Log("Product Name\t\tQuantity\tPrice");

	for (auto& product : order)
	{
		Debug::Log(
			product.name() + "\t\t\t" +
			std::to_string(product.quantity()) + "\t\t" +
			std::to_string(product.price()));
	}
	Debug::Log("------------------------------------");

	double totalPrice = GetTotalPrice(order);
	Debug::Log("Total price: $" + std::to_string(totalPrice));
	Debug::Log("Payment: $" + std::to_string(payment));
	Debug::Log("Change: $" + std::to_string(payment - totalPrice));
	Debug::Log("------------------------------------");
}

void Shop::PrintIntroMessage()
{
	Debug::Log("------------------------------------");
	Debug::Log("Welcome to Meteor Bucks coffee shop!");
	Debug::Log("------------------------------------");
}

void Shop::PrintExitMessage()
{
	Debug::Log("------------------------------------");
	Debug::Log("Thank you for using the app. Have a nice day!");
	Debug::Log("------------------------------------");
}

void Shop::PrintMenuMessage()
{
	Debug::Log("Type 1 to create new order");
	Debug::Log("Type 2 clear the screen");
	Debug::Log("Type 3 exit the app");
}


bool Shop::IsProductAvailable(const std::string& productName)
{
	for (auto& product : availableProducts)
	{
		if (product.name() == productName)
			return true;
	}
	return false;
}

Product* Shop::GetProductByName(const std::string& productName)
{
	for (auto& product : availableProducts)
	{
		if (product.name() == productName)
			return &product;
	}
	return nullptr;
}

double Shop::GetTotalPrice(std::vector<Product> order)
{
	double totalPrice = 0;
	for (int i = 0; i < order.size(); ++i)
	{
		Product product = order[i];
		totalPrice += product.totalPrice();
	}
	return totalPrice;
}