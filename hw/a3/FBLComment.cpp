//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLComment.h"

using namespace std;

FBLComment::FBLComment(){
    comment = "";
    user_first_name = "";
    user_last_name = "";
}

FBLComment::FBLComment(string c){
    comment = c;
}
FBLComment::FBLComment(string c, string fn, string ln){
    comment = c;
    user_first_name = fn;
    user_last_name = ln;
}
FBLComment::~FBLComment(){}

string FBLComment::get_comment(){
    return comment;
}
string FBLComment::get_first_name(){
    return user_first_name;
}
string FBLComment::get_last_name(){
    return user_last_name;
}

void FBLComment::set_comment(string c) {
    comment = c;
}
void FBLComment::set_first_name(string fn){
    user_first_name = fn;
}
void FBLComment::set_last_name(string ln){
    user_last_name = ln;
}


