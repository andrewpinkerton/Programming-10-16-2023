// Name: Andrew Pinkerton
// Program Description: Intro to Object Oriented Programming (OOP)
// Date: Oct 16, 2023

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person {
	// access modifiers: public, private, and protected
	// public: this is information (usually functions) that are accessible outside of the class
	// private: this is information (usually variables) that is accessible only inside of the class
	// protected: more on this later

public:


	person() // constructor
	{
		fName = "Tony";
		lName = "Tiger";
	}
	// anything is this section is publically available

	// to gain access to our variables, I will use what are called get and set functions
	// get functions return a value to main or another function
	// set functions set a value for our variables

	~person() // destructor
	{
		// nothing needs to go in here, it will delete everything by default
		// also, we do not need to create a destructor since the system will do it for us.


	}

	void setFirstName(string name)
	{
		fName = name;
	}
	void setLastName(string name)
	{
		lName = name;
	}
	string getFirstName()
	{
		return fName;
	}
	string getLastName()
	{
		return lName;
	}

private: 
	// anything in this section is private, and can only be accessed from within the class
	// we do this to restrict access to our variables so they can not be modified by accident
	string fName, lName;


};





int main()
{

	// make an instance of my class;
	vector<person> tb; // tb for taco bell
	string temp;

	for (int a = 0; a < 3; a++)
	{
		person info;

		cout << "Enter your first name: ";
		cin >> temp;
		info.setFirstName(temp);

		cout << "Enter your last name: ";
		cin >> temp;
		info.setLastName(temp);

		tb.push_back(info);
	}

	for (int a = 0; a < 3; a++)
	{
		cout << "Name: " << tb[a].getFirstName() << " " << tb[a].getLastName() << endl;
	}


	/*
	OOP is object oriented programming. This is a newer style of programming where code can be reused.
	
	OOP is made up of classes and objects

	Class - is a collection of related objects
	object - is a noun (person, place, or thing)

	Employment application - title (taco bell), you have fields, such as your name, address, 

	OOP allows us to initialize our variables automatically by using a constructor

	a cunstructor is a function that we create that we can put variables (others as well) that will
	automatically be called when the program starts

	destructor - this is a function that is automatically called to clear variable memory
	when they out of scope
	*/






}