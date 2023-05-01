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

#include "user.h"

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
		newUser << "System ID: " << newID << "\n";
		newUser << "Name: " << name << "\n";
	}
	else
	{
		if (type == "Technician")
		{
			string UserLocation = "/Technician/" + newID;
			newUser.open(UserLocation);
			newUser << "System ID: " << newID << "\n";
			newUser << "Name: " << name << "\n";
			newUser << "Active Tickets: \n";
		}
		else
		{
			if (type == "Customer")
			{
				string UserLocation = "/Customer/" + newID;
				newUser.open(UserLocation);
				newUser << "System ID: " << newID << "\n";
				newUser << "Name: " << name << "\n";
			//fix this, need ticketID or atleast set to 0	newUser << "TicketID: " << TicketID << "\n";
			}
		}
	}
	

	newUser.close();
}

void UserValueReplace(string userChoice,int UserID, int line, string data) {
	ifstream requestedFile;
	ofstream newFile;
	const string userChoiceVariable = userChoice;
	string fileName = "C:\\" + userChoiceVariable + "\\" + to_string(UserID);
	string tempFileName = fileName + "Temp";
	string fileName1 = fileName + ".txt";
	tempFileName = tempFileName + ".txt";
	requestedFile.open(fileName1); //opens the current file being requested
	newFile.open(tempFileName); // creates a new temporary file with a name similar to the other one for information to be copied to
	string value;
	int count = 0;
	string prefix;
	switch (line) {
	case 0:
		prefix = "SystemID ";
		break;
	case 1:
		prefix = "Name ";
		break;
	case 2:
		prefix = "ActiveTickets ";
		break;
	}
	while (getline(requestedFile, value)) { //begins reading loop for the files line by line
		if (count == line) { //Calls if its the line we are looking for
			newFile << prefix << data << "\n"; //writes the prefix decided earlier and the new information to the file
		}
		else {
			newFile << value << "\n"; //Writes whatever the current value read from the files is to the same position in the file
		}
		count++; //ups the count for tracking purposes
	};
	requestedFile.close();
	newFile.close();//closes old file
	string old = fileName + "old";
	old = old + ".txt";//sets up name for files removal
	const char* oldChar = old.c_str();
	const char* tempChar = tempFileName.c_str();
	const char* currentChar = fileName1.c_str();
	rename(currentChar, oldChar); //renames the old file to indicate that its been deprecated, doubles as a handy change tracking system for the software
	rename(tempChar, currentChar); //renames new file to match old file to transition is to being the default file
	remove(oldChar); //Deletes old file
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
bool userVerify(string userChoice, int userID)//do this 
{
	 {
		string fileName = "C:\\" + userChoice + "\\" + to_string(userID);
		ifstream file(fileName);
		return file.good();
	}
}

void DeleteEmployee(int userID, string userChoice)
{

}