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
	cout << "List of books registered in the library:\n"
		<< "----------------------------------------\n";
	for (int i = 0; i < lib.v_get_books().size(); ++i)
	{
		cout << lib.v_get_books()[i];
	}
}

// prints out all the patrons in the library
void print_patron_list(const Library& lib)
{
	cout << "List of patrons registered in the library:\n"
		<< "----------------------------------------\n";
	for (int i = 0; i < lib.v_get_patrons().size(); ++i)
	{
		cout << lib.v_get_patrons()[i];
	}
}

void test_library()
{
	// create library
	Library test_lib;

	Book book1(ISBN(9780, 1410, 3614, '4'),
		"1984",
		"George Orwell",
		Genre::fiction,
		false);
	test_lib.add_book(book1);

	Book book2(ISBN(9780,1410,3613,'7'),
		"Animal Farm",
		"George Orwell",
		Genre::fiction,
		false);
	test_lib.add_book(book2);

	Book book3(ISBN(9780,3161,1695,'4'),
		"The Day the Universe Changed",
		"James Burke",
		Genre::nonfiction,
		false);
	test_lib.add_book(book3);

	Book book4(ISBN(9780,1413,7114,'6'),
		"The BFG",
		"Roald Dahl",
		Genre::children,
		false);
	test_lib.add_book(book4);

	Book book5(ISBN(9780,3948,0001,'1'),
		"The Cat in the Hat",
		"Dr. Seuss",
		Genre::children,
		false);
	test_lib.add_book(book5);

	Book book6(ISBN(9781,2500,4072,'5'),
		"Neil Armstrong: A Life of Flight",
		"Jay Barbree ",
		Genre::biography,
		false);
	test_lib.add_book(book6);

	Book book7(ISBN(9781,4711,7787,'3'),
		"First Man: The Life of Neil Armstrong",
		"James Hansen",
		Genre::biography,
		false);
	test_lib.add_book(book7);

	Book book8(ISBN(000,720,354,'3'),
		"	The Fellowship of the Ring : The Lord of the Rings, Book 1",
		"John R. R. Tolkien",
		Genre::fiction,
		false);
	test_lib.add_book(book8);

	print_book_list(test_lib);
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