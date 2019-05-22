#pragma once

#include <iostream>
#include <vector>
#include "Debug.h"
#include "Product.h"

class Shop
{
public:

	Shop();

	std::vector<Product> availableProducts;

	void StartNewOrder();

	Product GetProductDetails();

	std::string AskProductName();

	int AskProductQuantity();

	int AskPayment(std::vector<Product> order);

	int GetPayment(std::vector<Product> order);

	void PrintOrderSummary(std::vector<Product> order, int payment);

	void PrintIntroMessage();

	void PrintExitMessage();

	void PrintMenuMessage();

private:

	bool IsProductAvailable(const std::string& productName);

	Product* GetProductByName(const std::string& productName);

	double GetTotalPrice(std::vector<Product> order);

};