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
	int id;
	std::queue<std::shared_ptr<Item>> bookQueue;
	std::shared_ptr<Item> bookCheckedOut = NULL;
public:
	Student(std::string _name, int _id);
	~Student();
	bool hasBook() { if (bookCheckedOut == NULL) return false; };
	void checkOut(std::shared_ptr<Item>);
	void returnBook();
	int getId() { return id; };
	int getBookQueueSize();
	std::string display();
	void setName(std::string _name) { name = _name; };
	std::string getName() { return name; };
	std::string getTitle() {
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		return name;
	};
	std::string getTakenOutBookName() {
		return bookQueue.front()->getTitle();
	};
};

