#pragma once
#include <string>
class Item
{
protected:
	std::string title;
	std::string description;
	std::string author;
public:
	Item(std::string, std::string, std::string);
	~Item();
	std::string getTitle() {return title;}
	std::string getAuthor() {return author;}
	std::string getDescription() {return description;}
};

