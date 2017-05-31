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
	
	char ch;
	intro();
	do
	{
		clrscr();
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. BOOK ISSUE";
		cout << "\n\n\t02. BOOK DEPOSIT";
		cout << "\n\n\t03. ADMINISTRATOR MENU";
		cout << "\n\n\t04. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-4) ";
		ch = getche();
		switch (ch)
		{
		case '1':clrscr();
			book_issue();
			break;
		case '2':book_deposit();
			break;
		case '3':admin_menu();
			break;
		case '4':exit(0);
		default:cout << "\a";
		}
	} while (ch != '4');
	system("pause");
	/*start()*/
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
