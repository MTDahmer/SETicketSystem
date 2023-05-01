#include "externalUI.h"

using namespace std;

void customerMenu() {
	int choice1;
	bool loop = true;
	while (loop) {
		cout << "Please enter the ticket ID that you would like to check (enter 0 to exit) " << endl;
		cin >> choice1;
		if (choice1 == 0) {
			return;
		}
		cout << "Ticket " << choice1 << endl;
		try {
			cout << "Title:" << ticketValueGrab(choice1, 0);
			cout << "Customer:" << ticketValueGrab(choice1, 1);
			cout << "Date Created:" << ticketValueGrab(choice1, 2);
			cout << "Status:" << ticketValueGrab(choice1, 3);
			cout << "Repaired Item:" << ticketValueGrab(choice1, 4);
			cout << "Description:" << ticketValueGrab(choice1, 5);
			cout << "Technician:" << ticketValueGrab(choice1, 6);
			cout << "Subtickets:" << ticketValueGrab(choice1, 7);
			cout << "Charges:" << ticketValueGrab(choice1, 8);
			cout << "Work Entries:" << ticketValueGrab(choice1, 9);
		}
		catch (...) {
			cout << "Invalid Ticket ID, please try again";
		}
	}
}

