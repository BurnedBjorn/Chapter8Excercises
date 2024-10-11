// Chapter8Excercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

class Name_pairs2 {
public:
	Name_pairs2();
	struct Name_pair
	{
		string name;
		double age = 0;
		Name_pair(string n, double d) :name{ n }, age{ d } {};
		Name_pair(string n) :name{ n }, age{ 0 } {};
		bool operator<(const Name_pair& pair) const
		{
			return (name + to_string(age)) < (pair.name + to_string(pair.age));
		}

		
	};
	void read_names();
	void read_ages();
	void sort_pairs();
	vector<Name_pair> get_pairs()const { return pairs; }
private:
	vector<Name_pair> pairs;
	
};
Name_pairs2::Name_pairs2()
{
	read_names();
	read_ages();
	sort_pairs();
}
void Name_pairs2::read_names()
{
	cout << "input names, separate by enter. to finish input write ';'\n>";
	string input;
	while (cin >> input)
	{
		if (input != ";")
		{
			pairs.push_back(input);
			cout << ">";
		}
		else {
			return;
		}
	}
}

void Name_pairs2::read_ages()
{
	cout << "now input age for each name\n";
	
	double input;
	for (int i = 0; i < pairs.size(); i++)
	{
		cout << pairs[i].name << ": ";
		cin >> input;
		while (!cin.good())
		{
			cout << "bad input\n" << pairs[i].name << ": ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> input;
		}
		pairs[i].age = input;

	}
}

void Name_pairs2::sort_pairs() {
	sort(pairs.begin(), pairs.end());
}
ostream& operator<<(ostream& os, const Name_pairs2& np2) {
	for (int i = 0; i < np2.get_pairs().size(); i++)
	{
		os << "name: " << np2.get_pairs()[i].name << ", age: " << np2.get_pairs()[i].age << endl;
	}
	return os;
}
/*
class Name_pairs
{
public:
	Name_pairs();
	~Name_pairs();
	void read_names();
	void read_ages();
	void print();
	void sort_name_age();
	vector<string> name;
	vector<double> age;
private:
	
};

Name_pairs::Name_pairs()
{
	read_names();
	read_ages();
	sort_name_age();
	
}

Name_pairs::~Name_pairs()
{
	cout << "k bye ";
}
void Name_pairs::read_names() {
	cout << "input names, separate by enter. to finish input write ';'\n>";
	string input;
	while (cin>>input)
	{
		if (input != ";")
		{
			bool repeats = false;
			for (int i = 0; i < name.size(); i++)
			{
				if (input == name[i]) { repeats = true; }
			}
			if (repeats) { cout << "name already in database, try another one\n>";}
			else {
				name.push_back(input);
				cout << ">";
			}
		}
		else {
			return;
		}
	}
}
void Name_pairs::read_ages() {
	cout << "now input age for each name\n";
	double input;
	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] << ": ";
		cin >> input;
		while (!cin.good())
		{
			cout<<"bad input\n" << name[i] << ": ";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> input;
		}
		age.push_back(input);

	}
}
void Name_pairs::print() {
	for (int i = 0; i < name.size(); i++)
	{
		cout << "name: " << name[i] << ", age: " << age[i]<<endl;
	}
}
void Name_pairs::sort_name_age() {
	vector<string> name_orig = name;
	vector<double> age_orig = age;
	sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); i++)
	{
		for (int ii = 0; ii < name_orig.size(); ii++)
		{
			if (name[i]==name_orig[ii])
			{
				age[i] = age_orig[ii];
				
			}
		}
	}
}
ostream& operator<<(ostream& os, Name_pairs np) {
	for (int i = 0; i < np.name.size(); i++)
	{
		os << "name: " << np.name[i] << ", age: " << np.age[i] << endl;
	}
	return os;
}
*/
int main()
{
	Name_pairs2 np2;
	cout << np2;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
