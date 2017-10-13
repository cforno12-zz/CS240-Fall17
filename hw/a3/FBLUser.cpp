//libraries
#include <stdlib.h>
#include <iostream>
#include <string.h>
//user headers
#include "FBLUser.h"
#include "FBLPostLL.h"

FBLUser::FBLUser(){
    last_name = "";
    first_name = "";
    password = "";
    user_id = "";
    
}

//GETTERS
string FBLUser::get_first_name(){
    return first_name;
}
string FBLUser::get_last_name(){
    return last_name;
}
string FBLUser::get_password(){
    return password;
}
string FBLUser::get_user_id(){
    return user_id;
}
//SETTERS
void FBLUser::set_first_name(string fn){
    first_name = fn;
}
void FBLUser::set_last_name(string ln){
    last_name = ln;
}
void FBLUser::set_password(string pw){
    password = pw;
}
void FBLUser::set_user_id(string ui){
    user_id = ui;
}
//OTHER FUNCTIONS
void FBLUser::print_user(){
    cout << "User: " << user_id << endl;
    cout << "Password: " << password << endl;
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
}
