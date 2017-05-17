#pragma once
#include "Item.h"
#include <string>
class Magazine: public Item
{
private:
	std::string publisher;
public:
	Magazine(std::string, std::string, std::string);
	~Magazine();
	std::string getPublisher() { return publisher; };
	std::string display();
};

