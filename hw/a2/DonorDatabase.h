#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <stdlib.h>
#include "Donor.h"
#define MAX_DONORS 1000

using namespace std;

class DonorDatabase {
 private:
    Donor* data;
    string last_name, first_name, street_name, town, zip_code, userid, password, state;
    int age, street_num, donor_indx, curr_donor;
    float donated;
 public:
    DonorDatabase(int donor_num);
    Donor access_data(int idx);
    bool validate_userid();
    bool validate_password();
    bool validate_last_name();
    bool validate_first_name();
    bool validate_zip_code();
	void login();
    void add();
    void save();
    void load();
    void report();
};
#endif
