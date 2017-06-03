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
	output += this->displayItems();
	output += this->displayStudents();
	return output;
}

std::string Library::displayItems()
{
	std::string output = "\nALL ITEMS\n";
	for (int x = 0; x < allItems.size(); x++) {
		output += "\n\nITEM #" + (std::to_string(x + 1));
		output += allItems[x]->display();
	}
	return output;
}

std::string Library::displayStudents()
{
	std::string output = "ALL STUDENTS \n";
	for (int x = 0; x < allStudents.size(); x++) {
		output += allStudents[x]->display();
	}
	return output;
}

std::shared_ptr<Student> Library::findStudent(int _id)
{
	for (int x = 0; x < allStudents.size(); x++) {
		if (_id == allStudents[x]->getId()) {
			return allStudents[x];
		}
	}
	return nullptr;
}

std::shared_ptr<Item> Library::findItem(std::string _title)
{
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	for (int x = 0; x < allItems.size(); x++) {
		if (_title == allItems[x]->getTitle()) {
			return allItems[x];
		}
	}
	return nullptr;
}

void Library::printBookList()
{
}
