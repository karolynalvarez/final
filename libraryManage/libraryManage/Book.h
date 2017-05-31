#pragma once
#include "Item.h"
#include <string>

class Book:public Item
{
private:
	std::string author;
public:
	Book(std::string, std::string, std::string);
	std::string display();
	~Book();
};

