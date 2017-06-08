#pragma once
#include <string>
#include <algorithm>
class Item
{
protected:
	std::string title;
	std::string description;
	std::string writtenBy;
	bool checkedOut = false;
	int checkOutId = -1;
public:
	Item(std::string, std::string, std::string);
	~Item();
	virtual std::string display();
	void checkOut() { checkedOut = true; };
	void returnIn() { checkedOut = false; checkOutId = -1; };
	std::string getTitle() { 
		std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		return title; 
	};
	void setTitle(std::string newTitle) { title = newTitle; }
	void setDescription(std::string newDesc) { description = newDesc; }
	std::string getDescription() { return description; }
	std::string getWrittenBy() { return writtenBy; }
	void setCheckOutId(int id) { checkOutId = id; checkedOut = true; };
	int getCheckOutId() { return checkOutId; };
	bool getStatus() { return checkedOut; };
};

