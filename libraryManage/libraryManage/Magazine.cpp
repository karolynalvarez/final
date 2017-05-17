#include "Magazine.h"



Magazine::Magazine(std::string _title, std::string _description, std::string _publisher) : Item(_title, _description)
{
	publisher = _publisher;
}


Magazine::~Magazine()
{
}

std::string Magazine::display()
{
	std::string output;
	output += "Title: ";
	output += title;
	output += "Description: ";
	output += description;
	output += "Publisher: ";
	output += publisher;
	return output;
}
