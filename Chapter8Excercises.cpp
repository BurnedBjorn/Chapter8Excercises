// Chapter8Excercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

class Name_pairs
{
public:
	Name_pairs();
	~Name_pairs();
	void read_names();
	void read_ages();
	void print();
	void sort_name_age();
private:
	vector<string> name;
	vector<double> age;
};

Name_pairs::Name_pairs()
{
	read_names();
	read_ages();
	sort_name_age();
	print();
}

Name_pairs::~Name_pairs()
{
	cout << "k bye";
}
void Name_pairs::read_names() {
	cout << "input names, separate by enter. to finish input write ';'\n>";
	string input;
	while (cin>>input)
	{
		if (input != ";")
		{
			name.push_back(input);
			cout << ">";
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

int main()
{
	Name_pairs np;
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
