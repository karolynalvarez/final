#pragma once
#include <memory>
#include <string>
#include "Student.h"
#include "Item.h"
class Library
{
private:
	std::string locationName;
	std::vector<std::shared_ptr<Student>> allStudents;
	std::vector<std::shared_ptr<Item>> allItems;
public:
	Library(std::string);
	~Library();
	void addStudent(std::shared_ptr<Student>);
	void addItem(std::shared_ptr<Item>);
	void printBookList();
};

