#ifndef USER_H
#define USER_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class FBLUser {
 private:
    string first_name, last_name, password, user_id;
 public:
    //CONSTRUCTORS
    FBLUser();
    // GETTERS
    string get_first_name();
    string get_last_name();
    string get_password();
    string get_user_id();
    // SETTERS
    void set_first_name(string fn);
    void set_last_name(string ln);
    void set_password(string pw);
    void set_user_id(string ui);
    // OTHER FUNCTIONS
    void print_user();
    //void post(); //creates a FB posting
    //void read(); //displays the first FBLPost inside the current user
};

#endif
