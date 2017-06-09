#include <iostream>
#include "Library.h"
#include "Item.h"
#include "Student.h"
#include "Magazine.h"
#include "Book.h"
#include <math.h>
#include <memory>
#include <fstream>

/* UI CODE REUSED FROM http://www.cppforschool.com/project/library-management-system.html  also exception catch statement from tutorialpoint.com*/
//By Karolyn Alvarez and Hector Jimenez
//6-8-2017
//CIS-17A Professor James Wilson
using namespace std;

//REQUIRED FUNCTIONS FOR DATA STORAGE
void openBooksForLibrary(shared_ptr<Library> _library) {
	fstream fileBeingRead2;
	static string _bookTitle;
	static string _bookDescription;
	static string _bookAuthor;
	static string _checkOutId;

	fileBeingRead2.open("books.txt", ios::in);
	if (fileBeingRead2) {
		cout << "\tLoading books...\n";
		while (!fileBeingRead2.eof()) {
			getline(fileBeingRead2, _bookTitle);
			if (_bookTitle != "") {
				getline(fileBeingRead2, _bookDescription);
				getline(fileBeingRead2, _bookAuthor);
				getline(fileBeingRead2, _checkOutId);
				auto checkOutId = std::stoi(_checkOutId);
				auto book = make_shared<Book>(_bookTitle, _bookDescription, _bookAuthor);
				if (_library->studentExists(checkOutId)) {
					if (_library->findStudent(checkOutId)->hasBook() == false) {
						_library->findStudent(checkOutId)->checkOut(book);
						book->setCheckOutId(checkOutId);
					}
				}
				_library->addItem(book);
			}
		}
		cout << "\tBooks have been loaded from file.\n";
		fileBeingRead2.close();
	}
	else {
		cout << "Unable to load students from library";
	}
};
void openLibrary(shared_ptr<Library> _library) {
	fstream fileBeingRead1;
	static string _id;
	static string _name;

	fileBeingRead1.open("students.txt", ios::in);
	if (fileBeingRead1) {
		cout << "\tLoading students...\n";
		while (!fileBeingRead1.eof()) {
			getline(fileBeingRead1, _id);
			if (_id != "") {
				getline(fileBeingRead1, _name);
				int id = std::stoi(_id);
				auto student = make_shared<Student>(_name, id);
				_library->addStudent(student);
			}
		}
		cout << "\tStudents have been loaded from file.\n";
		fileBeingRead1.close();
	}
	else {
		cout << "\tUnable to load students from library";
	}
	openBooksForLibrary(_library);
};
void saveBooksForLibrary(shared_ptr<Library> _library) {
	fstream fileOutBooks;
	static string _bookTitle;
	static string _bookDescription;
	static string _bookAuthor;
	static string _checkOutId;

	fileOutBooks.open("books.txt", ios::out);
	if (fileOutBooks) {
		cout << "\tSaving books to file...\n";
		for (int x = 0; x < _library->getAllItemSize(); x++) {
			auto item = _library->findItemByIndex(x);
			fileOutBooks << item->getTitle() << endl;
			fileOutBooks << item->getDescription() << endl;
			fileOutBooks << item->getWrittenBy() << endl;
			fileOutBooks << item->getCheckOutId() << endl;
		}
		cout << "\tBooks have been saved to file.\n";
		fileOutBooks.close();
	}
	else {
		cout << "\tUnable to open student file, Sorry...";
	}


}
void saveLibrary(shared_ptr<Library> _library) {

	fstream fileOutStudents;
	static string _id;
	static string _name;

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
	saveBooksForLibrary(_library);
};


//APP FUNCTIONS
void intro(shared_ptr<Library>);
void aminMenu(shared_ptr<Library>);

// MODIFICATION FUNCTIONS
void modify_book(shared_ptr<Library> _library) {
	try {
		string _title;
		cout << "\nPlease enter book title: ";
		cin.ignore();
		getline(cin, _title);
		std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
		if (_library->bookExists(_title)) {
			auto book = _library->findItem(_title);
			cout << "Would you like to modify the: \n";
			cout << "1)Title\n";
			cout << "2)Description\n";
			int ch;
			cin >> ch;
			if (ch == 1) {
				cin.ignore();
				string newTitle;
				cout << "Enter New Title: ";
				getline(cin, newTitle);
				book->setTitle(newTitle);
				cout << "\nTitle has been set...\n";
				system("pause");
			}
			else if (ch == 2) {
				cin.ignore();
				string newDescription;
				cout << "Enter New Description: ";
				getline(cin, newDescription);
				book->setDescription(newDescription);
				cout << "\nDescription has been set...\n";
				system("pause");
			}
			else {
				throw "You must enter either 1 or 2 for modifying\n";
			}
		}
		else {
			throw "\nBook does not exist, try again.";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
};
void modify_student(shared_ptr<Library> _library, int _id) {
	try {
		if (_library->studentExists(_id)) {
			string newTitle;
			cout << "Enter Name: ";
			cin.ignore();
			getline(cin, newTitle);
			_library->findStudent(_id)->setName(newTitle);
			cout << "\nName has been set...";
		}
		else {
			throw "\nSTUDENT NOT FOUND...\n";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
};

//DISPLAY FUNCTIONS
void displayAllLibrary(shared_ptr<Library> _library) { cout << _library->displayAll(); };
void display_alls(shared_ptr<Library> _library) {
	cout << _library->displayStudents();
};
void display_allb(shared_ptr<Library> _library) {
	cout << _library->displayItems();
};
void display_spb(shared_ptr<Library> _library) {
	try {
		string _title;
		cout << "\n\n\tPlease enter the book title: ";
		cin.ignore();
		getline(cin, _title);
		std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
		if (_library->bookExists(_title)) {
			cout << _library->findItem(_title)->display();
		}
		else {
			throw "\nITEM NOT FOUND...\n";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
};
void display_sps(shared_ptr<Library> _library, int _id) {
	try {
		if (_library->studentExists(_id)) {
			cout << _library->findStudent(_id)->display();
		}
		else {
			throw "\nSTUDENT NOT FOUND...\n";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
};


//CREATE FUNCTIONS
void createStudent(shared_ptr<Library> _library) {
	//EXH
	try {
		long int id;
		cout << "\nNEW STUDENT ENTRY...\n";
		cout << "\nEnter the admission number: ";
		cin >> id;
		if (_library->studentExists(id) != true) {
			string name;
			cout << "\nEnter the Name of The Student: ";
			cin.ignore();
			getline(cin, name);

			auto student = make_shared<Student>(name, id);
			_library->addStudent(student);
			cout << "\nStudent Record Created...\n";
			system("pause");
			cout << "\n\tWould you like to add another student?[Y/N]";
			string choice;
			cin >> choice;
			if (choice == "Y" || choice == "y") {
				createStudent(_library);
			}
			else if (choice == "N" || choice == "n") {

			}
			else {
				throw "\nIncorrect Input..";
			}
		}
		else {
			throw "\nThis is a duplicate id number, try a different number.";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
}
void write_book(shared_ptr<Library> _library) {
	try {
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
			string choice;
			cout << "\nWould you like to add another item?[Y/N] :";
			getline(cin, choice);
			if (choice == "Y" || choice == "y") {
				write_book(_library);
			}
			else if (choice == "N" || choice == "n") {
				cout << "\nBack to main menu...";
			}
			else {
				throw "\nIncorrect Input...Back to main menu.";
			}
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
			string choice;
			cout << "\nWould you like to add another item?[Y/N] :";
			getline(cin, choice);
			if (choice == "Y" || choice == "y") {
				write_book(_library);
			}
			else if (choice == "N" || choice == "n") {
				cout << "\nBack to main menu...";
			}
			else {
				throw "\nIncorrect Input...Back to main menu.";
			}
		}
		else {
			throw "\nIncorrect Input..Try again.\n";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
};

//RETURN AND CHECKOUT FUNCTIONS
void bookReturn(shared_ptr<Library> _library) {
	//EXH
	try {
		int _no;
		cout << "\nPlease enter the student no: ";
		cin.ignore();
		cin >> _no;

		if (_library->studentExists(_no) == true) {
			auto student = _library->findStudent(_no);
			if (student->getTakenOutBook() != nullptr) {
				shared_ptr<Item> bookTaken = student->getTakenOutBook();
				bookTaken->returnIn();
				student->returnBook();
				cout << "\nBook returned thank you!\n\n";
				system("pause");
			}
			else {
				throw "\nThere are no books on queue for this student";
				system("pause");
			}
		}
		else {
			throw "\nStudent does not exist...";
			system("pause");
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
};
void bookCheckout(shared_ptr<Library> _library) {
	//ExH
	try {
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
				if (_library->studentExists(num)) {
					auto student = _library->findStudent(num);
					cout << "\nFound the student...";
					if (student->hasBook()) {
						throw ("\nBut, this student currently has a book checked out.\n");
					}
					else {
						item->setCheckOutId(student->getId());
						student->checkOut(item);
						cout << "\nBook assigned to id: " << num << endl;
						system("pause");
					}
				}
				else {
					throw "This student was not found..returning to Administator Menu\n";
				}
			}
			else {
				throw "\nSorry that book is not available to check out!";
			}
		}
		else {
			throw "\nCouldn't find desired book!";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
		system("pause");
	}
};

//DELETE FUNCTIONS
void delete_student(shared_ptr<Library> _library) {
	//ExcH Done
	try {
		int no;
		cout << "\n\n\tPlease Enter the student number: ";
		cin.ignore();
		cin >> no;
		if (_library->studentExists(no) == true) {
			_library->deleteStudent(no);
			cout << "\n\tStudent has been deleted\n";
			system("pause");
		}
		else {
			throw "\tStudent ID does not exist...";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
};
void delete_book(shared_ptr<Library> _library) {
	//exh
	try {
		string _title;
		cout << "\n\n\tPlease Enter the book title: ";
		std::transform(_title.begin(), _title.end(), _title.begin(), ::tolower);
		cin.ignore();
		getline(cin, _title);
		if (_library->bookExists(_title) == true) {
			auto item = _library->findItem(_title);
			_library->deleteItem(_title);
			cout << "\n\tBook was deleted...\n";
			system("pause");
		}
		else {
			throw "\n\tBook does not exist..\n";
		}
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
};

//MAIN PROGRAM USER CONTROL FLOW
int main() {
	auto library = make_shared<Library>("The Reading Place");
	openLibrary(library);
	int ch;
	intro(library);
	do
	{
		cout << "\n\t***************************************************************";
		cout << "\n\tMAIN MENU";
		cout << "\n\t***************************************************************";
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
void intro(shared_ptr<Library> _library) {
	cout << "\n\tLIBRARY MANAGEMENT SYSTEM\n";
	cout << "\n\tMADE BY : Karolyn Alvarez & Hector Jimenez";
	cout << "\n\tSCHOOL : NORCO COLLEGE\n";
	cout << "\tThis tool will allow you to manage students and books.\n\n";
	system("pause");
	cout << _library->displayAll() << endl;
	cout << "\tOpening Main Menu...\n";

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
	case 12: break;
	default:
		break;
	}
};




