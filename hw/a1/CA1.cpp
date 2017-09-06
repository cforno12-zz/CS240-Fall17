#include <iostream>
#include <stdlib.h>
#include "Donate.h"

using namespace std;

int main(int argc, const char* argv[]){

    string command;
    Donor *donor_ptr = new Donor();

    while (command != "Quit"){
            cout << "Enter a command.\n";
            cout << "Choose from [\"Add\" \"Manage\" \"View\" \"Donate\" \"Total\" \"Quit\"]\n";
            cout << ": ";
            cin >> command;
        if (command == "Add"){
            donor_ptr->add();
        } else if (command == "Manage"){
            donor_ptr->add();
        } else if (command == "View"){
            donor_ptr->view();
        } else if (command == "Donate"){
            donor_ptr->donate();
        } else if (command == "Total"){
            donor_ptr->total();
        } else if (command != "Quit"){
            cout << "Command not recognized. Please try again.\n\n";
        }
    }
    exit(0);
}
