#include "Magazine.h"



Magazine::Magazine(std::string _title, std::string _description, std::string _publisher) : Item(_title, _description, _publisher)
{
	publisher = _publisher;
}


Magazine::~Magazine()
{
}

std::string Magazine::display()
{
	std::string output;
	if (checkOutId == -1) {
		output += ("\nMagazine Title: " + title);
		output += ("\nDescription: " + description);
		output += ("\nPublisher: " + publisher);
		output += ("\nChecked Out by ID#: None, it's available\n");
		return output;
	}
	else {
		output += ("\nMagazine Title: " + title);
		output += ("\nDescription: " + description);
		output += ("\nPublisher: " + publisher);
		output += ("\nChecked Out by ID#: " + std::to_string(checkOutId) + "\n");
		return output;
	}
}
