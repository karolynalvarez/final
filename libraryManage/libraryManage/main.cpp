#include <iostream>
#include "Library.h"
#include "Item.h"
#include "Student.h"
#include "Magazine.h"
#include "Book.h"
#include <memory>

using namespace std;
/*
void start();
void addToLibrary();
*/

int main() {
	/*
	cout << "Hello! This command line tool will allow you to create a collection of records using objects to store data. Lets get started!" << endl << endl;
	auto book = make_shared<Book>("Title", "Description", "Some guy");
	cout << book->getTitle() << endl << book->getDescription() << endl << book->getAuthor();
	auto library = make_shared<Library>("HOME");
	cout << "Welcome to your new library:  "<< library->getLocationName() << endl;
	cout << "/nLet's add a book and create a student..." << endl;
	auto book1 = make_shared<Book>("1", "Description", "Some guy");
	auto book2 = make_shared<Book>("2", "Description", "Some guy");
	auto book3 = make_shared<Magazine>("3", "Description", "Some guy");
	auto book4 = make_shared<Magazine>("4", "Description", "Some guy");
	library->addItem(book1);
	library->addItem(book2);
	library->addItem(book3);
	library->addItem(book4);
	auto student = make_shared<Student>("Hector", 712);
	library->addStudent(student);
	cout << "Great we've made some books take a look: " << endl;
	cout << "/n" << library->displayItems() << endl;
	cout << "/n And here is a student..." << library->displayStudents() << endl;
	system("pause");
	start();*/
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
