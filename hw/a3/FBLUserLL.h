#ifndef ULINKED_H
#define ULINKED_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUser.h"
#include "FBLUserNode.h"
//class FBLUserNode;

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
    void login();
    void add();
    void remove();
    void find();
    void clear();
};

#endif
