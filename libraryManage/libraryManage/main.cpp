#include <iostream>
#include "Library.h"
#include "Item.h"
#include "Student.h"
#include "Magazine.h"
#include "Book.h"
#include <memory>

using namespace std;
//APP FUNCTIONS
void intro();
void aminMenu(shared_ptr<Library>);

//BASIC LIBRARY FUNCTIONS
void bookCheckout(shared_ptr<Library>) { cout << "Hello frombook checkout"; };
void bookReturn(shared_ptr<Library>) { cout << "Hello frombook checkout"; };

//BASIC ADMIN FUNCTIONS STUDENT
void createStudent(shared_ptr<Library>);
void display_alls(shared_ptr<Library>);
void display_sps(shared_ptr<Library>, int);
//void modify_student(shared_ptr<Library>);
//void delete_student(shared_ptr<Library>);

//BASIC ADMIN FUNCTIONS STUDENT
void write_book(shared_ptr<Library>);
void display_allb(shared_ptr<Library>);
void display_spb(shared_ptr<Library>, string);
//void modify_book(shared_ptr<Library>);
//void delete_book(shared_ptr<Library>);


int main() {
	auto library = make_shared<Library>("The Reading Place");
	/**/
	intro();
	char ch;
	intro();
	do
	{
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. BOOK CHECKOUT";
		cout << "\n\n\t02. BOOK RETURN";
		cout << "\n\n\t03. ADMINISTRATOR MENU";
		cout << "\n\n\t04. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-4) ";
		cin >> ch;
		switch (ch)
		{
		case '1':bookCheckout(library); break;
		case '2':bookReturn(library); break;
		case '3':aminMenu(library);break;
		case '4':exit(0);
		default:cout << "\a";
		}
	} while (ch != '4');
	return 0;
}

void intro() {
	cout << "LIBRARY\n";
	cout << "MANAGEMENT\n";
	cout << "SYSTEM\n";
	cout << "\nMADE BY : Karolyn Alvarez";
	cout << "\nSCHOOL : NORCO COLLEGE\n";
	cout << "Welcome, this tool will allow you to manage students and book, tap any key to get started!\n";
	system("pause");
}

void aminMenu(shared_ptr<Library> _library) {
	int ch2;
	cout << "\n\n\n\tADMINISTRATOR MENU";
	cout << "\n\n\t1.CREATE STUDENT RECORD";
	cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout << "\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout << "\n\n\t4.MODIFY STUDENT RECORD";
	cout << "\n\n\t5.DELETE STUDENT RECORD";
	cout << "\n\n\t6.CREATE BOOK ";
	cout << "\n\n\t7.DISPLAY ALL BOOKS ";
	cout << "\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout << "\n\n\t9.MODIFY BOOK ";
	cout << "\n\n\t10.DELETE BOOK ";
	cout << "\n\n\t11.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-11) ";
	cin >> ch2;
	switch (ch2)
	{
	case 1:	createStudent(_library); break;
	case 2: display_alls(_library); break;
	case 3:
		int num;
		cout << "\n\n\tPlease Enter The Admission No. ";
		cin >> num;
		display_sps(_library, num);
		break;
	case 4: //modify_student(_library);
		break;
	case 5: //delete_student(_library); 
		break;
	case 6:write_book(_library); break;
	case 7: display_allb(_library); break;
	case 8: {
		string _title;
		cout << "\n\n\tPlease Enter The book title. ";
		cin.ignore();
		getline(cin, _title);
		display_spb(_library, _title);
		break;
	}
	case 9: //modify_book(_library); 
		break;
	case 10: //delete_book(_library); 
		break;
	case 11: return;
	default:cout << "\a";
	}
};

void createStudent(shared_ptr<Library> _library) {
	int id;

	cout << "\nNEW STUDENT ENTRY...\n";
	cout << "\nEnter the admission number: ";
	cin >> id;

	string name;
	cout << "\n\nEnter the Name of The Student: ";
	cin.ignore();
	getline(cin, name);
	
	auto student = make_shared<Student>(name, id);
	_library->addStudent(student);
	cout << "\n\nStudent Record Created...";
};
void display_alls(shared_ptr<Library> _library) {
	cout << _library->displayStudents();
};
void display_sps(shared_ptr<Library> _library, int _id) {
	if (_id == (_library->findStudent(_id)->getId()) ) {
		cout << _library->findStudent(_id)->display();
	}
	else {
		cout << "\nSTUDENT NOT FOUND...\n";
	}
};
//void modify_student(shared_ptr<Library>);
//void delete_student(shared_ptr<Library>);

//BASIC ADMIN FUNCTIONS STUDENT
void write_book(shared_ptr<Library> _library) {
	int ch;
	cout << "\nWhat type of item would you like to add?\n";
	cout << "1) Book\n";
	cout << "2) Magazine\n";
	cin >> ch;
	if (ch == 1) {
		string title, description, author;
		cin.ignore();
		cout << "\nNEW BOOK ENTRY...\n";
		cout << "\nEnter the Title: ";
		getline(cin, title);

		cout << "\nEnter the Author: ";
		getline(cin, author);

		cout << "\nEnter the Description: ";
		getline(cin, description);

		auto book = make_shared<Book>(title, description, author);
		_library->addItem(book);
		cout << "\n\nBook Record Created...";
	}
	else if (ch == 2) {
		string title, description, publisher;
		cin.ignore();
		cout << "\nNEW MAGAZINE ENTRY...\n";
		cout << "\nEnter the Title: ";
		getline(cin, title);

		cout << "\nEnter the Publisher: ";
		getline(cin, publisher);

		cout << "\nEnter the Description: ";
		getline(cin, description);

		auto magazine = make_shared<Magazine>(title, description, publisher);
		_library->addItem(magazine);
		cout << "\n\nMagazine Record Created...";
	}
	else {
		cout << "\nIncorrect Input..Try again.\n";
	}
};
void display_allb(shared_ptr<Library> _library) {
	cout << _library->displayItems();
};
void display_spb(shared_ptr<Library> _library, string _title) {
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	if (_title == (_library->findItem(_title)->getTitle())) {
		cout << _library->findItem(_title)->display();
	}
	else {
		cout << "\nITEM NOT FOUND...\n";
	}
};
void modify_book(shared_ptr<Library>);
void delete_book(shared_ptr<Library>);


	/*
	string userInput;
string secondUserInput;

cout << "Would you like to add to the library?[Y/N]" << endl;
getline(cin, userInput);
if (userInput == "Y" || userInput == "y") {
addToLibrary();
}	else if (userInput == "N" || userInput == "n") {
cout << "Display the library?[Y/N]" << endl;
getline(cin, secondUserInput);
if (secondUserInput == "Y" || secondUserInput == "y") {
newCollection.displayCollection();
}	else if (secondUserInput == "N" || secondUserInput == "n") {
cout << "Thanks for creating a library!" << endl;
exit(0);
}	else {
cout << "Incorrect Input, Try to add something to the library again." << endl;
start();
}
	*/

/*
void bookCheckout(shared_ptr<Library> _library){
int id;
cout << "Please Enter the 3 Digit Student ID:";
cin >> id;
if ( _library)
};
*/



