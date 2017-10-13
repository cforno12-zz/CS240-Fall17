#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPost.h"

FBLPost::FBLPost(string p){
    post = p;
}

string FBLPost::get_post(){
    return post;
}

void FBLPost::set_post(string p){
    post = p;
}
