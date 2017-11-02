#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPost.h"

FBLPost::FBLPost(string p){
    post = p;
    comments = new FBLCommentLL();
}

FBLPost::~FBLPost(){}

string FBLPost::get_post(){
    return post;
}

void FBLPost::set_post(string p){
    post = p;
}
int FBLPost::get_likes(){
    return likes;
}
void FBLPost::upvote(){
    likes++;
}
void FBLPost::add_comment(FBLCommentNode* fpn){
    comments->add(fpn);
}

void FBLPost::print_comments_AZ(){
    comments->print_AZ();
}

void FBLPost::print_comments_ZA(){
    comments->print_ZA();
}
