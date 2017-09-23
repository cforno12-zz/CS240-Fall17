#include <iostream>
#include <stdlib.h>
#include <string>
#include "Donor.h"

using namespace std;

Donor::Donor(){
    last_name = "";
    first_name = "";
    street_name = "";
    town = "";
    zip_code = "";
    age = -1;
    street_num = -1;
    donated = 0.00;
    userid = "";
    password = "";
}

string Donor::getlast_name(){
    return last_name;
}
string Donor::getfirst_name(){
    return first_name;
}
string Donor::getstreet_name(){
    return street_name;
}
string Donor::gettown(){
    return town;
}
string Donor::getzip_code(){
    return zip_code;
}
string Donor::getuserid(){
	return userid;
}
string Donor::getpassword(){
    return password;
}
string Donor::getstate(){
    return state;
}
int Donor::getage(){
    return age;
}
int Donor::getstreet_num(){
    return street_num;
}
float Donor::getdonated(){
    return donated;
}
void Donor::setlast_name(string ln){
    last_name = ln;
}
void Donor::setfirst_name(string fn){
    first_name = fn;
}
void Donor::setstreet_name(string sn){
    street_name = sn;
}
void Donor::settown(string t){
    town = t;
}
void Donor::setzip_code(string zc){
    zip_code = zc;
}
void Donor::setuserid(string ui){
    userid = ui;
}
void Donor::setpassword(string pw) {
    password = pw;
}
void Donor::setstate(string st){
    state = st;
}
void Donor::setage(int a){
    age = a;
}
void Donor::setstreet_num(int sn){
    street_num = sn;
}
void Donor::setdonated(float d){
    donated = d;
}
bool Donor::comparedonor(const Donor &other){
    bool retVal = false;
    if(last_name == other.last_name){
        if(first_name == other.first_name){
            if (street_name == other.street_name) {
                if(town == other.town){
                    if(zip_code == other.zip_code){
                        if(userid == other.userid){
                            if(password == other.password){
                                if(state == other.state){
                                    if (age == other.age){
                                        if(street_num == other.street_num){
                                            if(donated == other.donated){
                                                retVal = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retVal;
}

void Donor::manage(){
    /*change some or all of the donor information (other than the userid and password)
associated with the record for the donor who is logged in. Please allow the user to select which fields to
update, keeping all other information the same.*/
    
}

void Donor::view(){

    cout << "Donor Info\n";
    cout << first_name << " " << last_name << ": age " << age << endl;
    cout << street_num << " " << street_name << endl;
    cout << town << ", " << state << " " << zip_code << endl;

    cout << "Current Amount Donated: $";
    printf("%.2f", donated);
    cout << "\n\n";
}

void Donor::donate(){
    float temp_donated;
    while(true){
            cout << "\nEnter Amount to Donate: ";
            cin  >> temp_donated;
            if(temp_donated < 0){
                cout << "You cannot donate negative amount of money." << endl;
            } else if((temp_donated + donated) > 5000){
                cout << "You cannot donate more than $5,000." << endl;
                cout << "If you would like to donate $5,000, please donate " << (5000.0 - donated) << " when prompted." << endl;
            }
    }
    printf("You have just donated $%.2f. Thank you!\n", donated);
}

void Donor::total(){
    cout << last_name;
    printf(" $%.2f\n", donated);
}
