#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Donor.h"
#include "DonorDatabase.h"
#define MAX_DONORS 1000

using namespace std;

int main(int argc, char *argv[]){

    // check if cmd line arguments only has two arguments (max donors, and filename)
    if(argc > 3){
        cout << "ERROR, too many arguments" << endl;
        exit(0);
    } else if (argc == 1) {
        cout << "ERROR, you need to include the amount of max donors." << endl;
        exit(0);
    } else if (argc <= 3){

        int donors = stoi(argv[1]);
        DonorDatabase * database_ptr = new DonorDatabase(donors);

        if(argc == 3){
            string file = argv[2];
            database_ptr->load(file);
        }

        //check if the max number of donors are between 1 and 1000
        if(donors < 1){
            cout << "ERROR, you must have at least 1 donor." << endl;
            exit(0);
        } else if (donors > 1000){
            cout << "ERROR, max numbers of donors is 1,000" << endl;
            exit(0);
        }

        string command = "";
        string file = "";

        cout << "Welcome to my donation page!" << endl;
        while(command != "Quit"){
            cout << endl;
            cout << "Enter a command:\nChoose from: ['Login', 'Add', 'Save', 'Load', 'Report', or 'Quit']\n\t: ";
            cin >> command;
            if(command == "Login"){
                database_ptr->login();
            } else if(command == "Add"){
                database_ptr->add();
            } else if(command == "Save"){
                cout << "Which file would you like to write to?" << endl;
                cin >> file;
                database_ptr->save(file);
            } else if(command == "Load"){
                cout << "Which file would you like to read from?" << endl;
                cin >> file;
                database_ptr->load(file);
            } else if(command == "Report"){
                database_ptr->report();
            } else if(command != "Quit"){
                cout << "Command not recognized. Please input a valid command." << endl;
            }
        }

        cout << "\n";
        cout << "Exiting..." << endl;
        exit(0);
    }
}
