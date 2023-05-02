//Subticket Files, written by Leo Garcia, 4/28 
#include "subticket.h"

using namespace std;

//Subticket Creation, Leo Garcia, 4/28
//Creates the subticket document and adds the subticket id onto the list of subtickets for the requested ticket
void createSubticket() {
	int ticketid;
	int subticketid;
	int datecreated;
	string additionalrepaired, status;
	cout << "Enter the Main Ticket ID: \n";
	cin >> ticketid; //Take in the main ticket id
	cout << "Enter the Sub Ticket ID: \n";
	cin >> subticketid; //User creates the subticketID
	time_t now = (0);
	datecreated = now; //Pulls the current date
	status = "Currently being worked on"; //Sets status
	cout << "Enter additional work needed: \n";
	cin >> additionalrepaired; //takes in a new item description if needed
	ofstream newSubTicket;
	string ticketLocation = "C:\\TicketSystem\\SubTickets\\" + to_string(subticketid);
	ticketLocation = ticketLocation + ".txt"; //Creates new empty document

	newSubTicket.open(ticketLocation); //opens and writes all info to the new document
	newSubTicket << "Main Ticket ID: " << ticketid << "\n";
	newSubTicket << "SubTicketID: " << subticketid << "\n";
	newSubTicket << "Date Created: " << now << "\n";
	newSubTicket << "Status: " << status << "\n";
	newSubTicket << "Additional work needed: " << additionalrepaired << "\n";
	newSubTicket.close(); //closes file
}


//SubTicket Value Grab, Mitchell Dahmer, 4/30
//For retreiving needed information from subtickets
string subticketValueGrab(int subticketid, int line) {
		ifstream requestedFile;
		string fileName = "C:\\TicketSystem\\SubTickets\\" + to_string(subticketid);
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

//Subticket Information Replacer, Mitchell Dahmer, Written 4/30
//Takes in new info for the purposes of updating the Subticket. Limitations of text file operations in C++ require that the 
//File be completely rewritten rather than changing the singular line, so a function has been made to identify the needed
//change location, and begin replicating the file until the point is reached, at which time the new info is entered in and
// and the duplication continues next line
void ticketValueReplace(int subticketID, int line, string data) {
	ifstream requestedFile;
	ofstream newFile;
	string fileName = "C:\\TicketSystem\\SubTickets\\" + to_string(subticketID);
	string tempFileName = fileName + "Temp";
	string fileName1 = fileName + ".txt";
	tempFileName = tempFileName + ".txt";
	requestedFile.open(fileName1); //opens the current file being requested
	newFile.open(tempFileName);// creates a new temporary file with a name similar to the other one for information to be copied to
	string value;
	int count = 0;
	string prefix;
	switch (line) { //This switch statement is so that the new statement given to the file has the correct prefix. 
	case 0:			//This allows us to avoid the issue of having stripped the descriptor off the original value
		prefix = "Main Ticket ID: ";
		break;
	case 1:
		prefix = "SubticketID: ";
		break;
	case 2:
		prefix = "Date Created: ";
		break;
	case 3:
		prefix = "Status: ";
		break;
	case 4:
		prefix = "Additional work needed:  ";
		break;
	}
	while (getline(requestedFile, value)) { //begins reading loop for the files line by line
		if (count == line) { //Calls if its the line we are looking for
			newFile << prefix << data << "\n"; //writes the prefix decided earlier and the new information to the file
		}
		else {
			newFile << value << "\n"; //Writes whatever the current value read from the files is to the same position in the file
		}
		count++; //ups the count for tracking purposes
	};
	requestedFile.close();
	newFile.close();//closes old file
	string old = fileName + "old";
	old = old + ".txt";//sets up name for files removal
	const char* oldChar = old.c_str();
	const char* tempChar = tempFileName.c_str();
	const char* currentChar = fileName1.c_str();
	rename(currentChar, oldChar); //renames the old file to indicate that its been deprecated, doubles as a handy change tracking system for the software
	rename(tempChar, currentChar); //renames new file to match old file to transition is to being the default file
	remove(oldChar);