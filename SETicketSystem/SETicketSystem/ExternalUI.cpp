#include "externalUI.h"
//External User Interface, written by Mitchell Dahmer, 4/30
//Allows customers to search for information on their tickets


using namespace std;

void customerMenu(int userID) {
	cout << "Welcome Valued Customer! \n";
	int choice;
	bool loop = true;
	while (loop) {
		cout << "Please select an option from the menu below \n 0.View individual ticket \n 1. View all of your current tickets \n (enter -1 to exit) \n";
		cin >> choice;
		if (choice == -1) { //closes loop
			loop = false;
		}
		else if (choice == 0) {
			bool loop0 = true;
			while (loop0) { //Validation loop
				int choice0;
				cout << "Please enter the ticket ID that you would like to check" << endl;
				cin >> choice0; //takes in ticketID
				cout << "Ticket " << choice0 << endl;
				try {
					cout << "Title:" << ticketValueGrab(choice0, 0); //Displays all entries in ticket
					cout << "Customer:" << ticketValueGrab(choice0, 1);
					cout << "Date Created:" << ticketValueGrab(choice0, 2);
					cout << "Status:" << ticketValueGrab(choice0, 3);
					cout << "Repaired Item:" << ticketValueGrab(choice0, 4);
					cout << "Description:" << ticketValueGrab(choice0, 5);
					cout << "Technician:" << ticketValueGrab(choice0, 6);
					cout << "Subtickets:" << ticketValueGrab(choice0, 7);
					cout << "Charges:" << ticketValueGrab(choice0, 8);
					cout << "Work Entries:" << ticketValueGrab(choice0, 9);
					loop0 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID, please try again";
				}
			}
		}
		else if (choice == 1) { //Calls the userValueGrab to get the users currently open tickets
			try {
				cout << "Current Tickets: " << userValueGrab("Customer", userID, 2);
			}
			catch (...) {
				cout << "No Currently Open Tickets \n";
			}
		}
	}
}

