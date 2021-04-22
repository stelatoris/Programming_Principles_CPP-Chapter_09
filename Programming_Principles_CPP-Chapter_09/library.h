// library.h
#include "std_lib_facilities.h"

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

	Book book2(ISBN(9780, 1410, 3613, '7'),
		"Animal Farm",
		"George Orwell",
		Genre::fiction,
		false);			//availability
	lib.add_book(book2);

	Book book3(ISBN(9780, 3161, 1695, '4'),
		"The Day the Universe Changed",
		"James Burke",
		Genre::nonfiction,
		false);			//availability
	lib.add_book(book3);

	Book book4(ISBN(9780, 1413, 7114, '6'),
		"The BFG",
		"Roald Dahl",
		Genre::children,
		false);			//availability
	lib.add_book(book4);

	Book book5(ISBN(9780, 3948, 0001, '1'),
		"The Cat in the Hat",
		"Dr. Seuss",
		Genre::children,
		false);			//availability
	lib.add_book(book5);

	Book book6(ISBN(9781, 2500, 4072, '5'),
		"Neil Armstrong: A Life of Flight",
		"Jay Barbree ",
		Genre::biography,
		false);			//availability
	lib.add_book(book6);

	Book book7(ISBN(9781, 4711, 7787, '3'),
		"First Man: The Life of Neil Armstrong",
		"James Hansen",
		Genre::biography,
		false);			//availability
	lib.add_book(book7);

	Book book8(ISBN(000, 720, 354, '3'),
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

}