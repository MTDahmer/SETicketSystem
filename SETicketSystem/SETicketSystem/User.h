#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <iostream>


std::string WhatTypeofUser();
std::string NameofUser();
int getNextEmployeeID();

void EnterANewUser(std::string f, std::string g, int(*h)());


void AdminPermission(int ticketID, std::string name);

#endif