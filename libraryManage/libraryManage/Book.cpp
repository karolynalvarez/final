#include "Book.h"



Book::Book(std::string _title, std::string _description, std::string _author): Item(_title, _description)
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
		output += ("\Checked Out by ID#: None, it's available");
		return output;
	}
	else {
		output += ("\nBook Title: " + title);
		output += ("\nDescription: " + description);
		output += ("\nAuthor: " + author);
		output += ("\Checked Out by ID#: " + std::to_string(checkOutId));
		return output;
	}
}

Book::~Book()
{
}
