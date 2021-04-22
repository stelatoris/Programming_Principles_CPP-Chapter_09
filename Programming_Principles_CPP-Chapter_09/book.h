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
istream& operator>>(istream& is, ISBN& nn);

//--------------------------------------------------------------------------------

class Book {
public:
	Book(ISBN isbnnum, string title, string author, Genre genre, bool checked_out);			// constructor
	Book();			// default constructor

	ISBN isbn() const { return n; }
	string title() const { return t; }
	string author() const { return a; }
	Genre genre() const { return g; }
	bool checked_out() const { return chk_out; }	// checkout status

	string print_available();
	void check_in();
	void check_out();	

private:
	ISBN n;			// book ISBN
	string t;		// book title
	string a;		// book author	
	Genre g;		// book genre
	bool chk_out;	// book Checked In/Out
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
	void add_patron(const Patron& p);
	void add_transaction(const Library::Transaction& t);
	void book_check_out(Book book, Patron patron, Chrono::Date date);
	void book_check_in(Book book, Patron patron, Chrono::Date date);
	void delinquent_accounts();
	

	vector<Book> v_get_books() const { return books; }
	vector<Patron> v_get_patrons() const { return patrons; }
	vector<Transaction> v_get_transactions() const { return transactions; }
	

private:
	vector<Book>books;
	vector<Patron>patrons;
	vector<Transaction>transactions;
	
};

ostream& operator<<(ostream& os, const Library::Transaction& t);
//--------------------------------------------------------------------------------
