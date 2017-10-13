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
 public:
    //CONSTRUCTORS
    FBLUserLL();
    //GETTERS
    FBLUserNode* get_head();
    //SETTERS
    void set_head(FBLUserNode* h);
    //OTHER FUNCTIONS
    void login(string ui, string pass);
    void add(string ui, string pw, string fn, string ln);
    void remove(string ui);
    void print_list();
    bool check_userid(string ui);
};

#endif
