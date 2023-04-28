#pragma once
#ifndef subticket
#define subticket
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

subticket(){
	int ticketid 
	int subticketid
	string additionalrepaired

	cout << "Enter the Main Ticket ID: \n"
		cin >> ticketid;
	cout << "Enter the Sub Ticket ID: \n"
		cin >> subticketid;
	time_t now = (0);
	datecreated = now;
	status = "Currently being worked on"
	cout << "Enter additional work needed: \n"
		cin >> additionalrepaired;
	ofstream newSubTicket;
	string ticketLocation = "/SubTickets/" + subticketid;

	newSubTicket.open(ticketLocation);
	newSubTicket << "Main Ticket ID: " << ticketid << "\n";
	newSubTicket << "SubTicketID: " << subticketid << "\n";
	newSubTicket << "Date Created: " << now << "\n";
	newSubTicket << "Status" << status << "\n";
	newSubTicket << "Additional work needed: " << additionalrepaired << "\n";
	
	string ticketValueGrab(int subticketid, int line) {
		ifstream requestedFile;
		fileName = "/SubTickets/" + subticketid;
		requestedFile.open(fileName);
		string value;
		int count = 0;
		while (getline(requestedFile), value) { 
			if (count == line) {
				value = value.substr(value.find(":") + 1);
				requestedFile.close(); 
				return value; 
			}
			count++
		}

		

};



#endif // !
