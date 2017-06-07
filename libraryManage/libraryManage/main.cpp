#include <iostream>
#include "Library.h"
#include "Item.h"
#include "Student.h"
#include "Magazine.h"
#include "Book.h"
#include <memory>
#include <fstream>

/*CODE REUSED FROM http://www.cppforschool.com/project/library-management-system.html */

using namespace std;
//APP FUNCTIONS
void intro();
void aminMenu(shared_ptr<Library>);

//BASIC LIBRARY FUNCTIONS
void bookCheckout(shared_ptr<Library>);
void bookReturn(shared_ptr<Library>);
void displayAllLibrary(shared_ptr<Library>);

void openLibrary(shared_ptr<Library> _library) {

	fstream fileBeingRead1;
	fstream fileBeingRead2;
	static string _id;
	static string _name;
	static string _bookTitle;
	static string _bookDescription;
	static string _bookAuthor;
	static string _checkOutId;

	fileBeingRead1.open("students.txt", ios::in);
	if (fileBeingRead1) {
		cout << "\tLoading students...\n";
		while (!fileBeingRead1.eof()) {
			getline(fileBeingRead1, _id);
			getline(fileBeingRead1, _name);
			int id = std::stoi(_id);
			auto student = make_shared<Student>(_name, id);
			_library->addStudent(student);
		}
		cout << "\tStudents have been loaded from file.\n";
		fileBeingRead1.close();
	}
	else {
		cout << "\tUnable to load students from library";
	}

	fileBeingRead2.open("books.txt", ios::in);
	if (fileBeingRead2) {
		cout << "\tLoading books...\n";
		while (!fileBeingRead2.eof()) {
			getline(fileBeingRead2, _bookTitle);
			getline(fileBeingRead2, _bookDescription);
			getline(fileBeingRead2, _bookAuthor);
			getline(fileBeingRead2, _checkOutId);
			auto checkOutId = std::stoi(_checkOutId);
			auto book = make_shared<Book>(_bookTitle, _bookDescription, _bookAuthor);
			book->setCheckOutId(checkOutId);
			_library->addItem(book);
		}
		cout << "\tBooks have been loaded from file.\n";
		fileBeingRead2.close();
	}
	else {
		cout << "Unable to load students from library";
	}
};
void saveLibrary(shared_ptr<Library> _library) {

	fstream fileOutStudents;
	fstream fileOutBooks;

	static string _id;
	static string _name;

	static string _bookTitle;
	static string _bookDescription;
	static string _bookAuthor;
	static string _checkOutId;

	fileOutStudents.open("students.txt", ios::out);
	if (fileOutStudents) {
		cout << "\tSaving students to file...\n";
		for (int x = 0; x < _library->getAllStudentSize(); x++) {
			auto student = _library->findStudentyByIndex(x);
			fileOutStudents << student->getId() << endl;
			fileOutStudents << student->getName() << endl;
		}
		cout << "\tStudents have been saved to file.\n";
		fileOutStudents.close();
	}
	else {
		cout << "\tUnable to open student file, Sorry...";
	}
	/*
	fileBeingRead2.open("books.txt", ios::in);
	if (fileBeingRead2) {
		cout << "\tLoading books...\n";
		while (!fileBeingRead2.eof()) {
			getline(fileBeingRead2, _bookTitle);
			getline(fileBeingRead2, _bookDescription);
			getline(fileBeingRead2, _bookAuthor);
			auto book = make_shared<Book>(_bookTitle, _bookDescription, _bookAuthor);
			_library->addItem(book);
		}
		cout << "\tBooks have been loaded from file.\n";
		fileBeingRead2.close();
	}
	else {
		cout << "Unable to load students from library";
	}
	*/

};

//BASIC ADMIN FUNCTIONS STUDENT
void createStudent(shared_ptr<Library>);
void display_alls(shared_ptr<Library>);
void display_sps(shared_ptr<Library>, int);
void modify_student(shared_ptr<Library>, int);
void delete_student(shared_ptr<Library>);

//BASIC ADMIN FUNCTIONS STUDENT
void write_book(shared_ptr<Library>);
void display_allb(shared_ptr<Library>);
void display_spb(shared_ptr<Library>);
void modify_book(shared_ptr<Library>);
void delete_book(shared_ptr<Library>);


int main() {
	auto library = make_shared<Library>("The Reading Place");
	openLibrary(library);
	int ch;
	intro();
	do
	{
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. BOOK CHECKOUT";
		cout << "\n\n\t02. BOOK RETURN";
		cout << "\n\n\t03. ADMINISTRATOR MENU";
		cout << "\n\n\t04. SAVE & EXIT";
		cout << "\n\n\tPlease Select Your Option (1-4) ";
		cin >> ch;
		switch (ch)
		{
		case 1 :bookCheckout(library); break;
		case 2 :bookReturn(library); break;
		case 3 :aminMenu(library);break;
		case 4: 
			saveLibrary(library);
			system("pause");
			exit(0);
		default:cout << "\tIncorrect key entered...\n";
		}
	} while (ch != '4');
	return 0;
}

void intro() {
	cout << "\n\tLIBRARY MANAGEMENT SYSTEM\n";
	cout << "\n\tMADE BY : Karolyn Alvarez & Hector Jimenez";
	cout << "\n\tSCHOOL : NORCO COLLEGE\n";
	cout << "\tWelcome, this tool will allow you to manage students and book.\n\n";
	system("pause");
}

void aminMenu(shared_ptr<Library> _library) {
	int ch2;
	cout << "\n\n\n\tADMINISTRATOR MENU";
	cout << "\n\n\t1.)CREATE STUDENT RECORD";
	cout << "\n\n\t2.)DISPLAY ALL STUDENTS RECORD";
	cout << "\n\n\t3.)DISPLAY SPECIFIC STUDENT RECORD ";
	cout << "\n\n\t4.)MODIFY STUDENT RECORD";
	cout << "\n\n\t5.)DELETE STUDENT RECORD";
	cout << "\n\n\t6.)CREATE BOOK ";
	cout << "\n\n\t7.)DISPLAY ALL BOOKS ";
	cout << "\n\n\t8.)DISPLAY SPECIFIC BOOK ";
	cout << "\n\n\t9.)MODIFY BOOK ";
	cout << "\n\n\t10.)DELETE BOOK ";
	cout << "\n\n\t11.)DISPLAY WHOLE LIBRARY ";
	cout << "\n\n\t12.)BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-11) ";
	cin >> ch2;
	switch (ch2)
	{
	case 1:	createStudent(_library); break;
	case 2: display_alls(_library); break;
	case 3:
		int num;
		cout << "\n\nPlease Enter The Admission No. ";
		cin >> num;
		display_sps(_library, num);
		break;
	case 4: 
		int num2;
		cout << "\n\nPlease Enter The Admission No. ";
		cin >> num2;
		modify_student(_library, num2);
		break;
	case 5: delete_student(_library); break;
	case 6:write_book(_library); break;
	case 7: display_allb(_library); break;
	case 8: display_spb(_library); break;
	case 9: modify_book(_library); 
		break;
	case 10: delete_book(_library); break;
	case 11: displayAllLibrary(_library); break;
	case 12: aminMenu(_library);
	default:
		cout << "\nIncorrect Input try again...";
		aminMenu(_library);
	}
};

void createStudent(shared_ptr<Library> _library) {
	try {
		int id;

		cout << "\nNEW STUDENT ENTRY...\n";
		cout << "\nEnter the admission number: ";
		cin >> id;
		if (_library->studentExists(id) != true) {
			string name;
			cout << "nEnter the Name of The Student: ";
			cin.ignore();
			getline(cin, name);

			auto student = make_shared<Student>(name, id);
			_library->addStudent(student);
			cout << "\nStudent Record Created...";
		}
		else {
			throw "This is a duplicate id number, try a different number\n";
		}
	}
	catch (string e) {
		cout << e;
		aminMenu(_library);
	}
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
void modify_student(shared_ptr<Library> _library, int _id) {
	if (_id == (_library->findStudent(_id)->getId())) {
			string newTitle;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, newTitle);
			_library->findStudent(_id)->setName(newTitle);
	}
	else {
		cout << "\nSTUDENT NOT FOUND...\n";
	}
};
void delete_student(shared_ptr<Library> _library) {
	int no;
	cout << "\n\n\tPlease Enter the student number: ";
	cin.ignore();
	cin >> no;
	if (no == _library->findStudent(no)->getId()) {
		_library->deleteStudent(no);
	}
	else {
		cout << "\nStudent not found...\n";
	}
};

void bookCheckout(shared_ptr<Library> _library) {
	string _title;
	cout << "\nPlease enter the book title: ";
	cin.ignore();
	getline(cin, _title);
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	if (_library->bookExists(_title) == true) {
		auto item = _library->findItem(_title);
		if (item->getStatus() == false) {
			int num;
			cout << "\nNow enter the student number who it will be assigned to:";
			cin >> num;
			cin.ignore();
			if (_library->studentExists(num)) {
				auto student = _library->findStudent(num);
				cout << "\nFound the student no. Checking out book now...";
				if (student->hasBook() == false) {
					item->setCheckOutId(student->getId());
					student->checkOut(item);
				}
				else {
					cout << student->getName() << " currently has a book checked out.\n";
				}
			}
			else {
				cout << "This student was not found..returning to Administator Menu";
				system("pause");
			}
		}
		else {
			cout << "\nSorry that book is not available!";
			system("pause");
		}
	}
	else {
		cout << "\nCouldn't find desired book!";
		system("pause");
	}
};
void bookReturn(shared_ptr<Library> _library) {
	int _no;
	cout << "\nPlease enter the student no: ";
	cin.ignore();
	cin >> _no;
	if ( _library->studentExists(_no) == true) {
		auto student = _library->findStudent(_no);
		int queueSize = student->getBookQueueSize();
		if ( queueSize != 0 ) {
			string bookTaken = student->getTakenOutBookName();
			_library->returnBook(bookTaken);
			student->returnBook();
			cout << "\nBook returned thank you!";
			system("pause");
		}
		else {
			cout << "\nThere are no books on queue for this student";
			system("pause");
		}

	}
	else {
		cout << "\nCouldn't find this student!";
		system("pause");
	}
};
void displayAllLibrary(shared_ptr<Library> _library) { cout << _library->displayAll(); };

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
		cout << "\nBook Record Created...";
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
void display_spb(shared_ptr<Library> _library) {
	string _title;
	cout << "\n\n\tPlease enter the book title: ";
	cin.ignore();
	getline(cin, _title);
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	if (_title == (_library->findItem(_title)->getTitle())) {
		cout << _library->findItem(_title)->display();
	}
	else {
		cout << "\nITEM NOT FOUND...\n";
	}
};
void modify_book(shared_ptr<Library> _library) {
	string _title;
	cout << "\nPlease enter book title: ";
	cin.ignore();
	getline(cin, _title);
	std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
	if (_title == (_library->findItem(_title)->getTitle())) {
		cout << "Would you like to modify the: \n";
		cout << "1)Title\n";
		cout << "2)Description\n";
		int ch;
		cin.ignore();
		cin >> ch;
		if (ch == 1) {
			string newTitle;
			cout << "Enter New Title: ";
			getline(cin, newTitle);
			_library->findItem(_title)->setTitle(newTitle);
		}
		else if (ch == 2) {
			string newDescription;
			cout << "Enter New Description: ";
			getline(cin, newDescription);
			_library->findItem(_title)->setDescription(newDescription);
		}
		else {
			cout << "Please enter either 1, 2, 3\n";
		}
	}
	else {
		cout << "\nITEM NOT FOUND...\n";
	}
};
void delete_book(shared_ptr<Library> _library) {
		string _title;
		cout << "\n\n\tPlease Enter the book title: ";
		std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
		cin.ignore();
		getline(cin, _title);
		if (_title == _library->findItem(_title)->getTitle()) {
			_library->deleteItem(_title);
		}
		else {
			cout << "Book not found try another title\n";
		}
};


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



