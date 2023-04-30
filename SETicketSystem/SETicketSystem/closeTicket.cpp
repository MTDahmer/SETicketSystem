#include <iostream>
using namespace std;

void closeTicket(){
    string choice;

    cout << "Do you want to make a new ticket? (Type yes or no) \n";
    cin >> choice;

    if (choice == "yes"){
        createTicket()
    } else {
        return 0;
    }
}