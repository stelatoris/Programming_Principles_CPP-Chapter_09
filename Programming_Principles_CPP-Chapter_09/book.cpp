#include "std_lib_facilities.h"
#include "book.h"

//--------------------------------------------------------------------------------
// Genre class
vector<string>genre_tbl = {
	"None","Fiction","Nonfiction","Periodical","Biography","Children"
};

ostream& operator<<(ostream& os, Genre g)
{
	return os << genre_tbl[int(g)];
}

//--------------------------------------------------------------------------------
// ISBN class constructor
ISBN::ISBN(int n1, int n2, int n3, char x) : n1{ n1 }, n2{ n2 }, n3{ n3 }, x{ x }
{
}

// default ISBN constructor
//const ISBN& default_ISBN()
//{
//	static ISBN nn{ 0,0,0,'X' };
//	return nn;
//}

ISBN::ISBN() : n1{ 0 }, n2{ 0 }, n3{ 0 }, x{ 'X' }
{
}

// ISBN Operator overloading
ostream& operator<<(ostream& os, const ISBN& n)
{
	return os << n.n1 << '-' << n.n2 << '-' << n.n3 << '-' << n.x;
}

istream& operator>>(istream& is, ISBN& nn)
{
	int n1, n2, n3;
	char ch1, ch2, ch3;
	char x;
	is >> n1 >> ch1 >> n2 >> ch2 >> n3 >> ch3 >> x;
	if (!is) return is;
	if (ch1 != '-' || ch2 != '-' || ch3 != '-') {
		is.clear(ios_base::failbit);
		return is;
	}

	nn = ISBN(n1, n2, n3, x);
	return is;
}

bool operator==(const ISBN& a, const ISBN& b)
{
	return a.n1 == b.n1 &&
		a.n2 == b.n2 &&
		a.n3 == b.n3 &&
		a.x == b.x;
}

bool operator!=(const ISBN& a, const ISBN& b)
{
	return !(a == b);
}

//--------------------------------------------------------------------------------

// Book class constructor
Book::Book(ISBN isbnnum, string title, string author, Genre genre, bool available)
	: n{ isbnnum }, t{ title }, a{ author }, g{ genre }, available{ available }
{
}

// default Book constructor
const Book& default_book()
{
	static Book bb{ ISBN(), "", "" , Genre(),  false };
	return bb;
}

Book::Book()
	:n{ default_book().isbn() },
	t{ default_book().title() },
	a{ default_book().author() },
	g{ default_book().genre() },
	available{ default_book().availability() }
{
}

// Book cin, cout Operator overloading
ostream& operator<<(ostream& os, const Book& b)
{
	return os << "Title: " << b.title() << '\n'
		<< "Author: " << b.author() << '\n'
		<< "Genre: "<< b.genre() << '\n'
		<< "Availability: " << b.availability() << '\n'
		<< "ISBN: " << b.isbn() << '\n'
		<< "---------------------------------\n";
}

istream& operator>>(istream& is, Book& bb)
{
	string tt, aa;
	Genre gg{ Genre::default_genre };
	ISBN nn;
	bool availability;
	is >> nn >> tt >> aa >> availability;
	if (!is) return is;
	bb = Book(nn, tt, aa, gg, availability);
	return is;
}

// check if ISBN are same for two books
bool operator==(const Book& a, const Book& b)
{
	return a.isbn() == b.isbn();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

//--------------------------------------------------------------------------------

void Book::change_isbn(ISBN i)
{
	n = i;
}

void Book::change_title(string s)
{
	t = s;
}

void Book::change_author(string s)
{
	a = s;
}


