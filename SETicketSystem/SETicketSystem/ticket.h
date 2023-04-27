//Ticket Class Header, Mitchell Dahmer, Written 4/18, 
//Header files that holds the ticket class along with related functions
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

	//Ticket Constructor, Mitchell Dahmer, Written 4/20
	// Constructor for tickets
	//
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
		//Ticket Class Text File Workaround, Mitchell Dahmer, Written 4/25
		//Text file creation function as work around for database integration. 
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

//ticket Information Grabber, Mitchell Dahmer, written 4/20
//Retreives information from the given ticket at the given entry in the ticket. each line corresponds to a constant location
//for specific information. For a key, see the ticketValueReplace function as the switch statement there corresponds to what
//line is used for which peice of data
string ticketValueGrab(int ticketID, int line) {
	ifstream requestedFile;
	fileName = "/Tickets/" + ticketID;
	requestedFile.open(fileName);
	string value;
	int count = 0;
	while (getline(requestedFile), value) {
		if (count == line) {
			value = value.substr(value.find(":") + 1);
			return value;
		}
		count++
	}
}

//ticket Information Replacer, Mitchell Dahmer, Written 4/20, edited 4/27
//Takes in new info for the purposes of updating the ticket. Limitations of text file operations in C++ require that the 
//File be completely rewritten rather than changing the singular line, so a function has been made to identify the needed
//change location, and begin replicating the file until the point is reached, at which time the new info is entered in and
// and the duplication continues next line
void ticketValueReplace(int ticketID, int line, string data) {
	ofstream requestedFile, newFile;
	fileName = "/Tickets/" + ticketID;
	tempFileName = "/Tickets/" + ticketID + "Temp";
	requestedFile.open(fileName);
	newFile.open(tempFileName);
	string value;
	int count;
	string prefix;
	switch (line) {
	case 0:
		prefix = "Title: ";
		break;
	case 1:
		prefix = "Customer: ";
		break;
	case 2:
		prefix = "Date Created: ";
		break;
	case 3:
		prefix = "Status: ";
		break;
	case 4:
		prefix = "Repaired Item: ";
		break;
	case 5:
		prefix = "Description: ";
		break;
	case 6:
		prefix = "Technician: ";
		break;
	case 7:
		prefix = "Subtickets: ";
		break;
	case 8:
		prefix = "Charges: ";
		break;
	case 9:
		prefix = "Work Entries: ";
		break;
	}
	while (getline(requestedFile), value) {
		if (count == line) {
			newFile << prefix << data;
		}
		else {
			newFile << value;
		}
		count++
	}
	fileName.close();
	old = fileName + "old";
	rename(fileName, old);
	rename(tempFileName, fileName);

}

//Description Change, Mitchell Dahmer, Written 4/18
//for taking in the new description as requested by user
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
//Change Push, Mitchell Dahmer, written 4/27
//for calling the various change function, getting the current values of what is being changed, 
//and pushing the new data when done
void pushChange(int ticketID, int line) {
	bool loop = true;
	int choice;
	string value;
	switch (line) {
	case 0:
		value = "Title";
		break;
	case 1:
		value = "Customer";
		break;
	case 2:
		value = "Date Created";
		break;
	case 3:
		value = "Status";
		break;
	case 4:
		value = "Repaired Item";
		break;
	case 5:
		value = "Description";
		break;
	case 6:
		value = "Technician";
		break;
	case 7:
		value = "Subtickets";
		break;
	case 8:
		value = "Charges";
		break;
	case 9:
		value = "Work Entries";
		break;
	}
	string currentDesc = ticketValueGrab(ticketID, line);
	cout << "Current " << value << " for Ticket " << ticketID << "\n" << currentDesc << "\n";
	while (loop) {
		string newDesc = changeDescription(currentDesc);
		cout << "New " << value << " for Ticket " << ticketID << "\n" << newDesc << "\n";
		while (loop) {
			cout << "Keep New " << value << " or Edit Again ? (1 for KEEP, 2 for EDIT)";
			cin << choice;
			if (choice == 2) {
				loop = true;
			}
			else if (choice == 1) {
				loop = false;
			}
			else {
				cout << "Invalid Selection \n";
				loop = true;
			}
		}
	}
	ticketValueReplace(ticketID, line, newDesc);
}

//Tech Change, Mitchell Dahmer, written 4/18
string changeTech(string tech) {
	string newTech;
	cout << "Enter the name of new techician being assigned to the ticket";
	cin >> newTech;

	return newTech;
}
//Status Change, Mitchell Dahmer, written 4/18
string changeStatus() {
	string newStatus;
	cout << "Please enter the new status";
	cin >> newStatus;
	return newStatus;
}
//Charge Creator, Mitchell Dahmer, written 4/18
charge callAddCharge(ticketID) {
	return charge;
}

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
#endif