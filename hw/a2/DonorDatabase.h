#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#define MAX_DONORS 1000

using namespace std;

class DonorDatabase {
 private:
    Donor data[MAX_DONORS];
    string last_name, first_name, street_name, town, zip_code, userid, password, state;
    int age, street_num, donor_indx;
    float donated;
 public:
    DonorDatabase();
    Donor access_data(int idx){
        return data[idx];
    }
    bool validate_userid();
    bool validate_password();
    bool validate_last_name();
    bool validate_first_name();
    bool validate_zip_code();
    int find_num_donors();  //returns the number of Donors in the array minus 1
	void login();
    void add();
    void save();
    void load();
    void report();
};
#endif
