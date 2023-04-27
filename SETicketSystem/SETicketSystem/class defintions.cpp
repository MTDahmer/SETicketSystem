#include "User.h"
//#include <iostream>
//#include <string>
using namespace std;

User::User(string Name, int PhoneNumber, string Email)
	: Name(Name),
	Email(Email),
	PhoneNumber(PhoneNumber)
	
{}

Worker::Worker(string Name, int PhoneNumber, string Email)
	: User(Name,PhoneNumber,Email)
{
	
}
string getName()
{
	return Name;
}

/*string User::getName() {
	return m_Name;
}

void setName(string newName);
int getPhoneNumber();
void setPhoneNumber(int newNumber);
string getEmail(); */