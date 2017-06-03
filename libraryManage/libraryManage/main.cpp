#include <iostream>
#include "Library.h"
#include "Item.h"
#include "Student.h"
#include "Magazine.h"
#include "Book.h"
#include <memory>



using namespace std;
void intro();
void aminMenu(shared_ptr<Library>);
void addToLibrary();
void bookCheckout(shared_ptr<Library>);
void bookReturn(shared_ptr<Library>);

int main() {
	auto library = make_shared<Library>("The Reading Place");
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
		case 1:	createStudent(); break;
		case 2: display_alls();break;
		case 3:
			char num[6];
			clrscr();
			cout << "\n\n\tPlease Enter The Admission No. ";
			cin >> num;
			display_sps(num);
			break;
		case 4: modify_student();break;
		case 5: delete_student();break;
		case 6: clrscr();
			write_book();break;
		case 7: display_allb();break;
		case 8: {
			char num[6];
			clrscr();
			cout << "\n\n\tPlease Enter The book No. ";
			cin >> num;
			display_spb(num);
			break;
		}
		case 9: modify_book();break;
		case 10: delete_book();break;
		case 11: return;
		default:cout << "\a";
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
};
void bookCheckout(shared_ptr<Library> _library){
		int id;
		cout << "Please Enter the 3 Digit Student ID:";
		cin >> id;
		if ( _library)
};


