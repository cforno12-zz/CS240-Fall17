#ifndef ULINKED_H
#define ULINKED_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUserNode.h"

using namespace std;

class FBLUserLL {
 private:
    FBLUserNode* head;
    string temp_user, temp_pass, temp_first, temp_last;
 public:
    //CONSTRUCTORS
    FBLUserLL();
    //GETTERS
    FBLUserNode* get_head();
    //SETTERS
    void set_head(FBLUserNode* h);
    //OTHER FUNCTIONS
    void login();
    void add();
    void remove();
    void find();
    void clear();
};

#endif
