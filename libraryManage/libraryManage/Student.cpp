#include "Student.h"
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

bool Student::isQueueEmpty()
{
	return bookQueue.empty();
}
 
std::string Student::display()
{
	std::string output;
	if (bookCheckedOut == nullptr) {
		output += (("\nSTUDENT ID: " + std::to_string(id)) + ("\nNAME:" + this->getTitle() + "\n"));
	}
	else {
		output += (("\nSTUDENT ID: " + std::to_string(id)) + ("\nNAME:" + this->getTitle()) + ("\nBook Checked Out: " + bookCheckedOut->getTitle() + "\n"));
	}
	return output;
}
