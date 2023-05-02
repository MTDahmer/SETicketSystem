/*Main CPP files, this will be where the code responsible for
calling the other classes and running the program will be, all classes
made for this application should be written as headers and refrenced here
when needed. This way all classes will exist as seperate objects*/

//need subticket expansion for menus, make all user refrences id's, not string names

#include <iostream>
#include <string>
#include "externalUI.h"
#include "internalUI.h"
#include "user.h"
using namespace std;

int main() {
	int userChoice, userID;
	string jobType;
	bool loop = true;
	cout << "Welcome to the Placeholder Repair Shop ticketing system! \n";
	while (loop) { //Starts input validation loop
		cout << "Please select what role to login as : \n 1. Administrator \n 2. Technician \n 3. Customer \n Enter 0 to exit \n";
		cin >> userChoice; //Takes user's login choice
		if (userChoice == 0) { //Exits loop
			cout << "Have a nice day!";
			loop = false;
		}
		else if (userChoice == 1) { //Administrator Login Verify
			cout << "Please enter your administrator ID \n";
			cin >> userID;
			jobType = "Administrator";
			if (userVerify(jobType, userID)) { //Calls Verify
				administratorMenu(); //If verify passes, open the menu
			}
			else {
				cout << "Invalid Administrator ID \n";
				loop = true;
			}
		}
		else if (userChoice == 2) {//Technician Login Verify
			cout << "please enter your Technician ID \n";
			cin >> userID;
			jobType = "Technician";
			if (userVerify(jobType, userID)) {
				technicianMenu(userID);
			}
			else {
				cout << "Invalid Technician ID \n";
				loop = true;
			}
		}
		else if (userChoice == 3) {// Customer Login Verify
			cout << "please enter your Customer ID \n";
			cin >> userID;
			jobType = "Customer";
			if (userVerify(jobType, userID)) {
				customerMenu(userID);
			}
			else {
				cout << "Invalid Customer ID \n";
				loop = true;
			}
		}
		else {
			cout << "Invalid Selection \n";
			loop = true;
		}
	}
}