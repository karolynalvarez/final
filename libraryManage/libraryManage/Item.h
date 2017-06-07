#pragma once
#include <string>
#include <algorithm>
class Item
{
protected:
	std::string title;
	std::string description;
	bool checkedOut = false;
	int checkOutId;
public:
	Item(std::string, std::string);
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
	void setCheckOutId(int id) { checkOutId = id; };
	int getCheckOutId() { return checkOutId; };
	bool getStatus() { return checkedOut; };
};

