#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "string_obj.h"

using namespace std;


String_obj::String_obj(string s){
    data = s;
}

String_obj::String_obj(string s, int a, int l){
    data = s;
    alpha_idx = a;
    lH_idx = l;
}

string String_obj::get_data(){
    return data;
}

int String_obj::get_lH_idx(){
    return lH_idx;
}

int String_obj::get_alpha_idx(){
    return alpha_idx;
}

void String_obj::set_data(string d){
    data = d;
}
void String_obj::set_lH_idx(int i){
    lH_idx = i;
}
void String_obj::set_alpha_idx(int i){
    alpha_idx = i;
}
