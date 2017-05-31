#include "Library.h"



Library::Library(std::string _locationName): locationName(_locationName)
{
}


Library::~Library()
{
}

void Library::addStudent(std::shared_ptr<Student> _student)
{
	allStudents.push_back(_student);
}

void Library::addItem(std::shared_ptr<Item> _item)
{
	allItems.push_back(_item);
}

std::string Library::displayAll()
{ 
	std::string output = "Welcome to your library: " + locationName;
	output += "/n
}

std::string Library::displayItems()
{
	std::string output = "ALL ITEMS /n";
	for (auto _items : allItems) {
		output += "ITEM /n";
		output += "Title: " + _items->getTitle();
		output += "/nDescription: " + _items->getDescription();
		return output;
	}

}

void Library::printBookList()
{
}
