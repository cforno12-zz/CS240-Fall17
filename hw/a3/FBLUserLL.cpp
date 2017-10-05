//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUser.h"
#inlcude "FBLUserNode.h"

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


