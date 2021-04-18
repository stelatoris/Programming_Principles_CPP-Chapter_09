#include "std_lib_facilities.h"

// type for (name,age) pairs
class Name_pairs {		
public:
	void read_names();	// reads a series of names
	void read_ages();	// prompt user for age for each name
	void print();		// print out name and age pairs
	void sort();		// sorts name vector alphabetically with matching age vector
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
		while (cin >> a) {
			if (a == string) {
				cout << "Please enter a number";
			}
			else {
				age.push_back(a);
				break;
			}
		}

		
	}
	cout << "Thank you.\n";
}

// sort name vector alphabetically, with matching age vector
void Name_pairs::sort()
{
	if (name.size() != age.size())
		error("sort(): name and age must be the same size");
	vector<string>temp_name;
	vector<double>temp_age;
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
	if (name.size() != age.size())
		error("print(): name and age must be the same size");
	cout << "Names entered:\n";
	for (int i = 0; i < name.size(); ++i) {
		if(i==name.size()-1) cout <<'('<< name[i] <<','<<age[i]<<')'<< "\nEnd.";
		else cout << '(' << name[i] << ',' << age[i] << ")\n";		
	}
}

int main()
try {

	Name_pairs names;
	names.read_names();
	names.read_ages();
	names.print();

	names.sort();
	names.print();

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
