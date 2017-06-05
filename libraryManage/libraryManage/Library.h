#pragma once
#include <memory>
#include <algorithm>
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
	void returnBook(std::string);
	void addStudent(std::shared_ptr<Student>);
	void addItem(std::shared_ptr<Item>);
	bool bookExists(std::string);
	bool studentExists(int);
	std::string displayAll();
	std::string displayItems();
	std::string displayStudents();
	std::string getLocationName() { return locationName; };
	std::shared_ptr<Student> findStudent(int);
	std::shared_ptr<Item> findItem(std::string);
	int findItemIndex(std::string);
	int findStudentIndex(int);
	void deleteItem(std::string);
	void deleteStudent(int);
	void printBookList();
};

