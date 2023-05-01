//Work entry Creation, written by Nico Ambriz, 4/29
//Creates a work entry and appends it to the ticket afetr adding it to the end of old list
#include "User.h"
#include "ticket.h"
#include "workEntry.h"

using namespace std;

void wEntry (int ticketID) {
    string date, technician, description;
    int minutes;
    cout << "Enter the date: \n";
    cin >> date;
    cout << "Enter the number of minutes worked: \n";
    cin >> minutes;
    cout << "Enter description of work: \n";
    cin >> description; //Fills the variables needed for a work entry through user prompt
    string cWork = ticketValueGrab(ticketID, 9); //Retreies the current list of work entry from the requested ticket
    string updateWork = cWork + "[" + date + ", " + to_string(minutes) + " minutes, " + description + "], "; //adds the new work entry onto the back of the current list
    ticketValueReplace(ticketID, 9, updateWork); //sends the new list to be written to the ticket
};

