#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPost.h"

FBLPost::FBLPost(string p){
    post = p;
    comments = new FBLCommentLL();
}

FBLPost::FBLPost(FBLPost* obj){
    post = obj->get_post();
    likes = obj->get_likes();
    comments = obj->get_comment_list();
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
FBLCommentLL* FBLPost::get_comment_list(){
    return comments;
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
