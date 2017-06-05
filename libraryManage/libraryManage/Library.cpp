#include "Library.h"



Library::Library(std::string _locationName): locationName(_locationName)
{
}


Library::~Library()
{
}

void Library::returnBook(std::string _title)
{
	for (int x = 0; x < allItems.size(); x++) {
		if (_title == allItems[x]->getTitle()) {
			allItems[x]->returnIn();
		}
	}
}

void Library::addStudent(std::shared_ptr<Student> _student)
{
	allStudents.push_back(_student);
}

void Library::addItem(std::shared_ptr<Item> _item)
{
	allItems.push_back(_item);
}

bool Library::bookExists(std::string _title)
{
	for (int x = 0; x < allItems.size(); x++) {
		if (allItems[x]->getTitle() == _title) return true;
	}
	return false;
}

bool Library::studentExists(int _id)
{
	for (int x = 0; x < allStudents.size(); x++) {
		if (allStudents[x]->getId() == _id) return true;
	}
	return false;
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

int Library::findItemIndex(std::string _title)
{
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	for (int x = 0; x < allItems.size(); x++) {
		if (_title == allItems[x]->getTitle()) {
			return x;
		}
	}
	return 0;
}

int Library::findStudentIndex(int _id)
{
	for (int x = 0; x < allStudents.size(); x++) {
		if (_id == allStudents[x]->getId()) {
			return x;
		}
	}
	return 0;
}

void Library::deleteItem(std::string _title)
{
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	if (_title == findItem(_title)->getTitle()) {
		for (int x = 0; x < allItems.size(); x++) {
			if (_title == allItems[x]->getTitle()) {
				allItems.erase(allItems.begin() + x);
			}
		}
	}
}

void Library::deleteStudent(int _id)
{	
	if (_id == findStudent(_id)->getId()) {
		int x = findStudentIndex(_id);
		allStudents.erase(allStudents.begin() + x);
	}
}

void Library::printBookList()
{
}
