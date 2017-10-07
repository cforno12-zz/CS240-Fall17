//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUserLL.h"

using namespace std;

//CONSTRUCTOR
FBLUserLL::FBLUserLL(){
    head = NULL;
}
FBLUserNode* FBLUserLL::get_head(){
    return head;
}
void FBLUserLL::set_head(FBLUserNode* h){
    head = h;
}

void login(){
    //traverse through linked list and find userid == temp_user
}

void add(string ui, string pw, string fn, string ln){
    
}
