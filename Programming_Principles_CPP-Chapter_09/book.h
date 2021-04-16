// book.h

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

class Patron { 
public:
	Patron(string name, int card_num, int fees);
	Patron();		// default constructor

	void get_user_name();
	void get_card_num();
	void get_fees();

private:
	string user_n;
	int card_n;
	int l_fees;
};
