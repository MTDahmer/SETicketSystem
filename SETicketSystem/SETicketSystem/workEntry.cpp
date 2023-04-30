#include "User.h"
#include "ticket.h"
#include "workEntry.h"

using namespace std;

void wEntry (int ticketID) {
    string date, technician = RepairTechnician.Name, work;
    cout << "Enter the date: \n";
    cin >> date;
    cout << "Technician assigned: " << technician << "\n";
    cout << "Enter description of work: \n";
    cin >> work;
    string cWork = ticketValueGrab(ticketID, 9);
    string updateWork = cWork + "[" + date + ", " + technician + ", " + work + "], ";
    ticketValueReplace(ticketID, 9, updateWork);
};

