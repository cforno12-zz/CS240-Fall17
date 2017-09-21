#include <iostream>
#include "Donor.h"
#include <stdlib.h>

using namespace std;

#define CHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"
#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"
#define SPECIAL "!\"#$%&'()*+,-./:;<=>?@[]^_`{|}~"

Donor::Donor(){
    last_name = "";
    first_name = "";
    street_name = "";
    town = "";
    zip_code = "xxxxx";
    age = -1;
    street_num = 0;
    amount_donated = 0.00;
    userid = "";
    password = "";
}
bool validate_userid(){
    bool retVal = false;
    if(userid.length() >= 5){
        if (userid.length() < 10){
            if(userid.find_first_of(CHAR) != string::npos){
                retVal = true;
            } else {
                cout << "User ID cannot have special characters." << endl;
            }
        } else {
            cout << "User ID must be less than 10 characters long." << endl;
        }
    } else {
        cout << "User ID must be at least 5 characters long." << endl;
    }
    return retVal;
}

bool validate_password(){
    bool retVal;
    if(password.length() >= 6){
        if(password.find_first_of(NUM) != string::npos){
            if(password.find_first_of(SPECIAL) != string::npos){
                retVal = true;
            } else {
                cout << "Password has to contain one special character." << endl;
            }
        } else {
            cout << "Password has to contain at least one digit." << endl;
        }
    } else {
        cout << "Password has to contain at least 6 characters." << endl;
    }
    return retVal;
}
void Donor::login(){
    while (true){
        cout << "User ID: ";
        cin >> userid;
        if (validate_userid()){
            break;
        }
    }
    while (true){
        cout << "Password: ";
        cin >> password;
        if(validate_password()){
            break;
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
    //    printf("%.2f", tot);
    cout << "\n\n";
}

void Donor::donate(){

    cout << "\nEnter Amount to Donate: ";
    cin  >> amount_donated;
    //    tot += amount_donated;
    printf("$%.2f donated.\n\n", amount_donated);
}

void Donor::total(){
    //    printf(" $%.2f\n\n", tot);
}
