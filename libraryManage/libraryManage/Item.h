#pragma once
#include <string>
#include <algorithm>
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
	std::string getTitle() { 
		std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		return title; 
	};
};

