//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUserNode.h"

using namespace std;

//CONSTRUCTORS
FBLUserNode::FBLUserNode(){
    next = nullptr;
}
FBLUserNode::FBLUserNode(FBLUser* fbu){
    data = fbu;
    next = nullptr;
}
//GETTERS
FBLUser* FBLUserNode::get_data(){
    return data;
}
FBLUserNode* FBLUserNode::get_next(){
    return next;
}
//SETTERS
void FBLUserNode::set_data(FBLUser* fbu){
    data = fbu;
}
void FBLUserNode::set_next(FBLUserNode* fbn){
    next = fbn;
}
