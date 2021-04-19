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



// prints out all the books in the library
void print_book_list(const Library& lib)
{
	cout << "\n****************************************\n"
		<< "List of books registered in the library:\n\n";
		
	for (int i = 0; i < lib.v_get_books().size(); ++i)
	{
		cout << lib.v_get_books()[i];
	}

}

// prints out all the patrons in the library
void print_patron_list(const Library& lib)
{
	cout << "\n******************************************\n"
		<< "List of patrons registered in the library:\n\n";

	for (int i = 0; i < lib.v_get_patrons().size(); ++i)
	{
				cout << lib.v_get_patrons()[i];
	}
	
}

void print_transaction_list(const Library& lib)
{
	cout << "\n***********************************************\n"
		<< "List of transactions registered in the library:\n\n";
		for (int i = 0; i < lib.v_get_transactions().size(); ++i)
	{
		cout << "Transaction " << i + 1 << '\n';
		cout << lib.v_get_transactions()[i];
	}

}


void test_library()
{
	// create library
	Library test_lib;
	Chrono::Date date;

	// Add books
	Book book1(ISBN(9780, 1410, 3614, '4'),
		"1984",
		"George Orwell",
		Genre::fiction,
		true);			//availability
	test_lib.add_book(book1);

	Book book2(ISBN(9780,1410,3613,'7'),
		"Animal Farm",
		"George Orwell",
		Genre::fiction,
		true);			//availability
	test_lib.add_book(book2);

	Book book3(ISBN(9780,3161,1695,'4'),
		"The Day the Universe Changed",
		"James Burke",
		Genre::nonfiction,
		true);			//availability
	test_lib.add_book(book3);

	Book book4(ISBN(9780,1413,7114,'6'),
		"The BFG",
		"Roald Dahl",
		Genre::children,
		true);			//availability
	test_lib.add_book(book4);

	Book book5(ISBN(9780,3948,0001,'1'),
		"The Cat in the Hat",
		"Dr. Seuss",
		Genre::children,
		true);			//availability
	test_lib.add_book(book5);

	Book book6(ISBN(9781,2500,4072,'5'),
		"Neil Armstrong: A Life of Flight",
		"Jay Barbree ",
		Genre::biography,
		true);			//availability
	test_lib.add_book(book6);

	Book book7(ISBN(9781,4711,7787,'3'),
		"First Man: The Life of Neil Armstrong",
		"James Hansen",
		Genre::biography,
		true);			//availability
	test_lib.add_book(book7);

	Book book8(ISBN(000,720,354,'3'),
		"	The Fellowship of the Ring : The Lord of the Rings, Book 1",
		"John R. R. Tolkien",
		Genre::fiction,
		true);			//availability
	test_lib.add_book(book8);

	//Add patrons
	Patron patron1(Patron_name("Schwarzenegger", "Arnold"),
		8291997,		// card number
		0);				// fees
	test_lib.add_patron(patron1);

	Patron patron2(Patron_name("Cameron", "James"),
		20291984,		// card number
		0);				// fees
	test_lib.add_patron(patron2);

	Patron patron3(Patron_name("Connor", "Sarah"),
		19841984,		// card number
		0);				// fees
	test_lib.add_patron(patron3);

	Patron patron4(Patron_name("Reese", "Kyle"),
		38416,		// card number
		0);				// fees
	test_lib.add_patron(patron4);

	Patron patron5(Patron_name("no", "patron"),
		123456789,		// card number
		0);				// fees

	print_book_list(test_lib);

	test_lib.book_check_out(book6, patron2, date);
	test_lib.book_check_out(book2, patron1, date);


	cout << "Date: " << date << '\n';
	
	
	print_transaction_list(test_lib);

	print_book_list(test_lib);

	//print_patron_list(test_lib);
}

void test_library2()
{
	Library test_lib2;
	Chrono::Date date;

	// Add books
	Book book1(ISBN(9780, 1410, 3614, '4'),
		"1984",
		"George Orwell",
		Genre::fiction,
		true);			//availability
	test_lib2.add_book(book1);

	Book book2(ISBN(9780, 1410, 3613, '7'),
		"Animal Farm",
		"George Orwell",
		Genre::fiction,
		true);			//availability
	test_lib2.add_book(book2);

	Book book3(ISBN(9780, 3161, 1695, '4'),
		"The Day the Universe Changed",
		"James Burke",
		Genre::nonfiction,
		true);			//availability
	test_lib2.add_book(book3);

	Patron patron1(Patron_name("Schwarzenegger", "Arnold"),
		8291997,		// card number
		0);				// fees
	test_lib2.add_patron(patron1);

	test_lib2.book_check_out(book2, patron1, date);



	cout << "Testing access to bool\n";
	cout << test_lib2.v_get_books()[1].availability() << '\n';
	print_transaction_list(test_lib2);
	print_book_list(test_lib2);
}

int main()
try {
	
	test_library();
	


}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}