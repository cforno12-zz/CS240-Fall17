#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPostLL.h"

FBLPostLL::FBLPostLL(){
    head = nullptr;
}

FBLPostNode* FBLPostLL::get_head(){
    return head;
}

void FBLPostLL::set_head(FBLPostNode* h){
    head = h;
}

void FBLPostLL::add(FBLPostNode* post_node){
    if(head == nullptr){
        head = post_node;
    } else {
        post_node->set_next(head);
        head = post_node;
    }
}
void FBLPostLL::read(){
    if(head && head->get_next()){
        FBLPostNode* curr = head;
        FBLPostNode* previous = nullptr;
        while (curr){
            previous = curr;
            curr = curr->get_next();
        }
        string temp_post = previous->get_data()->get_post();
        cout << "Most recent post: "<< temp_post << endl;
        //remove post
        delete previous;
        previous = nullptr;
    } if (head){
        string temp_post = head->get_data()->get_post();
        cout << "Most recent post: " << temp_post << endl;
        delete head;
        head = nullptr;
    } else {
        cout << "List is empty." << endl;
    }
}
