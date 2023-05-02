#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

void EnterANewUser(string type);

int getNextEmployeeID();

bool DeleteEmployee(string userChoice, int userID);
void UserValueReplace(string userChoice, int UserID, int line, string data);
string userValueGrab(string userChoice, int userID, int line);
bool userVerify(string userChoice, int userID);
void userReadWholeFile(string userChoice, int userID);

#endif // !1
