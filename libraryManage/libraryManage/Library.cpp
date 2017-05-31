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
	std::string output = "ALL ITEMS /n";
	for (int x = 0; x < allItems.size(); x++) {
		output += ("/nITEM #" + std::to_string((x + 1)) + "/n" );
		output += ("Title: " + allItems[x]->getTitle());
		output += ("/nDescription: " + allItems[x]->getDescription());
	}
	return output;
}

std::string Library::displayStudents()
{
	std::string output = "ALL STUDENTS /n";
	for (int x = 0; x < allStudents.size(); x++) {
		output += ("STUDENT ID:" + std::to_string(allStudents[x]->getId()) + "/n");
		output += ("/nName: " + allStudents[x]->getName());
	}
	return output;
}

void Library::printBookList()
{
}
