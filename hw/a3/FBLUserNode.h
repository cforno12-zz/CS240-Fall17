#ifdef UNODE_H
#define UNODE_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUser.h"
#include "FBLUserLL.h"

using namespace std;

class FBLUserNode {
 private:
    FBLUser data;
    FBLUserNode* next;
 public:
    //CONSTRUCTORS
    FBLUserNode();
    FBLUserNode(FBLUser fbu);
    //GETTERS
    FBLUser get_data();
    FBLUserNode* get_next();
    //SETTERS
    void set_data(FBLUser fbu);
    void set_next(FBLUserNode* fbn);
    //CONSTRUCTORS
    FBLUserNode();
    FBLUserNode(FBLUser fbu);
};

#endif
