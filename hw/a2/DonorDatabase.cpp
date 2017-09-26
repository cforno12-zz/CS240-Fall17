#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include "DonorDatabase.h"

#define CHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"
#define LETTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"
#define SPECIAL "!\"#$\%&'()*+,-./:;<=>?@[]^_`{|}~"

DonorDatabase::DonorDatabase(int num_donors){
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
    donor_indx = 0;
    max_donor = num_donors;
    data = new Donor[num_donors];
}


Donor DonorDatabase::access_data(int idx){
        return data[idx];
}
bool DonorDatabase::validate_userid(){
    bool retVal = false;
    if(userid.length() >= 5){
        if (userid.length() < 10){
            if(userid.find_first_of(SPECIAL) == string::npos){
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

bool DonorDatabase::validate_password(){
    bool retVal = false;
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

void DonorDatabase::login(){
    int curr_donor = -1;
    while (true){
        cout << "User ID: ";
        cin >> userid;
        bool found = false;
        if (validate_userid()){
            for (int i = 0; i < donor_indx; i++) {
                if(userid == data[i].getuserid()){
                    curr_donor = i;
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            } else {
                cout << "User ID not found." << endl;
            }
        } else {
            userid = "";
        }

    }
    while (true){
        cout << "Password: ";
        cin >> password;
        if(validate_password()){
            if(data[curr_donor].getpassword() == password){
                break;
            } else {
                cout << "Wrong password." << endl;
            }
       }
       password = "";
    }
    string command = "";
    cout << endl;
    cout << "Welcome " << data[curr_donor].getuserid() << " to your donation page!" << endl;
    while(command != "Logout"){
        cout << endl;
        cout << "Enter a command:\nChoose from: ['Manage', 'Passwd', 'View', 'Donate', 'Total', or 'Logout']\n\t: ";
        cin >> command;
        if(command == "Manage"){
            data[curr_donor].manage();
        } else if (command == "Passwd"){
            data[curr_donor].change_password();
        } else if(command == "View"){
            data[curr_donor].view();
        } else if(command == "Donate"){
            data[curr_donor].donate();
        } else if(command== "Total"){
            data[curr_donor].total();
        } else if(command != "Logout"){
            cout << "Command not recognized. Please input a valid command." << endl;
        }
        if(command=="Logout"){
            cout << "Logging out..." << endl;
        }
    }
}



bool DonorDatabase::validate_last_name() {
    bool retVal = false;
    if(last_name.find_first_not_of(LETTERS) == string::npos){
        retVal = true;
    } else {
        cout << "Your last name should only contain letters." << endl;
    }
    return retVal;
}


bool DonorDatabase::validate_first_name() {
    bool retVal = false;
    if(first_name.find_first_not_of(LETTERS) == string::npos){
        retVal = true;
    } else {
        cout << "Your first name should only contain letters." << endl;
    }
    return retVal;
}

bool DonorDatabase::validate_zip_code(){
    bool retVal = false;
    if(zip_code.length() == 5){
        if(zip_code.find_first_not_of(NUM) == string::npos){
            retVal = true;
        } else {
            cout << "Your zip code must contain 5 digits." << endl;
        }
    } else {
        cout << "Your zip code must contain 5 digits." << endl;
    }
    return retVal;
}

void DonorDatabase::add(){
    Donor * curr = new Donor();
    if(!(curr->comparedonor(data[max_donor-1]))){
        cout << "Maximum donors reached. You cannot add another donor." << endl;
        return;
    }
    while(true){
        cout << "User ID: ";
        cin >> userid;
        if(validate_userid()){
            bool already_in_use = false;
            for (int i=0; i < donor_indx; i++){
                if(data[i].getuserid() == userid){
                    cout << "User ID is already in use. Please choose another User ID." << endl;
                    already_in_use = true;
                    break;
                }
            }
            if(!already_in_use){
                curr->setuserid(userid);
                break;
            }

        }
        userid="";
    }
    while(true){
        cout << "Password: ";
        cin >> password;
        if(validate_password()){
            curr->setpassword(password);
            break;
        }
        password="";
    }
    while(true){
        cout << "Last Name: ";
        cin >> last_name;
        if(validate_last_name()){
            curr->setlast_name(last_name);
            break;
        }
        last_name = "";
    }
    while(true){
        cout << "First Name: ";
        cin >> first_name;
        if(validate_first_name()){
            curr->setfirst_name(first_name);
            break;
        }
        first_name = "";
    }
    while(true){
        cout << "Age: ";
        cin >> age;
        if(age >= 18){
            curr->setage(age);
            break;
        } else {
            cout << "You must be 18 years or older to donate." << endl;
        }
    }

    while(true){
        cout << "House Number: ";
        cin >> street_num;
        if(street_num > 0){
            curr->setstreet_num(street_num);
            break;
        } else {
            cout << "House number must be positive." << endl;
        }
    }

    cout << "Street Name: ";
    cin.ignore(1000, '\n');
    getline(cin, street_name);
    curr->setstreet_name(street_name);

    cout << "Town: ";
    getline(cin, town);
    curr->settown(town);

    while(true){
        cout << "Zip Code: ";
        cin >> zip_code;
        if(validate_zip_code()){
            curr->setzip_code(zip_code);
            break;
        }
        zip_code = "";
    }
    while(true){
        cout << "State: ";
        cin >> state;
        if(state == "NY" || state == "PA" || state == "RI" || state == "NH" || state == "VT" || state == "MA" || state == "CT" || state == "ME"){
            curr->setstate(state);
            break;
        } else {
            cout << "You cannot donate in this state." << endl;
        }
    }
    //put new added donor inside array
    data[donor_indx] = *curr;
    donor_indx += 1;
    cout << "\n";

}

void DonorDatabase::save(string file_name){
    //this function is supposed to save the entire database of donors in a text file
    //why mike lewis? why did you make us do this?
    ofstream file;
    string response = "";
    while(true) {
        cout << "File exists, would you like to override it? (Yes/No)" << endl;
        cin >> response;
        if(response == "Yes"){
            file.open(file_name, ios::out);
            if(file.is_open()){
                for (int i = 0; i < donor_indx; i++){
                    file << i << endl;
                    file << data[i].getuserid() << endl;
                    file << data[i].getpassword() << endl;
                    file << data[i].getlast_name() << endl;
                    file << data[i].getfirst_name() << endl;
                    file << data[i].getage() << endl;
                    file << data[i].getstreet_num() << endl;
                    file << data[i].getstreet_name() << endl;
                    file << data[i].gettown() << endl;
                    file << data[i].getzip_code() << endl;
                    file << data[i].getstate() << endl;
                    file << data[i].getdonated() << endl;
                }
                file.close();
                break;
            } else {
                cout << "File is not detected." << endl;
                while(true){
                    cout << "Would you like to like to choose another file? (Yes/No)" << endl;
                    cin >> response;
                    if(response == "Yes"){
                        string new_file_name;
                        cout << "What is the new file you would like to save to?";
                        cin >> new_file_name;
                        save(new_file_name);
                        break;
                    } else if (response == "No"){
                        break;
                    } else {
                        cout << "Unknown command, please type \"Yes\" or \"No\"." << endl;
                    }
                }

            }
        } else if (response == "No"){
            break;
        } else {
            cout << "Unknown command, please type \"Yes\" or \"No\"." << endl;
        }
    }
}

void DonorDatabase::load(string file_name){
  //this function reads the text file and puts the information in the data array
    ifstream file (file_name);
    string temp_line;
    if(file.is_open()){
        donor_indx = 0;
        // this varibale indicates that there are 12 lines of text per donor
        while(getline(file, temp_line)){
            int idx = stoi(temp_line);
            if(idx > (max_donor-1)){
                break;
            }
            //USERID
            getline(file, temp_line);
            data[idx].setuserid(temp_line);
            //PASSWORD
            getline(file, temp_line);
            data[idx].setpassword(temp_line);
            //LAST NAME
            getline(file, temp_line);
            data[idx].setlast_name(temp_line);
            //FIRST NAME
            getline(file, temp_line);
            data[idx].setfirst_name(temp_line);
            //AGE
            getline(file, temp_line);
            data[idx].setage(stoi(temp_line));
            //STREET NUMBER
            getline(file, temp_line);
            data[idx].setstreet_num(stoi(temp_line));
            //STREET NAME
            getline(file, temp_line);
            data[idx].setstreet_name(temp_line);
            //TOWN
            getline(file, temp_line);
            data[idx].settown(temp_line);
            //ZIP CODE
            getline(file, temp_line);
            data[idx].setzip_code(temp_line);
            //STATE
            getline(file, temp_line);
            data[idx].setstate(temp_line);
            //DONATED
            getline(file, temp_line);
            data[idx].setdonated(stof(temp_line));
            donor_indx++;
        }
        file.close();
    } else {
        cout << "File is not detected. Please make sure that there is a \"data.txt\" file in the same directory as this program." << endl;
    }
}

void DonorDatabase::report(){
    cout << "There are currently " << donor_indx << " in the database:" << endl;
    cout << "Here are the donors:" << endl;
    cout << endl;
    for (int i = 0; i < donor_indx; i++){
        cout << "Donor #" << i + 1 << endl;
        data[i].view();
        cout << "\n";
    }
}
