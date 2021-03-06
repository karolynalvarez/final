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
public:
	std::vector<std::shared_ptr<Item>> allItems;
	Library(std::string);
	~Library();
	void returnBook(std::shared_ptr<Item>);
	void addStudent(std::shared_ptr<Student>);
	void addItem(std::shared_ptr<Item>);
	bool bookExists(std::string);
	bool studentExists(int);
	std::string displayAll();
	std::string displayItems();
	std::string displayStudents();
	std::string getLocationName() { return locationName; };
	std::shared_ptr<Student> findStudent(int);
	std::shared_ptr<Student> findStudentyByIndex(int);
	std::shared_ptr<Item> findItem(std::string);
	std::shared_ptr<Item> findItemByIndex(int);
	int findItemIndex(std::string);
	int findStudentIndex(int);
	void deleteItem(std::string);
	void deleteStudent(int);
	int getAllItemSize() { return allItems.size(); };
	int getAllStudentSize() { return allStudents.size(); };
	void printBookList();
};

