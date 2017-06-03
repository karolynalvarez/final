#pragma once
#include <string>
class Item
{
protected:
	std::string title;
	std::string description;
	bool checkedOut = false;
public:
	Item(std::string, std::string);
	~Item();
	virtual std::string display();
	void checkOut() { checkedOut = true; };
};

