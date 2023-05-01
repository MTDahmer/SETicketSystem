#include "InternalUI.h"

//Administrator Menu. written by Mitchell Dahmer, 4/30 
//For presenting administrators with the options available to them and calling the needed functions
void administratorMenu() {
	bool loop = true;
	int userChoice;
	while (loop) {  // Loop for allowing the user to do as much as needed while logged in
		cout << "What would you like to do? (enter -1 to exit) \n"; //Presents the user with the availble options for Administrators
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
		if (userChoice == -1) { //Closes Loop
			loop = false;
		}
		else if (userChoice == 0) {	//Views a user
			int jobNumber, userID0;
			bool loop0 = true;
			while (loop0) { //Loop foir input validation
				cout << "Please select what type of user to view \n 1. Administrator \n 2. Technician \n 3. Customer";
				cin >> jobNumber; //Takes in user's role
				cout << "Please enter the ID of the user you are looking for \n";
				cin >> userID0;//takes in the user's id
				try {
					if (showUserFile(jobNumber, userID0)) {//sends it to function that verifies if the user exists in that roles
						loop0 = false;
					}//ends if call is succsessful
					else {
						cout << "Invalid User"; //Repeats if the call fails
					}
				}
				catch (...) {
					cout << "Invalid Selection \n";
				}
			}
		}
		else if (userChoice == 1) { //Assigns a technician to the ticket
			bool(loop1) = true;
			int ticketID1, userID1;
			while (loop1) {
				try { //loops validating input
					string NewTech;
					cout << "Please enter the ID of the ticket you wish to assign a technician to \n";
					cin >> ticketID1; //takes in the requested ticket
					pushChange(ticketID1, 6); //Send the ticketID and line number for technicians to change the value of that ticket (rest of replacement handled in other fucntions)
					cout << "Please enter the ID of the user assigned";
					cin >> userID1; //Takes in userID
					UserValueReplace(userID1, 2, ticketID1); //Sends ticketID, userID, and line number to function that will add ticket to technicians active tickets
					loop1 = false;
				}
				catch (...) {
					cout << "Invalid TicketID or UserID";
				}

			}
		}
		else if (userChoice == 2) {  //blanket ticket edit
			bool(loop2) = true;
			int ticketID2, line;
			while (loop2) { //input validation loop
				string NewTech;
				int ticketID;
				cout << "Please enter the ID of the ticket you wish to edit \n";
				cin >> ticketID; //takes in ticketID
				cout << "What value would you like to edit? \n";
				cout << "0.Title \n 1. Customer \n 2. Date Created \n 3. Status \n 4. Repaired Item \n 5. Description \n 6. Technician \n 7. Subtickets \n 8. Charges \n 9. Work Entries "; 
				try {
					cin >> line; //Takes in users requested edit
					pushChange(ticketID, line); //Pashes ticket id and chosen edit to other function
					loop2 = false;
				}
				catch (...) {
					cout << "Invalid Ticket or Edit choice";
				}
			}
		}
		else if (userChoice == 3) { //displays full ticket
			int ticketID3;
			bool loop3 = true;
			while (loop3) { //input validation loop
				cout << "Please enter the ticket ID that you would like to check " << endl;
				cin >> ticketID3; //takes in requested ticket
				cout << "Ticket " << ticketID3 << endl;
				try {
					cout << "Title:" << ticketValueGrab(ticketID3, 0); //Goes through every entry in the ticket and prints it our
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
		else if (userChoice == 4) { //Calls the subticketCreation
			createSubticket();
		}
		else if (userChoice == 5) {//Creates new technician
		}
		else if (userChoice == 6) {//Create new customer
		}
		else if (userChoice == 7) {//Creates new administrator
		}
		else if (userChoice == 8) {//Fire employee
		}
		else if (userChoice == 9) { //Calls the ticketCreation
			int ticketID9 = createTicket();
			cout << "Ticket " << ticketID9 << " has been successfully created and stored"; //displays new ticketID
		}
		else {
			cout << "Invalid Selection \n";
		}
	}
}

void technicianMenu(int userID) {
	bool loop = true;
	int userChoice;
	while (loop) { //input validation loop
		cout << "What would you like to do? (enter -1 to exit) \n"; //Present options to users
		cout << "0. Get Active Tickets \n";
		cout << "1. Add work entry to ticket\n";
		cout << "2. Add charge to ticket \n";
		cout << "3. View ticket\n";
		cout << "4. Edit ticket status \n";
		cout << "5. View Customer \n";
		cin >> userChoice;
		if (userChoice == -1) { //close loop
			loop = false;
		}
		else if (userChoice == 0) { //Retreive current technicians active tickets
			showUserFile(2, userID);
		}
		else if (userChoice == 1) {//Add work entry to ticket
			bool loop1 = true;
			int ticketID1;
			while (loop1) { //validation loop
				try {
					cout << "Enter the ticket to add a work entry to \n";
					cin >> ticketID1; //take in ticketID
					wEntry(ticketID1); //Call work entry creator 
					loop1 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID";
				}
			}
		}
		else if (userChoice == 2) { //Add charge to ticket
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
		else if (userChoice == 3) {//display entire ticket
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
		else if (userChoice == 4) { //Push a change to the status of a ticket
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
		else if (userChoice == 5) { //Shows all information for a customer
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