#pragma once
#ifndef charge
#define charge
#include <string>
#include <vector>
#include <iostream>
class charge {
private:
	std::string name;
	float price;
	std::string description;

	charge() {
		std::cout << "Enter name of charge: \n";
		std::cin >> name;
		std::cout << "Enter the cost of the charge: \n";
		std::cin >> price;
		std::cout << "Enter a description of the charge \n";
		std::cin >> description;
	};

};


#endif