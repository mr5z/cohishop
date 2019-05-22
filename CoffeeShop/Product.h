#pragma once

#include <string>

class Product
{
	double _price;
	int _quantity;
	std::string _name;
public:

	Product(std::string name, int quantity, double price) :
		_price(price),
		_name(name),
		_quantity(quantity)
	{

	}

	double price()
	{
		return _price;
	}

	std::string name() const
	{
		return _name;
	}

	int quantity()
	{
		return _quantity;
	}

	double totalPrice()
	{
		return _price * _quantity;
	}
};

