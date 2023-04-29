//Ticket Class Header, Mitchell Dahmer, Written 4/18, 
//Header files that holds the ticket class along with related functions
#pragma once
#ifndef ticket
#define ticket
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "charge.h"

using namespace std;

int ticketIDGenerator(int data, string customer);

void createTicket();

string ticketValueGrab(int ticketID, int line);

void ticketValueReplace(int ticketID, int line, string data);

string changeValue(string value);

void pushChange(int ticketID, int line);

#endif