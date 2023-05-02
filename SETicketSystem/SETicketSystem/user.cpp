#include "user.h"

using namespace std;


int getNextEmployeeID() {//able to have a file that returns a unique ID for each new user, uses incremental system to ensure parity
	std::ifstream inputFile("IDcounter.txt"); //we have a file that is only used for this function, create it or return error code
	if (!inputFile.is_open()) {
		std::cerr << "Error: Failed to open file 'IDcounter.txt'" << std::endl;
		return -1;
	}

	string idString;
	getline(inputFile, idString); // Read the current ID from the file, store it into idString temporarily
	inputFile.close(); //done with .txt file

	int id = stoi(idString); // Convert the ID string to an integer
	++id; // Increment the ID

	std::ofstream outputFile("IDcounter.txt"); // reopen the file, this may be an oversight to close and reopen, but we'll keep this for now and in theory can fix this in the future
	if (!outputFile.is_open()) {
		std::cerr << "Error: Failed to open file 'IDcounter.txt'" << std::endl;
		return -1;
	}

	outputFile << id << std::endl; // Write the new ID to the file
	outputFile.close();

	return id;//ultimately we were able to open, increment the ID, use it, and then return a copy to the .txt file
}

void EnterANewUser(string type)
{

	string ID, ActiveTickets, name;
	cout << "Please enter the name of the new user \n";
	cin >> name;
	
	int newID = getNextEmployeeID(); //must call  getNextEmployeeID()

	//when calling in main use EnteraNewUsername(WhatTypeofUser,NameofUser)
	//get the return of type and name so we can put into a text file
	//start of making text file
	ofstream newUser;
	if (type == "Administrator")//nested if else statement to check  what type of user you are
	{
		string UserLocation = "C:\\TicketSystem\\Administrator\\" + to_string(newID) + ".txt";//saves UserLocation as the .txt file 
		newUser.open(UserLocation);
		newUser << "System ID: " << newID << "\n";//each if statement will have its own statements for creating system ID and name, because the JOB title is necessary  to open the file, can't have one generic "user.txt system ID: name :"
		newUser << "Name: " << name << "\n";
	}
	else//if user not found it moves on to the next etc etc
	{
		if (type == "Technician")
		{
			string UserLocation = "C:\\TicketSystem\\Technician\\" + to_string(newID) + ".txt";
			newUser.open(UserLocation);
			newUser << "System ID: " << newID << "\n";
			newUser << "Name: " << name << "\n";
			newUser << "Active Tickets: \n";
		}
		else
		{
			if (type == "Customer")
			{
				string UserLocation = "C:\\TicketSystem\\Customer\\" + to_string(newID) + ".txt";
				string PhoneNumber;
				string Email;
				cout << "May I have your phone number in 'xxx-xxx-xxxx' Format ? " << endl;
				cin >> PhoneNumber;
				cout << "May I have your Email?" << endl;
				cin >> Email;
				newUser.open(UserLocation);
				newUser << "System ID: " << newID << "\n";
				newUser << "Name: " << name << "\n";
				newUser << "Active Tickets: \n";
				newUser << "Phone Number: " << PhoneNumber << "\n";
				newUser << "Email: " << Email << "\n";


			}
			else
			{
				cout << "Error couldn't Create a new User";
			}
		}
	}


	newUser.close();
}

void UserValueReplace(string userChoice, int UserID, int line, string data) {
	ifstream requestedFile;
	ofstream newFile;
	const string userChoiceVariable = userChoice;
	string fileName = "C:\\TicketSystem\\" + userChoiceVariable + "\\" + to_string(UserID);
	string tempFileName = fileName + "Temp";
	string fileName1 = fileName + ".txt";
	tempFileName = tempFileName + ".txt";
	requestedFile.open(fileName1); //opens the current file being requested
	newFile.open(tempFileName); // creates a new temporary file with a name similar to the other one for information to be copied to
	string value;
	int count = 0;
	string prefix;
	switch (line) {
	case 0:
		prefix = "SystemID: ";
		break;
	case 1:
		prefix = "Name: ";
		break;
	case 2:
		prefix = "Active Tickets: ";
		break;
	case 3:
		prefix = "Phone Number: ";
		break;
	case 4:
		prefix = "Email: ";
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
	remove(oldChar); //Deletes old file
}

string userValueGrab(string userChoice, int userID, int line) {
	ifstream requestedFile;
	string fileName = "C:\\TicketSystem\\" + userChoice + "\\" + to_string(userID);
	fileName = fileName + ".txt";
	requestedFile.open(fileName); // Opens a file object that exists in the tickets folder with the requested ticketID
	string value;
	int count = 0;
	while (getline(requestedFile, value)) {
		//getline(requestedFile, value);
		//cout << value;//starts the reading loop that continues line by line until it fines the corresponding line
		if (count == line) {
			value = value.substr(value.find(":") + 1);//Grabs the value at the determined line, then strips everything before the colon so it only grabs the info
			requestedFile.close(); //closes files as looping is done.
			return value; //return value stops here
		}
		count++; //increases count if line not reached yet
	};
	requestedFile.close();
};

bool userVerify(string userChoice, int userID)//simple check if a file exist, because if the customer can enter a Title and an ID it is good enough for this first iteration
{
	{
		string fileName = "C:\\TicketSystem\\" + userChoice + "\\" + to_string(userID) + ".txt";
		ifstream file(fileName);
		return file.good();
	}
}

bool DeleteEmployee(string userChoice, int userID)
{
	string fileName = "C:\\TicketSystem\\" + userChoice + "\\" + to_string(userID) + ".txt";//find and delete a file, in the future we want to have a method to push active tickets into an "assignment" object for replacement of the technician
	int result = std::remove(fileName.c_str());
	return (result == 0);
}

void userReadWholeFile(string userChoice, int userID)
{
	string fileName = "C:\\TicketSystem\\" + userChoice + "\\" + to_string(userID) + ".txt";//cout's an entire document for easily readability

	ifstream file(fileName);
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			// Do something with each line, such as printing it to the console
			cout << line << '\n';
		}
		file.close();
	}
	else {
		cout << "Unable to open file " << fileName << '\n';
	}
}

