/*Main CPP files, this will be where the code responsible for
calling the other classes and running the program will be, all classes
made for this application should be written as headers and refrenced here
when needed. This way all classes will exist as seperate objects*/

#include <iostream>
#include <string>
#include "ticket.h"
#include <studio>
using namespace std;
string ticketValueGrab(int ticketID, int line) {
	ifstream requestedFile;
	fileName = "/Tickets/" + ticketID;
	requestedFile.open(fileName);
	string value;
	int count;
	while (getline(requestedFile), value) {
		if (count == line) {
			value = value.substr(value.find(":") + 1);
			return value;
		}
		count ++
	}
}
void ticketValueReplace(int ticketID, int line, T data) {
	ofstream requestedFile, newFile;
	fileName = "/Tickets/" + ticketID;
	tempFileName = "/Tickets/" + ticketID + "Temp";
	requestedFile.open(fileName);
	newFile.open(tempFileName);
	string value;
	int count;
	string prefix;
	switch(line) {
	case 0:
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
	while (getline(requestedFile), value) {
		if (count == line) {
			newFile << prefix << data;
		}
		else {
			newFile << value;
		}
		count++
	}
	fileName.close();
	old = fileName + "old";
	rename(fileName, old);
	rename(tempFileName, fileName);

}}
int main() {
	
}