#pragma once
#include <string>
#include "Item.h"
#include <vector>
#include <queue>
#include <memory>
class Student
{
private:
	std::string name;
	long int id;
	std::shared_ptr<Item> bookCheckedOut = nullptr;
public:
	Student(std::string _name, long  int _id) : name(_name), id(_id){};
	~Student();
	bool hasBook() { if (bookCheckedOut != nullptr) { return true; } };
	void checkOut(std::shared_ptr<Item>);
	void returnBook();
	long int getId() { return id; };
	std::string display();
	void setName(std::string _name) { name = _name; };
	std::string getName() { return name; };
	std::string getTitle() {
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		return name;
	};
	std::shared_ptr<Item> getTakenOutBook() { return bookCheckedOut; };
};

