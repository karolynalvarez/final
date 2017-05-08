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
	std::string getTitle() {return title;}
	std::string getDescription() {return description;}
};

