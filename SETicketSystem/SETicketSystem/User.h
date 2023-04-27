#pragma once
#include <string>
using namespace std;

class User {
public:
	User(string Name , int PhoneNumber, string Email);

private:
	string Name;
	int PhoneNumber;
	string Email;
};

class Worker : public User {
public:
	Worker(string Name, int PhoneNumber, string Email);
	string getName();
	void setName(string newName);
	int getPhoneNumber();
	void setPhoneNumber(int newNumber);
	string getEmail();
	
private: 
	
};

class RepairTechnician : public Worker {
public: 
	RepairTechnician(string Name, int PhoneNumber, string Email, int TechnicianID, int TechnicianActiveTickets);
	int getTechnicianActiveTickets();

private:
	int TechnicianActiveTickets;
	int TechnicianID;
	static int NewID;
};

class Customer : public User {
public:
	Customer(string Name, int PhoneNumber, string Email, int TicketID);
	void getOwnTicket(int TicketID, string CustomerName);
private:
	int TicketID;
};

class Administrator : public Worker {
public:
	Administrator(string Name, int PhoneNumber, string Email);

	void setAssignTechnician(int TicketID, float TechnicianName);
	float getAssignTechnician(int TicketID);
	void CreateTicket();// come back once u talk about how ticketcreate() is done
	void CreateSubTicket(int TicketID);
	void AddTicketToTechnicianWorkload(int TicketID, int TechnicianID);
	void EmployNewTechnician(string Name, int PhoneNumber, string Email);
	void FireCurrentTechnician(int firing_TechnicianID, int passing_load_onto_new_technician);
};


