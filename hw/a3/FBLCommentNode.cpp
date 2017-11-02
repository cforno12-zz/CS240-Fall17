//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLCommentNode.h"

using namespace std;

//CONSTRUCTORS
FBLCommentNode::FBLCommentNode(){
    prev = nullptr;
    next = nullptr;
    data = nullptr;
}
FBLCommentNode::FBLCommentNode(FBLComment* fbc){
    prev = nullptr;
    data = fbc;
    next = nullptr;
}
FBLCommentNode::~FBLCommentNode(){
    if(prev) delete prev;
    if(next) delete next;
    if(data) delete data;
}
//GETTERS
FBLComment* FBLCommentNode::get_data(){
    return data;
}
FBLCommentNode* FBLCommentNode::get_next(){
    return next;
}
FBLCommentNode* FBLCommentNode::get_prev(){
    return prev;
}
//SETTERS
void FBLCommentNode::set_data(FBLComment* fbc){
    data = fbc;
}
void FBLCommentNode::set_next(FBLCommentNode* fnc){
    next = fnc;
}
void FBLCommentNode::set_prev(FBLCommentNode* fnc){
    prev = fnc;
}
