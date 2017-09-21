#ifndef DON_H
#define DON_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Donor {
 private:
    string last_name, first_name, street_name, town, zip_code, userid, password, state;
    int age, street_num;
    float amount_donated;
 public:
    Donor();
    bool validate_userid();
    bool validate_password();
    bool validate_last_name();
    bool validate_first_name();
    void login();
    void add();
    void save();
    void load();
    void report();
    void manage();
    void passwrd();
    void view();
    void donate();
    void total();
};

#endif
