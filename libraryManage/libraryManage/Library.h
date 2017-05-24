#pragma once
#include <memory>
#include <string>
#include "Student.h"
class Library
{
private:
	std::string locationName;
	std::vector<std::shared_ptr<Student>> allStudents;
	std::vector<std::shared_ptr<Student>> allBooks;
public:
	Library(std::string);
	~Library();
	void printBookList();
};

