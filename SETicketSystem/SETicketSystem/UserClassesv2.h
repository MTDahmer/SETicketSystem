#pragma once
#include <string>
using namespace std;

string WhatTypeofUser();
string NameofUser();

void EnterANewUser(string(*f)(), string(*g)(), int(*h)());

int getNextEmployeeID();
void AdminPermission(int ticketID, string name);