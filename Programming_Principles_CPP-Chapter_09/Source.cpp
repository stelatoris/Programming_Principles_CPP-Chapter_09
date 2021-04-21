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


void main_menu( Library& lib, Patron p, Chrono::Date d);
void back_to_menu( Library& lib, Patron p, Chrono::Date d);
void login_screen( Library& lib);

void menu_check_out( Library& lib, Patron p, Chrono::Date d)
{
	back_to_menu(lib, p, d);
}

void menu_check_in( Library& lib, Patron p, Chrono::Date d)
{
	back_to_menu(lib, p, d);
}

void call_book( Library& lib, Patron p, Chrono::Date d, int c)
{
	cout <<'\n'<< lib.v_get_books()[c-1];
	cout<<"To check out this book enter (1) or enter (0) to return to main menu: ";
	int s;
	cin >> s;
	if (s == 0)back_to_menu(lib, p, d);
	if (s == 1) {
		int indx = 0;
		indx=lib.v_get_transactions().size();
		lib.book_check_out((lib.v_get_books()[c - 1]), p, d);
		cout << "\n****************************************************\n"
			 << "***************** Book Checked Out *****************\n"
			 << "****************************************************\n"
			 << "Transaction number: " << indx + 1 << '\n';
		cout << lib.v_get_transactions()[indx];
		back_to_menu(lib, p, d);
	}
}

void menu_list_books( Library& lib, Patron p, Chrono::Date d)
{
	cout << "\n****************************************\n"
		 << "List of books registered in the library:\n\n";

	for (int i = 0; i < lib.v_get_books().size(); ++i)
	{
		cout << "Book number: " << i + 1 << '\n';
		cout << lib.v_get_books()[i];
	}
	cout << '\n'
		<< "Please enter a book (number) or enter '0' to return to main menu: ";
	int s;
	cin >> s;
	if(s==0)main_menu(lib, p, d);
	call_book(lib, p, d, s);	
}



void menu_list_patrons( Library& lib, Patron p, Chrono::Date d)
{
	cout << "\n******************************************\n"
		<< "List of patrons registered in the library:\n\n";

	for (int i = 0; i < lib.v_get_patrons().size(); ++i)
	{
		cout << lib.v_get_patrons()[i];
	}

	back_to_menu(lib, p, d);
}

void menu_list_transactions( Library& lib, Patron p, Chrono::Date d)
{
	cout << "\n***********************************************\n"
		<< "List of transactions registered in the library:\n\n";
	for (int i = 0; i < lib.v_get_transactions().size(); ++i)
	{
		cout << "Transaction " << i + 1 << '\n';
		cout << lib.v_get_transactions()[i];
	}
	back_to_menu(lib, p, d);
}

void menu_list_del_accounts( Library& lib, Patron p, Chrono::Date d)
{
		vector<Patron>del_accounts;
	for (int i = 0; i < lib.v_get_patrons().size(); ++i) {
		if (lib.v_get_patrons()[i].fees() > 0) del_accounts.push_back(lib.v_get_patrons()[i]);
	}
	cout << "Delinquent accounts:\n";
	for (int i = 0; i < del_accounts.size(); ++i) {
		cout << del_accounts[i];
	}
	
	back_to_menu(lib, p, d);
}

void back_to_menu( Library& lib, Patron p, Chrono::Date d)
{
	cout << "Please press (0) to get back to menu.\n";
	int m;
	cin >> m;
	if (m == 0) main_menu(lib, p, d);
}

namespace lib 
{
	Library test_lib;	// create library
	Library test_lib2;
	Chrono::Date date;
}
void load_library(Library& lib)
{
	using namespace lib;
	// Add books
	Book book1(ISBN(9780, 1410, 3614, '4'),
		"1984",
		"George Orwell",
		Genre::fiction,
		false);			//availability
	lib.add_book(book1);

	Book book2(ISBN(9780,1410,3613,'7'),
		"Animal Farm",
		"George Orwell",
		Genre::fiction,
		false);			//availability
	lib.add_book(book2);

	Book book3(ISBN(9780,3161,1695,'4'),
		"The Day the Universe Changed",
		"James Burke",
		Genre::nonfiction,
		false);			//availability
	lib.add_book(book3);

	Book book4(ISBN(9780,1413,7114,'6'),
		"The BFG",
		"Roald Dahl",
		Genre::children,
		false);			//availability
	lib.add_book(book4);

	Book book5(ISBN(9780,3948,0001,'1'),
		"The Cat in the Hat",
		"Dr. Seuss",
		Genre::children,
		false);			//availability
	lib.add_book(book5);

	Book book6(ISBN(9781,2500,4072,'5'),
		"Neil Armstrong: A Life of Flight",
		"Jay Barbree ",
		Genre::biography,
		false);			//availability
	lib.add_book(book6);

	Book book7(ISBN(9781,4711,7787,'3'),
		"First Man: The Life of Neil Armstrong",
		"James Hansen",
		Genre::biography,
		false);			//availability
	lib.add_book(book7);

	Book book8(ISBN(000,720,354,'3'),
		"	The Fellowship of the Ring : The Lord of the Rings, Book 1",
		"John R. R. Tolkien",
		Genre::fiction,
		false);			//availability
	lib.add_book(book8);

	Book book9(ISBN(000, 0, 0, '0'),	// this book not in library, for testing errors
		"	No book there",
		"no name",
		Genre::fiction,
		false);			//availability

	//Add patrons
	Patron patron1(Patron_name("Schwarzenegger", "Arnold"),
		8291997,		// card number
		0);				// fees
	lib.add_patron(patron1);

	Patron patron2(Patron_name("Cameron", "James"),
		20291984,		// card number
		0);				// fees
	lib.add_patron(patron2);

	Patron patron3(Patron_name("Connor", "Sarah"),
		19841984,		// card number
		0);				// fees
	lib.add_patron(patron3);

	Patron patron4(Patron_name("Reese", "Kyle"),
		38416,		// card number
		0);				// fees
	lib.add_patron(patron4);

	Patron patron5(Patron_name("no", "patron"),	// this patron not in library, for testing errors
		123456789,		// card number
		0);				// fees

	lib.book_check_out(book1, patron1, date);

}

void user_number( Library& lib, int n, Chrono::Date d)
{
	switch (n) {
		case 1:
			main_menu(lib, lib.v_get_patrons()[n - 1], d);
			break;
		case 2:
			main_menu(lib, lib.v_get_patrons()[n - 1], d);
			break;
		case 3:
			main_menu(lib, lib.v_get_patrons()[n - 1], d);
			break;
		case 4:
			main_menu(lib, lib.v_get_patrons()[n - 1], d);
			break;
	}
}


void main_menu( Library& lib, Patron p, Chrono::Date d)
{
	using namespace lib;
	cout<<"\n***************************************************************\n"
		<< "***************************************************************\n"
		<<"Account holder:\n"
		<< p<< '\n';

	cout << "Please choose an option (number) from the following list:\n"
		<< '\n'
		<< "(1)-List books\n"
		<< "(2)-List patrons\n"
		<< "(3)-List transactions\n"
		<< "(4)-List delinquint accounts\n"
		<< "(5)-Change user\n"
		<< '\n';

	int choice = 0;
	cin >> choice;
	switch (choice){

	case 1:
		menu_list_books(lib, p, d);
		break;
	case 2:
		menu_list_patrons(lib, p, d);
		break;
	case 3:
		menu_list_transactions(lib, p, d);
		break;
	case 4:
		menu_list_del_accounts(lib, p, d);
		break;
	case 5:
		login_screen(lib);
		break;
	default:
		cout << "Invalid option.\n";
	}
}

void login_screen( Library& lib)
{
	using namespace lib;
	cout << "*********************************************************\n"
		<< "\tWelcome to the Springfield Public Library.\n"
		<< "**********************************************************\n"
		<< "\n";

	for (int i = 0; i < lib.v_get_patrons().size(); ++i)
	{
		cout << "User "<<i+1<<'\n';
		cout << lib.v_get_patrons()[i];
	}

	cout << "Please select a user number: ";
	int n = 0;
	cin >> n;
	user_number(lib, n, date);
}


int main()
try {
	using namespace lib;
	load_library(test_lib);
	login_screen(test_lib);
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}