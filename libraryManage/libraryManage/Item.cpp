#include "Item.h"



Item::Item(std::string _title, std::string _description) : title(_title), description(_description)
{
}


Item::~Item()
{
}

std::string Item::display()
{
	return "Some Item";
}


