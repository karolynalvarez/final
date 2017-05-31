#include "Book.h"



Book::Book(std::string _title, std::string _description, std::string _author): Item(_title, _description)
{
	author = _author;
}


std::string Book::display()
{
	std::string output;
	output += ("\nBook Title: " + title);
	output += ("\nDescription: " + description);
	output += ("\nAuthor: " + author);
	return output;
}

Book::~Book()
{
}
