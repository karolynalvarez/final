#include "Student.h"



Student::Student(std::string _name, int _id): name(_name), id(_id)
{
}


Student::~Student()
{
}

void Student::checkOut(std::shared_ptr<Item>)
{
}

void Student::returnBook(std::shared_ptr<Item>)
{
}

void Student::printBookHistory(std::vector<std::shared_ptr<Item>>)
{
}
