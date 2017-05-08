#include "Magazine.h"



Magazine::Magazine(std::string _title, std::string _description, std::string _publisher) : Item(_title, _description)
{
	publisher = _publisher;
}


Magazine::~Magazine()
{
}
