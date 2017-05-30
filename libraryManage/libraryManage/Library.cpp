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

void Library::printBookList()
{
}
