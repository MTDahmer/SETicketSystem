//Header for subticket.cpp
#pragma once
#ifndef subticket
#define subticket
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

void createSubticket();
	
std::string subticketValueGrab(int subticketid, int line);
void subticketValueReplace(int subticketID, int line, std::string data);

#endif 
