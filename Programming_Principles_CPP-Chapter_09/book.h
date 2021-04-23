// book.h
#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------

enum class Genre {
	default_genre=0, fiction, nonfiction, periodical, biography, children
};

//--------------------------------------------------------------------------------

struct ISBN {
    ISBN(int n1, int n2, int n3, char x);        // constructor e.g ISBN 2,3,4,x
    ISBN();            // default constructor
    int n1;
    int n2;
    int n3;
    char x;	
};

ostream& operator<<(ostream& os, const ISBN& n);
istream& operator>>(istream& is, const ISBN& nn);

//--------------------------------------------------------------------------------

class Book {
public:
	Book(const ISBN& isbnnum, const string& title, const string& author, Genre genre, bool checked_out);			// constructor
	Book();			// default constructor

	const ISBN& isbn() const { return n; } //This is a getter function. It returns ISBN member variable.
	const string& title() const { return t; } //This is also a getter function. It returns title member variable
	const string& author() const { return a; } //This is also a getter function. It returns author member variable.
	Genre genre() const { return g; }          // This is also a getter function. It returns genre member variable. The reason why it returns by value is because enum class implicitly converts to int
											   // Remember, there is no overhead for small built-in types (char, float, bool, int, float, short, double)
	bool checked_out() const { return chk_out; }	// Also a getter. 

	string print_available(); //Not a getter function
	void check_in();  //Not a getter function
	void check_out();  //Not a getter function

private:
	ISBN n;			// book ISBN
	string t;		// book title
	string a;		// book author	
	Genre g;		// book genre
	bool chk_out;	// book Checked In/Out
};

ostream& operator<<(ostream& os, const Book& b);

//--------------------------------------------------------------------------------

class Patron_name {
public:
	Patron_name(const string& last_name, const string& initial_name);
	Patron_name();

	const string& last_name() const { return l_name; }
	const string& initial_name() const { return i_name; }
private:
	string l_name;
	string i_name;
};


class Patron { 
public:
	Patron(const Patron_name& name, const int card_num, double fees);
	Patron();		// default constructor

	const Patron_name& name() const { return user_n; }
	const int card_num() const { return card_n; }
	double fees() const { return l_fees; }
	
	bool check_fees();
	
	void set_fee(double fee);
	void add_fee(double fee);


private:
	Patron_name user_n;
	int card_n;
	double l_fees;
};

ostream& operator<<(ostream& os, const Patron& p);
ostream& operator<<(ostream& os, const Patron_name& pn);

//--------------------------------------------------------------------------------

class Library {
public:

	struct Transaction {		

		Book trans_book;
		Patron trans_patron;
		Chrono::Date trans_date;

		Transaction(const Book& book, const Patron& patron, Chrono::Date date);
		Transaction();
	};

	Library(const vector<Book>& books, const vector<Patron>& patrons, const vector<Transaction>& transactions);
	Library();

	void add_book(const Book& b);
	void add_patron(const Patron& p);
	void add_transaction(const Library::Transaction& t);
	void book_check_out(const Book& book, const Patron& patron, Chrono::Date date);
	void book_check_in(const Book& book, const Patron& patron, Chrono::Date date);
	void delinquent_accounts();
	

	const vector<Book>& v_get_books() const { return books; }
	const vector<Patron>& v_get_patrons() const { return patrons; }
	const vector<Transaction>& v_get_transactions() const { return transactions; }
	

private:
	vector<Book>books;
	vector<Patron>patrons;
	vector<Transaction>transactions;
	
};

ostream& operator<<(ostream& os, const Library::Transaction& t);
//--------------------------------------------------------------------------------
