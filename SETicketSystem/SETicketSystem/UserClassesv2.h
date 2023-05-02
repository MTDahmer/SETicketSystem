#pragma once
#include <string>
#include <cstdio>
using namespace std;

string WhatTypeofUser();
string NameofUser();

void EnterANewUser(string(*f)(), string(*g)(), int(*h)());

int getNextEmployeeID();
//void AdminPermission(int ticketID, string name); +replaced by userVerify+
bool DeleteEmployee(string userChoice, int userID);
void UserValueReplace(string userChoice , int UserID, int line, string data);
bool userVerify( string userChoice, int userID );
void userReadWholeFile(string userChoice, int userID);
