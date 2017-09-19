#include <iostream>
#include "Donate.h"
#include <stdlib.h>

using namespace std;

Donor::Donor(){
    last_name = "";
    first_name = "";
    street_name = "";
    town = "";
    zip_code = "xxxxx";
    age = -1;
    street_num = 0;
    amount_donated = 0.00;
}

void Donor::login(){
    bool incorrect = true;
    while (incorrect){
        cout << "User ID: ";
        cin >> userid;
        if (userid.length() <= 5 && userid.length() > 10 && userid.find_first_not_of("[^A-Za-z0-9_]") == string::npos){
            incorrect = false;
        } else {
            cout << "Error, User ID must be at least 5 characters, but no more than 10. No special characters.\n";
        }
    }
    incorrect = true;
    while (incorrect){
        cout << "Password: ";
        cin >> password;
        if(password.length() <= 6 && password.find_first_of("[0-9]") && password.find_first_of(" !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~]'") <= 0){
            incorrect = false;
        } else {
            cout << "Error, Password must be at least 6 characters containing one digit and one special character." << endl;
        }
    }
    //go to 2nd level of interface
}

void Donor::add(){
    cout << "Last Name: ";
    cin >> last_name;
    cout << "First Name: ";
    cin >> first_name;
    cout << "Age: ";
    cin >> age;
    cout << "House Number: ";
    cin >> street_num;
    cout << "Street Name: ";
    cin >> street_name;
    cout << "Town: ";
    cin >> town;
    cout << "Zip Code: ";
    cin >> zip_code;
    cout << "\n";

}
void Donor::view(){

    cout << "Donor Info\n";
    cout << first_name << " " << last_name << ": age " << age << "\n";
    cout << street_num << " " << street_name << "\n";
    cout << town << ", NY " << zip_code << "\n";

    cout << "Current Amount Donated: $";
    printf("%.2f", tot);
    cout << "\n\n";
}

void Donor::donate(){

    cout << "\nEnter Amount to Donate: ";
    cin  >> amount_donated;
    tot += amount_donated;
    printf("$%.2f donated.\n\n", amount_donated);
}

void Donor::total(){
    printf(" $%.2f\n\n", tot);
}
