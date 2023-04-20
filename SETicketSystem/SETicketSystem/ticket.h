#pragma once
#ifndef ticket
#define ticket
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
class ticket {
private:
	int ticketID;
	std::string title;
	std::string customer;
	std::string dateCreated;
	std::string repairedItem;


public:
	std::string status;
	std::string description;
	std::vector <std::string> subticketList;
	std::string technician;
	std::vector < std::string> workentryList;
	std::vector < std::string> charges;

	ticket() {
		std::cout << "Enter title of ticket: \n";
		std::cin >> title;
		std::cout >> "Enter a brief description of the issue: \n";
		std::cin >> description;
		std::cout >> "Enter the name of the client: \n";
		time_t now = time(0);
		dateCreated = now;
		ticketID = ticketIDGenerator(now, client);
		std::cout << "Enter a description of the item to be repaired: \n";
		std::cin >> repairedItem;
		status = "Awaiting Assignment";
		//Storeticket function
	}

};

//+callSubticketCreation() for calling the subticket creation process, leaving as psuedo until subticket is made
//void callSubticketCreation(ticketID) {
//	string newSubTicket = subticketCreation(ticketID);
//	subticketList.append(newSubticket)
//}
//+ callUpdateCustomer() for calling update customer function, leaving as psuedo until subticket is made
//Void callUpdateCustomer(customer) {
//	updateCustomer(customer)
//}
//+ callAppendWork() for calling append work function, leaving as psuedo until subticket is made
//Void callAppendWork(ticketID) {
//	appendWork(ticketID)
//}
//+ changeDescription()
std::string changeDescription(std::string description) {
	std::cout << "Edit current description or append statement? \n 1. Append \n 2. Edit \n";
	int choice;
	std::string newDesc;
	std::cin >> choice;
	bool loop = true;
	while (loop) {
		if (choice == 1) {
			std::cout << "Please enter the statement to append to the current description \n";
			std::cin >> newDesc;
			description = description + newDesc;
			return description;
		}
		else if (choice == 2) {
			std::cout << description;
			std::cout << "Please enter a new description";
			std::cin >> newDesc;
			return newDesc;
		}
		else {
			std::cout << "Invalid Selection. Please only enter the numbers listed as options";
		}
	}
}
//+ changeTech()
std::string changeTech(std::string tech) {
	std::string newTech;
	std::cout << "Enter the name of new techician being assigned to the ticket";
	std::cin >> newTech;
	/*Following segment waiting for others first
	Check if tech exists
	If tech doesn't exist  {
	Display “Invalid Tech”
	Repeat prompt*/
	return newTech;
}
//+ changeStatus() update the status of the ticket
std::string changeStatus() {
	std::string newStatus;
	std::cout << "Please enter the new status";
	std::cin >> newStatus;
	return newStatus;
}
//+ callAddCharge()
chargeObject callAddCharge(ticketID) {
	addCharge(ticketID)
}


#endif