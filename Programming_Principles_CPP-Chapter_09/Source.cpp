/*5. This exercise and the next few require you to design and implement a
Book class, such as you can imagine as part of software for a library.Class
Book should have members for the ISBN, title, author, and copyright
date.Also store data on whether or not the book is checked out.Create
functions for returning those data values.Create functions for checking
a book inand out.Do simple validation of data entered into a Book. for
example, accept ISBNs only of the form n - n - n - x where n is an integer and
x is a digit or a letter.Store an ISBN as a string.
*/

#include "std_lib_facilities.h"
#include "Chrono.h"
#include "book.h"
#include "library.h"


void main_menu(const Library& lib, const Patron& p, const Chrono::Date& d);
void login_screen(const Library& lib);

void prev_menu()
{
	int s = -100;
	while (s != 0) {
		cout << "Enter '0' to return to main menu :";
		cin >> s;
		if (s == 0) break;
		else {
			cout << "Invalid option\n";
		}
	}
}

void call_book(Library& lib, const Patron& p, const Chrono::Date& d, int c)
{
	cout << '\n' << lib.v_get_books()[c - 1]<<'\n';
	cout << "To check out this book enter (1) or enter (0) to return to main menu: ";
	int s=-100;
	while (s != 0) {
		cin >> s;
		if (s == 0) break;
		else if (s == 1) {
			int indx = 0;
			indx = lib.v_get_transactions().size();		// get size of vector before adding another index
			lib.book_check_out((lib.v_get_books()[c - 1]), p, d);	// check out book
			cout << "\n****************************************************\n"
				<< "***************** Book Checked Out *****************\n"
				<< "****************************************************\n"
				<< "Transaction number: " << indx + 1 << '\n';
			cout << lib.v_get_transactions()[indx];
			break;
		}
		else {}
	}	
}

void menu_list_books(Library& lib, const Patron& p, const Chrono::Date& d)
{
	cout << "\n****************************************\n"
		<< "List of books registered in the library:\n\n";

	for (int i = 0; i < lib.v_get_books().size(); ++i)
	{
		cout << "Book number: " << i + 1 << '\n';
		cout << lib.v_get_books()[i]
			<< "------------------------------------------------\n";
	}
	
	int s=-100;
	while (s != 0) {
		cout << '\n'
			<< "Please enter a book (number) or enter '0' to return to main menu: ";		
		cin >> s;
		if (s == 0)break;
		else if(s>0 && s< lib.v_get_books().size()+1) {		// number of books in vector
			call_book(lib, p, d, s);
			break;
		}
		else {
			cout << "Invalid option\n";
		}
	}	
}

void menu_list_patrons(const Library& lib, const Patron& p, const Chrono::Date& d)
{
	cout << "\n******************************************\n"
		<< "List of patrons registered in the library:\n\n";

	for (int i = 0; i < lib.v_get_patrons().size(); ++i)
	{
		cout << lib.v_get_patrons()[i]
			<< "------------------------------------------------\n";
	}	
	prev_menu();
}

void menu_list_transactions(const Library& lib, const Patron& p, const Chrono::Date& d)
{
	cout << "\n***********************************************\n"
		<< "List of transactions registered in the library:\n\n";
	for (int i = 0; i < lib.v_get_transactions().size(); ++i)
	{
		cout << "Transaction " << i + 1 << '\n';
		cout << lib.v_get_transactions()[i]
			<< "------------------------------------------------\n";
	}
	prev_menu();
}

void menu_list_del_accounts(const Library& lib, const Patron& p, const Chrono::Date& d)	// delinquent accounts
{
	vector<Patron>del_accounts;
	for (int i = 0; i < lib.v_get_patrons().size(); ++i) {
		if (lib.v_get_patrons()[i].fees() > 0) del_accounts.push_back(lib.v_get_patrons()[i]);
	}
	cout << "Delinquent accounts:\n";
	for (int i = 0; i < del_accounts.size(); ++i) {
		cout << del_accounts[i] 
			<< "------------------------------------------------\n";
	}
	prev_menu();
}



void main_menu(Library& lib, const Patron& p, const Chrono::Date& d)
{
	int s = 0;
	while (s != 5) {
		cout << "\n***************************************************************\n"
			<< "***************************************************************\n"
			<< "Account holder:\n"
			<< p << '\n';	// cout account holders info

		cout << "Please choose an option (number) from the following list:\n"
			<< '\n'
			<< "(1)-List books\n"
			<< "(2)-List patrons\n"
			<< "(3)-List transactions\n"
			<< "(4)-List delinquint accounts\n"
			<< "(5)-Change user\n"
			<< '\n';
		cin >> s;
		if (s == 1) {
			menu_list_books(lib, p, d);
		}
		else if (s == 2) {
			menu_list_patrons(lib, p, d);
		}
		else if (s == 3) {
			menu_list_transactions(lib, p, d);
		}
		else if (s == 4) {
			menu_list_del_accounts(lib, p, d);
		}
		else if (s == 5) {
			break;
		}

		else { break; }
	}
	return;
	
}


int main()
try {
	using namespace lib;

	load_library(test_lib);
	
	int n = 0;
	while (n != -1) {

		cout << "*********************************************************\n"
		<< "\tWelcome to the Springfield Public Library.\n"
		<< "**********************************************************\n"
		<< "\n";

		for (int i = 0; i < test_lib.v_get_patrons().size(); ++i)
		{
			cout << "User " << i + 1 << '\n';
			cout << test_lib.v_get_patrons()[i]<<'\n';
		}

		cout << "Please select a user number: ";		

		cin >> n;
		if (n == 1) {
			main_menu(test_lib, test_lib.v_get_patrons()[n - 1], date);
		}
		else if (n == 2) {
			main_menu(test_lib, test_lib.v_get_patrons()[n - 1], date);
		}
		else if (n == 3) {
			main_menu(test_lib, test_lib.v_get_patrons()[n - 1], date);
		}
		else if (n == 4) {
			main_menu(test_lib, test_lib.v_get_patrons()[n - 1], date);
		}
		else {
			break;
		}
	}
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}