#pragma once
#include <string>
class Item
{
protected:
	std::string title;
	std::string description;
public:
	Item(std::string, std::string);
	~Item();
	virtual std::string display();
};

