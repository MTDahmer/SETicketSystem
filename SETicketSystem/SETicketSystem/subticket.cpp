#include "subticket.h"

using namespace std;

void createSubticket() {
	int ticketid;
	int subticketid;
	int datecreated;
	string additionalrepaired, status;
	cout << "Enter the Main Ticket ID: \n";
	cin >> ticketid;
	cout << "Enter the Sub Ticket ID: \n";
	cin >> subticketid;
	time_t now = (0);
	datecreated = now;
	status = "Currently being worked on";
	cout << "Enter additional work needed: \n";
	cin >> additionalrepaired;
	ofstream newSubTicket;
	string ticketLocation = "C:\\SubTickets\\" + to_string(subticketid);
	ticketLocation = ticketLocation + ".txt";

	newSubTicket.open(ticketLocation);
	newSubTicket << "Main Ticket ID: " << ticketid << "\n";
	newSubTicket << "SubTicketID: " << subticketid << "\n";
	newSubTicket << "Date Created: " << now << "\n";
	newSubTicket << "Status" << status << "\n";
	newSubTicket << "Additional work needed: " << additionalrepaired << "\n";
	newSubTicket.close();
}


string subticketValueGrab(int subticketid, int line) {
		ifstream requestedFile;
		string fileName = "C:\\SubTickets\\" + to_string(subticketid);
		fileName = fileName + ".txt";
		requestedFile.open(fileName);
		string value;
		int count = 0;
		while (getline(requestedFile, value)) {
			if (count == line) {
				value = value.substr(value.find(":") + 1);
				requestedFile.close();
				return value;
			}
			count++;
		}



	};



#endif // !
