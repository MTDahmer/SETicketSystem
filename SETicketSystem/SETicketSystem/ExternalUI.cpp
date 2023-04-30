#include "externalUI.h"

using namespace std;

void customerOptions() {
	int choice1;
	cout << "Please enter the ticket ID that you would like to check: " << endl;
	cin >> choice1;
	cout << "Ticket " << choice1;
	try {
		cout << ticketValueGrab(choice1, 0);
	}
}

