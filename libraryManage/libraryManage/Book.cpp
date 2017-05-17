#include "Book.h"



Book::Book(std::string _title, std::string _description, std::string _author): Item(_title, _description)
{
	author = _author;
}


std::string Book::display()
{
	std::string output;
	output += "Title: ";
	output += title;
	output += "Description: ";
	output += description;
	output += "Author: ";
	output += author;
	return output;
}

Book::~Book()
{
}
