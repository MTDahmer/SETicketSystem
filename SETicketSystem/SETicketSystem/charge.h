#pragma once
#ifndef charge
#define charge
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class charge {
private:
	string name;
	float price;
	string description;

	charge(ticketID) {
		cout << "Enter name of charge: \n";
		cin >> name;
		cout << "Enter the cost of the charge: \n";
		cin >> price;
		cout << "Enter a description of the charge \n";
		cin >> description;
		string currentCharges = ticketValueGrab(ticketID, 8);
		string newCharge = currentCharges + "[" + name + ", " + price + ", " + description + "], ";
		ticketValueReplace(ticketID, 8, newCharge);
	};

};


#endif