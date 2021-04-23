#include "std_lib_facilities.h"
#include "Chrono.h"
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
Book::Book(const ISBN& isbnnum, const string& title, const string& author, Genre genre, bool checked_out)
	: n{ isbnnum }, t{ title }, a{ author }, g{ genre }, chk_out{ checked_out }
{
}

// default Book constructor

Book::Book() : n{ ISBN() }, t{ "" }, a{ "" }, g{ Genre() }, chk_out{ false }{}


std::string availability(bool checked_out)
{
	if (checked_out)
		return "Unavailable";
	else
		return "Available";
}

ostream& operator<<(ostream& os, const Book& b)
{
	return os << "Title: " << b.title() << '\n'
		<< "Author: " << b.author() << '\n'
		<< "Genre: " << b.genre() << '\n'
		<< "Availability: " << availability(b.checked_out()) << '\n'
		<< "ISBN: " << b.isbn() << '\n';


}

// check if ISBN are same or not for two books
bool operator==(const Book& a, const Book& b)
{
	return a.isbn() == b.isbn();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

//--------------------------------------------------------------------------------
// Patron_name Constructor
Patron_name::Patron_name(const string& last_name, const string& initial_name)
	: l_name{ last_name }, i_name{ initial_name }
{
}
// Default Constructor
Patron_name::Patron_name() : l_name{ "Surname" }, i_name{ "Name" }
{
}

ostream& operator<<(ostream& os, const Patron_name& pn)
{
	return os << pn.last_name() << ", " << pn.initial_name() << ". ";
}

//--------------------------------------------------------------------------------
// Patron Constructor
Patron::Patron(const Patron_name& name, int card_num, double fees)
	:user_n{ name }, card_n{ card_num }, l_fees{ fees }
{
}
// Default Constructor
Patron::Patron() : user_n{ Patron_name() }, card_n{ 0 }, l_fees{ 0 }
{
}

ostream& operator<<(ostream& os, const Patron& p)
{
	return os << "Patron Name: " << p.name() << '\n'
		<< "Card Number: " << p.card_num() << '\n'
		<< "Outstanding Fees: $" << p.fees() << '\n';		
}

bool operator==(const Patron_name& a, const Patron_name& b)
{
	return a.last_name() == b.last_name();
}

bool operator!=(const Patron_name& a, const Patron_name b)
{
	return a.last_name() != b.last_name();
}

bool operator==(const Patron& a, const Patron& b)
{
	return a.name() == b.name()
		&& a.card_num() == b.card_num()
		&& a.fees() == b.fees();
}

bool operator!=(const Patron& a, const Patron& b)
{
	return a.name() != b.name()
		&& a.card_num() != b.card_num()
		&& a.fees() != b.fees();
}

//-------------------------------------------------------------------------------------------
//Transaction constructor
Library::Transaction::Transaction( const Book& book, const Patron& patron, Chrono::Date date)
	:trans_book{ book }, trans_patron{ patron }, trans_date{ date }
{
}

// Transactiom Default Constructor
Library::Transaction::Transaction() : trans_book{ Book() }, trans_patron{ Patron() }, trans_date{ Chrono::Date() }
{
}

ostream& operator<<(ostream& os, const Library::Transaction& t)
{
	return os << t.trans_book << '\n'
		<<  t.trans_patron << '\n'
		<< "Date: " << t.trans_date << "\n\n";		
}

//-------------------------------------------------------------------------------------------
// Library Constructor
Library::Library(const vector<Book>& b, const vector<Patron>& p, const vector<Transaction>& t)
	: books{ b }, patrons{ p }, transactions{ t }
{
}

// Library Default Constructor
const Library& default_library()
{
	vector<Book>books;
	vector<Patron>patrons;
	vector<Library::Transaction>transactions;

	static Library lib{ books,patrons,transactions };
	return lib;
}

Library::Library()
	: books{ default_library().v_get_books() },
	patrons{ default_library().v_get_patrons() },
	transactions{ default_library().v_get_transactions() }
{
}

//Library::Library() : books{  Book() }, patrons{  Patron() }, transactions{  Transaction() }
//{
//}

//--------------------------------------------------------------------------------
// Book class functions
void Book::check_out()
{
	if (checked_out()) error("already checked out");
	chk_out = true;
}

void Book::check_in()
{
	if (!checked_out()) error("already checked in");
	chk_out = false;
}

string Book::print_available()		// unused for now
{
	string available{ "Available" };
	string unavailable{ "Unavailable" };
	if (checked_out() == true) return available;
}

//----------------------------------------------------------------------------------
// Patron class functions
void Patron::set_fee(double fee)	//sets initial fee
{
	l_fees = fee;
}

void Patron::add_fee(double fee)	// add fees to account
{
	l_fees += fee;
}

bool Patron::check_fees()
{
	return l_fees > 0;
}

//----------------------------------------------------------------------------------
// Library class functions
void Library::add_book( const Book& b)		// add to books vector
{
	books.push_back(b);
}

void Library::add_patron( const Patron& p)	// add to patrons vector
{
	patrons.push_back(p);
}

void Library::add_transaction( const Library::Transaction& t)	// add to transactions vector
{
	
	transactions.push_back(t);
}

void Library::book_check_out( const Book& book, const Patron& patron, Chrono::Date date)
{
	
	bool book_found = false;
	bool no_fees = true;
	int booknum = 0;

	for (int i = 0; i < books.size(); ++i) {	// find vector index bumber of book
		if (book == books[i]) {
			booknum = i;
			book_found = true;
			break;
		}
	}
	if(!book_found) error("book_check_out() book not in library");

	if (books[booknum].checked_out()) error("book_check_out(): book is already checked out");	// if already checked out, error

	bool patron_found = false;
	int patron_num = 0;
	for (int i = 0; i < patrons.size(); ++i) {		// find patron
		if (patron.name() == patrons[i].name()) {
			patron_found = true;
			patron_num = i;
			break;
		}
	}
	if (!patron_found)error("book_check_out() patron not found.");

	if (patrons[patron_num].fees()) error("book_check_out() patron owes fees");	// check if patron owes fees

	transactions.push_back(Transaction(books[booknum], patrons[patron_num], date));		// add transactions to vector
	books[booknum].check_out();		// mark as checked out
	patrons[patron_num].add_fee(2);
}

void Library::book_check_in(const Book& book, const Patron& patron, Chrono::Date date)
{
	bool book_found = false;
	int booknum = 0;

	// find vector index bumber of book
	for (int i = 0; i < books.size(); ++i) {	
		if (book == books[i]) {
			booknum = i;
			book_found = true;
			break;
		}
	}
		
	bool patron_found = false;
	int patron_num = 0;
	// find patron
	for (int i = 0; i < patrons.size(); ++i) {		
		if (patron.name() == patrons[i].name()) {
			patron_found = true;
			patron_num = i;
			break;
		}
	}

	transactions.push_back(Transaction(books[booknum], patrons[patron_num], date));
	books[booknum].check_in();			// mark as checked in
	patrons[patron_num].set_fee(0);		//resets all fees to zero *not best solution for now.
}

void Library::delinquent_accounts()
{
	vector<Patron>del_accounts;
	for (int i = 0; i < patrons.size(); ++i) {
		if (patrons[i].fees() > 0) del_accounts.push_back(patrons[i]);
	}
	cout << "Delinquent accounts:\n";
	for (int i = 0; i < del_accounts.size(); ++i) {
		cout << del_accounts[i];
	}
}





