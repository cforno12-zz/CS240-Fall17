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
