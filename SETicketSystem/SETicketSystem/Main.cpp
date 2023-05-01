/*Main CPP files, this will be where the code responsible for
calling the other classes and running the program will be, all classes
made for this application should be written as headers and refrenced here
when needed. This way all classes will exist as seperate objects*/

#include <iostream>
#include <string>
#include "externalUI.h"
#include "internalUI.h"
using namespace std;

int main() {
	int userChoice, userID, reqTicket;
	bool loop;
	cout << "Welcome to the Placeholder Repair Shop ticketing system! \n";
	while (loop) {
		cout << "Please select what role to login as : \n 1. Administrator \n 2. Technician \n 3. Customer \n Enter 0 to exit";
		cin >> userChoice;
		if (userChoice == 0) {
			cout << "Have a nice day!";
			loop = false;
		}
		else if (userChoice == 1) {
			cout << "Please enter your administrator ID \n";
			cin >> userID;
			if (userVerify(userChoice, userID)) {
				administratorMenu();
			}
			else {
				cout << "Invalid Administrator ID \n";
				loop = true;
			}
		}
		else if (userChoice == 2) {
			cout << "please enter your Technician ID \n";
			cin >> userID;
			if (userVerify(userChoice, userID)) {
				technicianMenu(userID);
			}
			else {
				cout << "Invalid Technician ID \n";
				loop = true;
			}
		}
		else if (userChoice == 3) {
			cout << "please enter your Customer ID \n";
			cin >> userID;
			if (userVerify(userChoice, userID)) {
				customerMenu();
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