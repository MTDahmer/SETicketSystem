#pragma once
#ifndef ticket
#define ticket
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "charge.h"

using namespace std;
class ticket {
private:
	int ticketID;
	string title;
	string customer;
	string dateCreated;
	string repairedItem;


public:
	string status;
	string description;
	vector <string> subticketList;
	string technician;
	vector < string> workentryList;
	vector < string> charges;

	ticket() {
		cout << "Enter title of ticket: \n";
		cin >> title;
		cout >> "Enter a brief description of the issue: \n";
		cin >> description;
		cout >> "Enter the name of the customer: \n";
		cin >> customer;
		time_t now = time(0);
		dateCreated = now;
		ticketID = ticketIDGenerator(now, client);
		cout << "Enter a description of the item to be repaired: \n";
		cin >> repairedItem;
		status = "Awaiting Assignment";
		//Storeticket function as work around for database integration. 
		//stores the values of the ticket into a text file to be refrenced later
		ofstream newTicket;
		string ticketLocation = "/Tickets/" + ticketID;
		newTicket.open(ticketLocation);
		newTicket << "Title: " << title << "\n";
		newTicket << "Customer: " << customer << "\n";
		newTicket << "Date Created: " << now << "\n";
		newTicket << "Status" << status << "\n";
		newTicket << "Repaired Item: " << repairedItem << "\n";
		newTicket << "Description: " << description << "\n";
		newTicket << "Technician: \n";
		newTicket << "Subtickets: \n";
		newTicket << "Charges: \n";
		newTicket << "Work Entries: \n";
	}

};

//+callSubticketCreation() for calling the subticket creation process, leaving as psuedo until subticket is made
void callSubticketCreation(ticketID) {
	string newSubTicket = subticketCreation(ticketID);
	subticketList.append(newSubticket);
}
//+ callUpdateCustomer() for calling update customer function, leaving as psuedo until subticket is made
void callUpdateCustomer(customer) {
	updateCustomer(customer)
}
//+ callAppendWork() for calling append work function, leaving as psuedo until subticket is made
void callAppendWork(ticketID) {
	appendWork(ticketID)
}
//+ changeDescription()
string changeDescription(string description) {
	cout << "Edit current description or append statement? \n 1. Append \n 2. Edit \n";
	int choice;
	string newDesc;
	cin >> choice;
	bool loop = true;
	while (loop) {
		if (choice == 1) {
			cout << "Please enter the statement to append to the current description \n";
			cin >> newDesc;
			description = description + newDesc;
			return description;
		}
		else if (choice == 2) {
			cout << description;
			cout << "Please enter a new description";
			cin >> newDesc;
			return newDesc;
		}
		else {
			cout << "Invalid Selection. Please only enter the numbers listed as options";
		}
	}
}
//+ changeTech()
string changeTech(string tech) {
	string newTech;
	cout << "Enter the name of new techician being assigned to the ticket";
	cin >> newTech;
	/*Following segment waiting for others first
	Check if tech exists
	If tech doesn't exist  {
	Display “Invalid Tech”
	Repeat prompt*/
	return newTech;
}
//+ changeStatus() update the status of the ticket
string changeStatus() {
	string newStatus;
	cout << "Please enter the new status";
	cin >> newStatus;
	return newStatus;
}
//+ callAddCharge()
chargeObject callAddCharge(ticketID) {
	addCharge(ticketID)
}
#endif