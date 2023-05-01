//Charge Creation Function, Written by Mitchell Dahmer, 4/27
//Creates a new charge, formats it and combines it with the old charge list, then it sends the 
//the information to the value replace function which puts the new list into the ticket
#include "ticket.h"
#include "charge.h"
using namespace std;

void createCharge(int ticketID) {
	string name, price, description;
	cout << "Enter name of charge: \n";
	cin >> name; //takes in name
	cout << "Enter the cost of the charge: \n";
	cin >> price; //takes in price
	cout << "Enter a description of the charge \n";
	cin >> description; //takes in description
	string currentCharges = ticketValueGrab(ticketID, 8); //gets the current list of charges from the requested ticket
	string newCharge = currentCharges + "[" + name + ", " + price + ", " + description + "], "; //adds the new charge to the charge list while formatting it
	ticketValueReplace(ticketID, 8, newCharge); //Sends new charge list to the replace function for the ticket requested
};