#include "Student.h"



Student::Student(std::string _name, int _id): name(_name), id(_id)
{
}


Student::~Student()
{
}

void Student::checkOut(std::shared_ptr<Item> _item)
{
	bookQueue.push(_item);
	bookHistory.push_back(_item);
	bookCheckedOut = _item;
}

void Student::returnBook(std::shared_ptr<Item> _item)
{
	if (bookCheckedOut != NULL) {
		bookQueue.pop();
		bookCheckedOut = NULL;
	} 
}

void Student::printBookHistory(std::vector<std::shared_ptr<Item>>)
{
}

std::string Student::display()
{
	std::string output = (("\nSTUDENT ID: " + std::to_string(id)) + ("\nNAME:" + name + "\n"));
	return output;
}
