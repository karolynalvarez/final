#include "Book.h"



Book::Book(std::string _title, std::string _description, std::string _author): Item(_title, _description)
{
	author = _author;
}


Book::~Book()
{
}
