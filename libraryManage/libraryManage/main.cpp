#include <iostream>
#include "Item.h"
#include <memory>

using namespace std;
/*
void start();
void addToLibrary();
*/

int main() {
	cout << "Hello! This command line tool will allow you to create a collection of records using objects to store data. Lets get started!" << endl << endl;
	auto item = std::make_shared<Item>("Book", "some book", "some guy or girl");
	cout << item->getAuthor() << item->getDescription() << item->getTitle();
	system("pause");
	/*start();*/
	return 0;
}
/*
void start() {
string userInput;
string secondUserInput;

cout << "Would you like to add to the library?[Y/N]" << endl;
getline(cin, userInput);
if (userInput == "Y" || userInput == "y") {
addToLibrary();
}
else if (userInput == "N" || userInput == "n") {
cout << "Display the library?[Y/N]" << endl;
getline(cin, secondUserInput);
if (secondUserInput == "Y" || secondUserInput == "y") {
newCollection.displayCollection();
}
else if (secondUserInput == "N" || secondUserInput == "n") {
cout << "Thanks for creating a library!" << endl;
exit(0);
}
else {
cout << "Incorrect Input, Try to add something to the library again." << endl;
start();
}
}
else {
cout << "Incorrect Input, Try to add something to the library again." << endl;
start();
}
start();
};
void addToLibrary() {
};
*/
