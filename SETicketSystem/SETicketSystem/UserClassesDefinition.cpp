/*#include "User.h"
//#include <iostream>
//#include <string>
using namespace std;


//User initialization and assosciated functions for Users

User::User(string Name, int PhoneNumber, string Email)
	: Name(Name),
	Email(Email),
	PhoneNumber(PhoneNumber)

{}

//getter for user NAME
string User::getName() const {
	return Name;
}

//setter for user NAME
void User::setName(string newName)
{
	Name = newName;
}

//getter for user PhoneNumber
int User::getPhoneNumber()
{
	return PhoneNumber;
}

//setter for user Phonenumber
void User::setPhoneNumber(int newNumber)
{
	PhoneNumber = newNumber;
}

//getter for Email
string User::getEmail()
{
	return Email;
}

//setter for Email
void User::setEmail(string newEmail)
{
	Email = newEmail;
}


//Worker   initialization and assosciated functions for Users



Worker::Worker(string Name, int PhoneNumber, string Email)
	: User(Name,PhoneNumber,Email)
{

}
//Name getter for Worker
string Worker::getName()
{
	return User::getName();
}
//Name setter for Worker
void  Worker::setName(string newName)
{
	User::setName(newName);
}

//PhoneNumber getter for Worker
int Worker::getPhoneNumber()
{
	return User::getPhoneNumber();
}

//PhoneNumber setter for Worker
void Worker::setPhoneNumber(int newNumber)
{
	User::setPhoneNumber(newNumber);
}

//email getter for Worker

string Worker::getEmail()
{
	return User::getEmail();
}

//email setter for Worker
void Worker::setEmail(string newEmail)
{
	User::setEmail(newEmail);
}

 /*Repair technician section

RepairTechnician::RepairTechnician(string Name, int PhoneNumber, string Email, int TechnicianID, int TechnicianActiveTickets)
	: User(Name, PhoneNumber, Email)
{

}*/

#include "UserClassesv2.h"
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

string WhatTypeofUser()
{
	string TypeOfUser;
	string y = "y";
	string n = "n";
	cout << "Are you an administrator? y/n\n";
	cin >> TypeOfUser;
	if (TypeOfUser == y) {
		TypeOfUser = "Administrator";
		return TypeOfUser;
	}
	else
	{
		cout << "Are you an technician? y/n\n";
		cin >> TypeOfUser;

		if (TypeOfUser == y)
		{
			TypeOfUser = "Technician";
			return TypeOfUser;
		}
		else
		{
			cout << "Are you an customer? y/n\n";
			cin >> TypeOfUser;

			if (TypeOfUser == y)
			{
				TypeOfUser = "Customer";
				return TypeOfUser;

			}
			else {
				TypeOfUser = "not found";
				return TypeOfUser;
			}
		}
	}
}

string NameofUser()
{
	string NameofUser;
	cout << "What is your name ? \n";
	cin >> NameofUser;
	return NameofUser;
}
int getNextEmployeeID() {
	std::ifstream inputFile("ID counter.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Error: Failed to open file 'ID counter.txt'" << std::endl;
		return -1;
	}

	string idString;
	getline(inputFile, idString); // Read the current ID from the file
	inputFile.close();

	int id = stoi(idString); // Convert the ID string to an integer
	++id; // Increment the ID

	std::ofstream outputFile("ID counter.txt");
	if (!outputFile.is_open()) {
		std::cerr << "Error: Failed to open file 'ID counter.txt'" << std::endl;
		return -1;
	}

	outputFile << id << std::endl; // Write the new ID to the file
	outputFile.close();

	return id;
}

void EnterANewUser(string(*f)(), string(*g)(), int(*h)())
{

	string ID;
	string ActiveTickets;

	string type = f();
	string name = g();
	int newID = h();
	//when calling in main use EnteraNewUsername(WhatTypeofUser,NameofUser)
	//get the return of type and name so we can put into a text file
	//start of making text file
	ofstream newUser;
	if (type == "Administrator")
	{
		string UserLocation = "/Administrator/" + newID;
		newUser.open(UserLocation);
	}
	else
	{
		if (type == "Technician")
		{
			string UserLocation = "/Technician/" + newID;
			newUser.open(UserLocation);
			newUser << "Active Tickets: \n";
		}
		else
		{
			if (type == "Customer")
			{
				string UserLocation = "/Customer/" + newID;
				newUser.open(UserLocation);
			}
		}
	}
	newUser << "System ID: " << newID << "\n";
	newUser << "Name: " << name << "\n";

	newUser.close();
}

/*void AdminPermission(int ticketID, string name)
{
	ifstream requestedFile;
	string fileName = "/Administrator/" + ticketID;
	// convert ticketID to string or convert string into INT
	requestedFile.open(fileName);
	string TempHold;
	string ticketID_string = to_string(ticketID);
	int count = 0;
	while (getline(requestedFile, TempHold))
	{
		if (count == 0) {
			if

		}
	}
}*/

