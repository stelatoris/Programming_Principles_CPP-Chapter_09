// Chapter 09, exercise 02: Name_pairs class
//2. Design and implement a Name_pairs class holding(name, age) pairs where
//name is a string and age is a double.Represent that as a vector<string>
//(called name) and a vector<double>(called age) member.Provide an input
//operation read_names() that reads a series of names.Provide a read_
//ages() operation that prompts the user for an age for each name.Provide
//a print() operation that prints out the(name[i], age[i]) pairs(one per line)
//in the order determined by the name vector.Provide a sort() operation
//that sorts the name vector in alphabetical orderand reorganizes the age
//vector to match.Implement all “operations” as member functions.Test
//the class (of course : test early and often).
//3. Replace Name_pair::print() with a(global) operator << and define ==
//and != for Name_pairs.


#include "std_lib_facilities.h"

// type for (name,age) pairs
class Name_pairs {		
public:
	void read_names();	// reads a series of names
	void read_ages();	// prompt user for age for each name
	void print();		// print out name and age pairs
	void sort();		// sorts name vector alphabetically with matching age vector
	const vector<string>& get_name() const { return name; }		// to access name and age vectors from ostream << operator
	const vector<double>& get_age() const { return age; }		// to access name and age vectors from ostream << operator
private:
	vector<string>name;
	vector<double>age;
};

// reads a series of names
void Name_pairs::read_names()
{
	string n;	
	cout << "Enter names, 'noname' to finish:\n";
	while (cin>>n && n != "noname") {
		bool name_exists = false;
		for (int i = 0; i < name.size(); ++i) {
			if (n == name[i]) {
				cout << "Name already exists.\n";
				name_exists = true;
			}
		}
		if(!name_exists) name.push_back(n);
	}
}

// prompt user for age for each name
void Name_pairs::read_ages()
{
	int a;
	cout << "Enter the age for each name:\n";
	for (int i = 0; i < name.size(); ++i) {
		cout << name[i] << ": ";
		cin >> a;
		age.push_back(a);	
	}
	cout << "Thank you.\n\n";
}

// sort name vector alphabetically, with matching age vector
void Name_pairs::sort()
{
	if (name.size() != age.size())		//check if both vectors are same size
		error("sort(): name and age must be the same size");
	vector<string>temp_name;		// copy name vector to keep original order
	vector<double>temp_age;			// copy age vector to keep original order
	temp_name = name;
	temp_age = age;
	std::sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); ++i) {
		for (int ii = 0; ii < temp_name.size(); ++ii) {
			if (name[i] == temp_name[ii]) {
				age[i] = temp_age[ii];
			}
		}
	}
}

// print out name and age pairs
void Name_pairs::print()
{
	if (name.size() != age.size())	//check if both vectors are same size
		error("print(): name and age must be the same size");
	cout << "Names entered:\n";
	for (int i = 0; i < name.size(); ++i) {
		if(i==name.size()-1) cout <<'('<< name[i] <<','<<age[i]<<')'<< "\nEnd.";
		else cout << '(' << name[i] << ',' << age[i] << ")\n";		
	}
}

// define how to print Name_pairs class when using cout<<
ostream& operator<<(ostream& os, const Name_pairs& np)
{
	if(np.get_name().size() != np.get_age().size()) error("<<: name and age must be the same size");

	for (int i = 0; i < np.get_name().size(); ++i) {
		if (i == np.get_name().size() - 1) cout << '(' << np.get_name()[i] << ',' << np.get_age()[i] << ')' << "\nEnd.\n\n";
		else cout << '(' << np.get_name()[i] << ',' << np.get_age()[i] << ")\n";
	}
	return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	if (a.get_name().size() != b.get_name().size() || a.get_age().size() != b.get_age().size()) return false;

	for (int i = 0; i < a.get_name().size(); ++i) {
		if (a.get_name()[i] != b.get_name()[i]) return false;
	}
	for (int i = 0; i < a.get_age().size(); ++i) {
		if (a.get_age()[i] != b.get_age()[i]) return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}

int main()
try {

	Name_pairs names;
	names.read_names();
	names.read_ages();
	cout << names;

	names.sort();
	cout << names;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}