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



int main()
try {
	


	Book book1;

	cout << book1;

	book1.change_title("1984");

	

	book1.change_author("Orwell");
	book1.change_isbn({ 11, 22, 33, 'x' });

	

	Patron member1{ {"Doe","John"},123456789,0 };

	cout << member1;

	int boolcheck = 0;
	boolcheck=member1.check_fees();
	cout << "bool fees:" << boolcheck << "\n\n";

	member1.add_fee(10);
	boolcheck=member1.check_fees();
	
	cout << member1;

	cout << "bool fees:" << boolcheck << "\n\n";

	Library lib1;

	lib1.add_book(book1);
	cout << "Printing below a book from the lib1 Library:\n ";

	for (int i = 0; i < lib1.v_get_books().size(); ++i)
	{
		cout << lib1.v_get_books()[i];
	}


}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}