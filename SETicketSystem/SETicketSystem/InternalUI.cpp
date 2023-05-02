#include "InternalUI.h"

//Administrator Menu. written by Mitchell Dahmer, 4/30 
//For presenting administrators with the options available to them and calling the needed functions
void administratorMenu() {
	bool loop = true;
	while (loop) {  // Loop for allowing the user to do as much as needed while logged in
		int userChoiceA;
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
		cin >> userChoiceA;
		if (userChoiceA == -1) { //Closes Loop
			loop = false;
		}
		else if (userChoiceA == 0) {	//Views a user
			int jobNumber, userID0;
			string jobType;
			bool loop0 = true;
			while (loop0) { //Loop foir input validation
				cout << "Please select what type of user to view \n 1. Administrator \n 2. Technician \n 3. Customer";
				cin >> jobNumber; //Takes in user's role
				if (jobNumber == 1) { jobType = "Administrator"; }
				else if (jobNumber == 2) { jobType = "Technician"; }
				else if (jobNumber == 3) { jobType = "Customer"; }
				cout << "Please enter the ID of the user you are looking for \n";
				cin >> userID0;//takes in the user's id
				try {
					if (userVerify(jobType, userID0)) {//sends it to function that verifies if the user exists in that roles
						userReadWholeFile(jobType, userID0);
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
		else if (userChoiceA == 1) { //Assigns a technician to the ticket
			bool(loop1) = true;
			int ticketID1, userID1;
			while (loop1) {
				try { //loops validating input
					string NewTech;
					cout << "Please enter the ID of the ticket you wish to assign a technician to \n";
					cin >> ticketID1; //takes in the requested ticket
					pushChange(ticketID1, 6); //Send the ticketID and line number for technicians to change the value of that ticket (rest of replacement handled in other fucntions)
					cout << "Please enter the ID of the user assigned\n";
					cin >> userID1; //Takes in userID
					UserValueReplace("Technician", userID1, 2, to_string(ticketID1)); //Sends ticketID, userID, and line number to function that will add ticket to technicians active tickets
					loop1 = false;
				}
				catch (...) {
					cout << "Invalid TicketID or UserID";
				}

			}
		}
		else if (userChoiceA == 2) {  //blanket ticket edit
			bool(loop2) = true;
			int ticketID2, line;
			while (loop2) { //input validation loop
				string NewTech;
				int ticketID2;
				cout << "Please enter the ID of the ticket you wish to edit \n";
				cin >> ticketID2; //takes in ticketID
				cout << "What value would you like to edit? \n";
				cout << "0.Title \n 1. Customer \n 2. Date Created \n 3. Status \n 4. Repaired Item \n 5. Description \n 6. Technician \n 7. Subtickets \n 8. Charges \n 9. Work Entries "; 
				try {
					cin >> line; //Takes in users requested edit
					pushChange(ticketID2, line); //Pashes ticket id and chosen edit to other function
					loop2 = false;
				}
				catch (...) {
					cout << "Invalid Ticket or Edit choice";
				}
			}
		}
		else if (userChoiceA == 3) { //displays full ticket
			int ticketID3;
			bool loop3 = true;
			while (loop3) { //input validation loop
				cout << "Please enter the ticket ID that you would like to check " << endl;
				cin >> ticketID3; //takes in requested ticket
				cout << "Ticket " << ticketID3 << endl;
				try {
					cout << "Title:" << ticketValueGrab(ticketID3, 0) << endl; //Goes through every entry in the ticket and prints it our
					cout << "Customer:" << ticketValueGrab(ticketID3, 1) << endl;
					cout << "Date Created:" << ticketValueGrab(ticketID3, 2) << endl;
					cout << "Status:" << ticketValueGrab(ticketID3, 3) << endl;
					cout << "Repaired Item:" << ticketValueGrab(ticketID3, 4) << endl;
					cout << "Description:" << ticketValueGrab(ticketID3, 5) << endl;
					cout << "Technician:" << ticketValueGrab(ticketID3, 6) << endl;
					cout << "Subtickets:" << ticketValueGrab(ticketID3, 7) << endl;
					cout << "Charges:" << ticketValueGrab(ticketID3, 8) << endl;
					cout << "Work Entries:" << ticketValueGrab(ticketID3, 9) << endl;
					loop3 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID, please try again";
				}
			}
		}
		else if (userChoiceA == 4) { //Calls the subticketCreation
			createSubticket();
		}
		else if (userChoiceA == 5) {//Creates new technician
			EnterANewUser("Technician");
			loop = true;
		}
		else if (userChoiceA == 6) {//Create new customer
			EnterANewUser("Customer");
		}
		else if (userChoiceA == 7) {//Creates new administrator
			EnterANewUser("Administrator");
		}
		else if (userChoiceA == 8) {//Fire employee
			int userID, check;
			bool loop8 = true;
			while (loop8) {
				cout << "Please enter the ID of the employee to terminate: \n";
				cin >> userID; //Gets id
				cout << "VERIFY: DELETE USER " << userID << "? \n Reenter ID to continue \n";
				cin >> check; //double checks id
				if (check == userID) { //if id's match, call delete function
					DeleteEmployee("Technician", userID);
					loop8 = false;
				}
				else {
					cout << "Please Try Again \n";
					loop8 = true;
				}
			}
		}
		else if (userChoiceA == 9) { //Calls the ticketCreation
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
	int userChoiceT;
	while (loop) { //input validation loop
		userChoiceT = 0;
		cout << "What would you like to do? (enter -1 to exit) \n"; //Present options to users
		cout << "0. Get Active Tickets \n";
		cout << "1. Add work entry to ticket\n";
		cout << "2. Add charge to ticket \n";
		cout << "3. View ticket\n";
		cout << "4. Edit ticket status \n";
		cout << "5. View Customer \n";
		cout << "6. View subticket\n";
		cin >> userChoiceT;
		if (userChoiceT == -1) { //close loop
			loop = false;
		}
		else if (userChoiceT == 0) { //Retreive current technicians active tickets
			userReadWholeFile("Technician", userID);
		}
		else if (userChoiceT == 1) {//Add work entry to ticket
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
		else if (userChoiceT == 2) { //Add charge to ticket
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
		else if (userChoiceT == 3) {//display entire ticket
			int ticketID3;
			bool loop3 = true;
			while (loop3) {
				cout << "Please enter the ticket ID that you would like to check " << endl;
				cin >> ticketID3;
				cout << "Ticket " << ticketID3 << endl;
				try {
					cout << "Title:" << ticketValueGrab(ticketID3, 0) << endl;
					cout << "Customer:" << ticketValueGrab(ticketID3, 1) << endl;
					cout << "Date Created:" << ticketValueGrab(ticketID3, 2) << endl;
					cout << "Status:" << ticketValueGrab(ticketID3, 3) << endl;
					cout << "Repaired Item:" << ticketValueGrab(ticketID3, 4) << endl;
					cout << "Description:" << ticketValueGrab(ticketID3, 5) << endl;
					cout << "Technician:" << ticketValueGrab(ticketID3, 6) << endl;
					cout << "Subtickets:" << ticketValueGrab(ticketID3, 7) << endl;
					cout << "Charges:" << ticketValueGrab(ticketID3, 8) << endl;
					cout << "Work Entries:" << ticketValueGrab(ticketID3, 9) << endl;
					loop3 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID";
				}
			}
		}
		else if (userChoiceT == 4) { //Push a change to the status of a ticket
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
		else if (userChoiceT == 5) { //Shows all information for a customer
			int userID5;
			bool loop5 = true;
			while (loop5) {
				cout << "Please enter the ID of the user you are looking for \n";
				cin >> userID5;
				try {
					userReadWholeFile("Customer", userID5);
					loop5 = false;
				}
				catch (...) {
					cout << "Invalid Selection \n";
				}
			}
		}
		else if (userChoiceT == 6) {//display entire subticket
			int ticketID6;
			bool loop6 = true;
			while (loop6) {
				cout << "Please enter the ticket ID that you would like to check " << endl;
				cin >> ticketID6;
				cout << "Ticket " << ticketID6 << endl;
				try {
					cout << "Title:" << subticketValueGrab(ticketID6, 0) << endl;
					cout << "Customer:" << subticketValueGrab(ticketID6, 1) << endl;
					cout << "Date Created:" << subticketValueGrab(ticketID6, 2) << endl;
					cout << "Status:" << subticketValueGrab(ticketID6, 3) << endl;
					cout << "Repaired Item:" << subticketValueGrab(ticketID6, 4) << endl;
					cout << "Description:" << subticketValueGrab(ticketID6, 5) << endl;
					cout << "Technician:" << subticketValueGrab(ticketID6, 6) << endl;
					cout << "Subtickets:" << subticketValueGrab(ticketID6, 7) << endl;
					cout << "Charges:" << subticketValueGrab(ticketID6, 8) << endl;
					cout << "Work Entries:" << subticketValueGrab(ticketID6, 9) << endl;
					loop6 = false;
				}
				catch (...) {
					cout << "Invalid Ticket ID";
				}
			}
		}
	}
}