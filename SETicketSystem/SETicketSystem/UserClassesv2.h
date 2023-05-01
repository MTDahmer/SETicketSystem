#pragma once
#include <string>
#include <cstdio>
using namespace std;

string WhatTypeofUser();
string NameofUser();

void EnterANewUser(string(*f)(), string(*g)(), int(*h)());

int getNextEmployeeID();
//void AdminPermission(int ticketID, string name);
void DeleteEmployee(string userChoice, int userID);

/* Needs to be preceded by Admin verfication in order to run this, on its own anyone can use it
will allow you to enter ID and job title, convert job title into appropiate string ex: "/Customer/",
and Then it will check if it exists, 
 do string changeValue(string value) makes value into 0 ingores input,


and then remove() the file if 
*/
void UserValueReplace(string userChoice , int UserID, int line, string data);
bool userVerify( string userChoice, int userID );