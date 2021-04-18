// book.h
#include "std_lib_facilities.h"

//--------------------------------------------------------------------------------

enum class Genre {
	default_genre=0, fiction, nonfiction, periodical, biography, children
};

//--------------------------------------------------------------------------------

struct ISBN {
    ISBN(int n1, int n2, int n3, char x);        // constructor
    ISBN();            // default constructor
    int n1;
    int n2;
    int n3;
    char x;	
};

ostream& operator<<(ostream& os, const ISBN& n);
istream& operator>>(istream& is, ISBN& nn);

//--------------------------------------------------------------------------------

class Book {
public:
	Book(ISBN isbnnum, string title, string author, Genre genre, bool availability);			// constructor
	Book();			// default constructor

	ISBN isbn() const { return n; }
	string title() const { return t; }
	string author() const { return a; }
	Genre genre() const { return g; }
	bool availability() const { return available; }
	void change_isbn(ISBN i);
	void change_title(string s);
	void change_author(string s);
	void check_in() { available = true; }
	void check_out() { available = false; }
	

private:
	ISBN n;			// book ISBN
	string t;		// book title
	string a;		// book author	
	Genre g;		// book genre
	bool available;	// book Check In/Out
};

ostream& operator<<(ostream& os, const Book& b);
istream& operator>>(istream& is, Book& bb);

//--------------------------------------------------------------------------------

class Patron_name {
public:
	Patron_name(string last_name, string initial_name);
	Patron_name();

	string last_name() const { return l_name; }
	string initial_name() const { return i_name; }
private:
	string l_name;
	string i_name;
};


class Patron { 
public:
	Patron(Patron_name name, int card_num, double fees);
	Patron();		// default constructor

	Patron_name name() const { return user_n; }
	int card_num() const { return card_n; }
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
istream& operator>>(istream& is, Patron_name& pn);

//--------------------------------------------------------------------------------

class Library {
public:

	struct Transaction {		

		Book trans_book;
		Patron trans_patron;
		Chrono::Date trans_date;

		Transaction(Book book, Patron patron, Chrono::Date date);
		Transaction();
	};

	Library(vector<Book>books, vector<Patron>patrons, vector<Transaction>transactions);
	Library();

	void add_book(const Book& b);
	vector<Book> get_books() const { return books; }

private:
	vector<Book>books;
	vector<Patron>patrons;
	vector<Transaction>transactions;
	
};

//--------------------------------------------------------------------------------
