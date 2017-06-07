#include "Student.h"



Student::Student(std::string _name, int _id): name(_name), id(_id)
{
}


Student::~Student()
{
}

void Student::checkOut(std::shared_ptr<Item> _item)
{
	if (bookCheckedOut == nullptr) {
		bookQueue.push(_item);
		bookCheckedOut = _item;
	}
}

void Student::returnBook()
{
	if (bookCheckedOut != NULL) {
		bookQueue.pop();
		bookCheckedOut = NULL;
	}
}

int Student::getBookQueueSize()
{
	return bookQueue.size();
}
 
std::string Student::display()
{
	std::string output = (("\nSTUDENT ID: " + std::to_string(id)) + ("\nNAME:" + this->getTitle() + "\n"));
	return output;
}
