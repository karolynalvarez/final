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
	std::vector<std::shared_ptr<Item>> bookHistory;
	std::queue<std::shared_ptr<Item>> bookQueue;
	std::shared_ptr<Item> bookCheckedOut = NULL;
public:
	Student();
	~Student();
	void checkOut(std::shared_ptr<Item>);
	void returnBook(std::shared_ptr<Item>);
	void printBookHistory(std::vector<std::shared_ptr<Item>>);
};

