#include "InternalUI.h"

void administratorMenu() {
	bool loop = true;
	int userChoice;
	while (loop) {
		cout << "What would you like to do? (enter -1 to exit) \n";
		cout << "0. View User \n";
		cout << "1. Assign Technician to ticket \n";
		cout << "2. Edit ticket values directly\n";
		cout << "3. View ticket\n";
		cout << "4. Create Subticket \n";
		cout << "5. Create Technician User\n";
		cout << "6. Create Customer User \n";
		cout << "7. Create Administrator User \n";
		cout << "8. Fire Technician \n";
		cout << "9. Create Ticket \n";
		cin >> userChoice;
		if (userChoice == -1) {
			loop = false;
		}
		else if (userChoice == 0) {	
			int jobNumber, userID0;
			bool loop0 = true;
			while (loop0) {
				cout << "Please select what type of user to view \n 1. Administrator \n 2. Technician \n 3. Customer";
				cin >> jobNumber;
				cout << "Please enter the ID of the user you are looking for \n";
				cin >> userID0;
				try {
					showUserFile(jobNumber, userID0);
					loop0 = false;
				}
				catch (...) {
					cout << "Invalid Selection \n";
				}
			}
		}
		else if (userChoice == 1) {
			bool(loop1) = true;
			int ticketID1, userID1;
			while (loop1) {
				try {
					string NewTech;
					cout << "Please enter the ID of the ticket you wish to assign a technician to \n";
					cin >> ticketID1;
					pushChange(ticketID1, 6);
					cout << "Please enter the ID of the user assigned";
					cin >> userID1;
					UserValueReplace(userID1, 2, ticketID1);
					loop1 = false;
				}
				catch (...) {
					cout << "Invalid TicketID or UserID";
				}

			}
		}
		else if (userChoice == 2) {
			bool(loop2) = true;
			int ticketID2, line;
			while (loop2) {
				string NewTech;
				int ticketID;
				cout << "Please enter the ID of the ticket you wish to assign a technician to \n";
				cin >> ticketID;
				cout << "What value would you like to edit? \n";
				cout << "0.Title \n 1. Customer \n 2. Date Created \n 3. Status \n 4. Repaired Item \n 5. Description \n 6. Technician \n 7. Subtickets \n 8. Charges \n 9. Work Entries ";
				try {
					cin >> line;
					pushChange(ticketID, line);
					loop2 = false;
				}
				catch (...) {
					cout << "Invalid Ticket or Edit choice";
				}
			}
		}
		else if (userChoice == 3) {
			int ticketID3;
			bool loop3 = true;
			while (loop3) {
				cout << "Please enter the ticket ID that you would like to check " << endl;
				cin >> ticketID3;
				cout << "Ticket " << ticketID3 << endl;
				try {
					cout << "Title:" << ticketValueGrab(ticketID3, 0);
					cout << "Customer:" << ticketValueGrab(ticketID3, 1);
					cout << "Date Created:" << ticketValueGrab(ticketID3, 2);
					cout << "Status:" << ticketValueGrab(ticketID3, 3);
					cout << "Repaired Item:" << ticketValueGrab(ticketID3, 4);
					cout << "Description:" << ticketValueGrab(ticketID3, 5);
					cout << "Technician:" << ticketValueGrab(ticketID3, 6);
					cout << "Subtickets:" << ticketValueGrab(ticketID3, 7);
					cout << "Charges:" << ticketValueGrab(ticketID3, 8);
					cout << "Work Entries:" << ticketValueGrab(ticketID3, 9);
					loop3 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID, please try again";
				}
			}
		}
		else if (userChoice == 4) {
			createSubticket();
		}
		else if (userChoice == 5) {}
		else if (userChoice == 6) {}
		else if (userChoice == 7) {}
		else if (userChoice == 8) {}
		else if (userChoice == 9) {
			int ticketID9 = createTicket();
			cout << "Ticket " << ticketID9 << " has been successfully created and stored";
		}
		else {
			cout << "Invalid Selection \n";
		}
	}
}

void technicianMenu(int userID) {
	bool loop = true;
	int userChoice;
	while (loop) {
		cout << "What would you like to do? (enter -1 to exit) \n";
		cout << "0. Get Active Tickets \n";
		cout << "1. Add work entry to ticket\n";
		cout << "2. Add charge to ticket \n";
		cout << "3. View ticket\n";
		cout << "4. Edit ticket status \n";
		cout << "5. View Customer \n";
		cin >> userChoice;
		if (userChoice == -1) {
			loop = false;
		}
		else if (userChoice == 0) {
			showUserFile(2, userID);
		}
		else if (userChoice == 1) {
			bool loop1 = true;
			int ticketID1;
			while (loop1) {
				try {
					cout << "Enter the ticket to add a work entry to \n";
					cin >> ticketID1;
					wEntry(ticketID1);
					loop1 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID";
				}
			}
		}
		else if (userChoice == 2) {
			bool loop2 = true;
			int ticketID2;
			while (loop2) {
				try {
					cout << "Enter the ticket to add a work entry to \n";
					cin >> ticketID2;
					createCharge(ticketID2);
					loop2 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID";
				}
			}
		}
		else if (userChoice == 3) {
			int ticketID3;
			bool loop3 = true;
			while (loop3) {
				cout << "Please enter the ticket ID that you would like to check " << endl;
				cin >> ticketID3;
				cout << "Ticket " << ticketID3 << endl;
				try {
					cout << "Title:" << ticketValueGrab(ticketID3, 0);
					cout << "Customer:" << ticketValueGrab(ticketID3, 1);
					cout << "Date Created:" << ticketValueGrab(ticketID3, 2);
					cout << "Status:" << ticketValueGrab(ticketID3, 3);
					cout << "Repaired Item:" << ticketValueGrab(ticketID3, 4);
					cout << "Description:" << ticketValueGrab(ticketID3, 5);
					cout << "Technician:" << ticketValueGrab(ticketID3, 6);
					cout << "Subtickets:" << ticketValueGrab(ticketID3, 7);
					cout << "Charges:" << ticketValueGrab(ticketID3, 8);
					cout << "Work Entries:" << ticketValueGrab(ticketID3, 9);
					loop3 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID";
				}
			}
		}
		else if (userChoice == 4) {
			bool(loop4) = true;
			int ticketID4;
			while (loop4) {
				try {
					string NewTech;
					cout << "Please enter the ID of the ticket you wish to update the status of \n";
					cin >> ticketID4;
					pushChange(ticketID4, 3);
					loop4 = false;
				}
				catch (...) {
					cout << "Invalid TicketID or UserID";
				}

			}
		}
		else if (userChoice == 5) {
			int userID5;
			bool loop5 = true;
			while (loop5) {
				cout << "Please enter the ID of the user you are looking for \n";
				cin >> userID5;
				try {
					showUserFile(3, userID5);
					loop5 = false;
				}
				catch (...) {
					cout << "Invalid Selection \n";
				}
			}
		}
		}
	}
}