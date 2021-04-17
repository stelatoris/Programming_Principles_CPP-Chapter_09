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
#include "book.h"

int main()
try {
	


	Book book1;

	cout << book1;

	book1.change_title("blabla");

	cout << book1;

	book1.change_author("Hasan");
	book1.change_isbn({ 1, 2, 3, 'x' });

	cout << book1;

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}