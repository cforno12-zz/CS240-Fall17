#ifndef USER_H
#define USER_H
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class FBLUser {
 private:
    string last_name, first_name, password, user_id;
 public:
    // GETTERS
    string get_first_name();
    string get_last_name();
    string get_password();
    string get_user_id();
    // SETTERS
    void set_last_name(string ln);
    void set_first_name(string fn);
    void set_password(string pw);
    void set_suer_id(string ui);
    // OTHER FUNCTIONS
    
};

#endif
