#include "Book.h"



Book::Book(std::string _title, std::string _description, std::string _author): Item(_title, _description, _author)
{
	author = _author;
}


std::string Book::display()
{
	std::string output;
	if (checkOutId == -1) {
		output += ("\nBook Title: " + title);
		output += ("\nDescription: " + description);
		output += ("\nAuthor: " + author);
		output += ("\nChecked Out by ID#: None, it's available\n\n");
		return output;
	}
	else {
		output += ("\nBook Title: " + title);
		output += ("\nDescription: " + description);
		output += ("\nAuthor: " + author);
		output += ("\nChecked Out by ID#: " + std::to_string(checkOutId) + "\n");
		return output;
	}
}

Book::~Book()
{
}
