//Ticket Functions, Mitchell Dahmer, Written 4/18, 
//Header files that holds the ticket class along with related functions

#include "ticket.h"

using namespace std;

int ticketIDGenerator(int data, string customer) {
	cout << data;
	return data;
}


//Ticket Constructor, Mitchell Dahmer, Written 4/20, edited 4/28
// Constructor for tickets, takes in arguments and makes a text file
void createTicket() {
	string title, description, customer, repairedItem, status;
	int dateCreated, ticketID;
	cout << "Enter title of ticket: \n";
	cin >> title;
	cout << "Enter a brief description of the issue: \n";
	cin >> description;
	cout << "Enter the name of the customer: \n";
	cin >> customer;
	time_t now = time(0);
	dateCreated = now;
	ticketID = ticketIDGenerator(dateCreated, customer);
	cout << "Enter a description of the item to be repaired: \n";
	cin >> repairedItem;
	status = "Awaiting Assignment";
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
	newTicket.close();
};

//ticket Information Grabber, Mitchell Dahmer, written 4/20
//Retreives information from the given ticket at the given entry in the ticket. each line corresponds to a constant location
//for specific information. For a key, see the ticketValueReplace function as the switch statement there corresponds to what
//line is used for which peice of data
string ticketValueGrab(int ticketID, int line) {
	ifstream requestedFile;
	string fileName = "/Tickets/" + ticketID;
	requestedFile.open(fileName); // Opens a file object that exists in the tickets folder with the requested ticketID
	string value;
	int count = 0;
	while (getline(requestedFile, value)) { //starts the reading loop that continues line by line until it fines the corresponding line
		if (count == line) {
			value = value.substr(value.find(":") + 1);//Grabs the value at the determined line, then strips everything before the colon so it only grabs the info
			requestedFile.close(); //closes files as looping is done.
			return value; //return value stops here
		}
		count++; //increases count if line not reached yet
	};
};

//ticket Information Replacer, Mitchell Dahmer, Written 4/20, edited 4/27
//Takes in new info for the purposes of updating the ticket. Limitations of text file operations in C++ require that the 
//File be completely rewritten rather than changing the singular line, so a function has been made to identify the needed
//change location, and begin replicating the file until the point is reached, at which time the new info is entered in and
// and the duplication continues next line
void ticketValueReplace(int ticketID, int line, string data) {
	ifstream requestedFile;
	ofstream newFile;
	string fileName = "/Tickets/" + ticketID;
	string tempFileName = fileName + "Temp";
	requestedFile.open(fileName); //opens the current file being requested
	newFile.open(tempFileName);// creates a new temporary file with a name similar to the other one for information to be copied to
	string value;
	int count = 0 ;
	string prefix;
	switch (line) { //This switch statement is so that the new statement given to the file has the correct prefix. 
	case 0:			//This allows us to avoid the issue of having stripped the descriptor off the original value
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
	while (getline(requestedFile, value)) { //begins reading loop for the files line by line
		if (count == line) { //Calls if its the line we are looking for
			newFile << prefix << data; //writes the prefix decided earlier and the new information to the file
		}
		else {
			newFile << value; //Writes whatever the current value read from the files is to the same position in the file
		}
		count++; //ups the count for tracking purposes
	};
	requestedFile.close(); //closes old file
	string old = fileName + "old"; //sets up name for files removal
	//rename(fileName, old); //renames the old file to indicate that its been deprecated, doubles as a handy change tracking system for the software
	//rename(tempFileName, filename); //renames new file to match old file to transition is to being the default file

}

//Value Change, Mitchell Dahmer, Written 4/18, edited 4/27 to be broader purpose
//for allowing the user to either completely rewrite or append to the end of a value
//This function exists to handle and all changes to the ticket
string changeValue(string value) {

	cout << "Edit current value or append? \n 1. Append \n 2. Edit \n"; //
	int choice;
	string userEntry;
	cin >> choice; //takes in user choice of action
	bool loop = true;
	while (loop) { //verification while loop to make sure user enters the correct info
		if (choice == 1) {
			cout << "Please enter the statement to append to the current value \n";
			cin >> userEntry;
			value = value + " " + userEntry; //takes users entry, adds a space for formatting and replaces the value with the concatenated version
			loop = false; //ends loop
			return value; //returns new value to function
		}
		else if (choice == 2) {
			cout << "Please enter a new value";
			cin >> value; //in contrast to other function, replaces the value outright
			loop = false;//closes loop
			return value;// returns replaced value

		}
		else { //continues loop if user chooses incorrectly
			cout << "Invalid Selection. Please only enter the numbers listed as options";
		}
	}
}

//Change Push, Mitchell Dahmer, written 4/27
//for calling the various change function, getting the current values of what is being changed, 
//and pushing the new data after calling the changing function
void pushChange(int ticketID, int line) {
	bool loop1 = true;
	bool loop2 = true;
	int choice;
	string value;
	switch (line) { //A switch for making sure the statements put out to the user properly reflect what they are changing
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
	string currentValue = ticketValueGrab(ticketID, line); //calls reveiw function to get current value user is wanting to edit

	while (loop1) {
		string newValue = changeValue(currentValue); //Calls changing function to get new value 
		cout << "New " << value << " for Ticket " << ticketID << "\n" << newValue << "\n"; //displays user new value for checking
		loop2 = true;//sets loop2 to true so that edit choice loop can run again after retry
		while (loop2) {
			cout << "Keep New " << value << " or Edit Again ? (1 for KEEP, 2 for EDIT)"; //Allows user to restart if mistakes were made
			cin >> choice;
			if (choice == 2) { //if user wants to restart, this sends back to the front of the loop and lets them try again
				loop1 = true;
				loop2 = false;
			}
			else if (choice == 1) { //if user is fine, ends loop and sends to push
				loop1 = false;
				loop2 = false;
			}
			else {
				cout << "Invalid Selection \n"; //if user messes up, keeps them in the loop
				loop1 = true;
				loop2 = true;
			}
		} ticketValueReplace(ticketID, line, newValue); //send the value to the replace function to put the change into place
	}
}
