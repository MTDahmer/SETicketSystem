#pragma once
#ifndef workEntry
#define workEntry
#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include "ticket.h"


using namespace std
class workEntry {
private:
    string date;
    string technician = RepairTechnician.Name;
    string work;


    workEntry(ticketID){
        cout << "Enter the date: \n";
        cin >> date;
        cout << "Technician assigned: " << technician << "\n";
        return 0;
        cout << "Enter description of work: \n";
        cin >> work;
        string cWork = ticketValueGrab(ticketID, 9);
        string updateWork = cWork + "[" + date + ", " + technician + ", " + work + "], ";
        ticketValueReplace(ticketID, 9, newCharge);
    };
};


#endif
