#include "Item.h"



Item::Item(std::string _title, std::string _description, std::string _writtenBy) : title(_title), description(_description), writtenBy(_writtenBy)
{
}


Item::~Item()
{
}

std::string Item::display()
{
	return "Some Item";
}



