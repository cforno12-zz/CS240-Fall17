#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPostLL.h"

FBLPostLL::FBLPostLL(){
    head = nullptr;
}

FBLPostLL::~FBLPostLL(){
    if(head){
        delete head;
    }
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
//pops oldest post
// FBLPost* FBLPostLL::read(){
//     FBLPost* ret_val = nullptr;
//     if(head && head->get_next()){
//         FBLPostNode* curr = head;
//         FBLPostNode* previous = nullptr;
//         while (curr->get_next()){
//             previous = curr;
//             curr = curr->get_next();
//         }
//         ret_val = curr->get_data();
//         //cout << "\t\tMost recent post:"<< temp_post << endl;
//         //remove post
//         previous->set_next(nullptr);
//         //delete curr;
//         //curr = nullptr;
//     } else if (head){
//         ret_val = head->get_data();
//         //cout << "\t\tMost recent post:" << temp_post << endl;
//         //delete head;
//         //head = nullptr;
//     } else {
//         cout << "\t\tNothing to READ." << endl;
//     }
//     return ret_val;
// }

void FBLPostLL::print_posts(){
    if(head != nullptr){
        FBLPostNode* curr = head;
        while(curr != nullptr) {
            cout << "\t\t\t->";
            cout << curr->get_data()->get_post() << "# of Likes: " << curr->get_data()->get_likes() <<endl;
            curr = curr->get_next();
        }
    } else {
        cout << "\t\t\tNo posts available." << endl;
    }

}


FBLPostNode* FBLPostLL::get_last_node(){
    FBLPostNode* retVal = nullptr;
    if(head && head->get_next()){
        FBLPostNode* curr =  head;
        FBLPostNode* prev = nullptr;
        while(curr->get_next()){
            prev = curr;
            curr = curr->get_next();
        }
        retVal = curr;
    } else if (head){
        retVal = head;
    } else {
        cout << "\t\tThere is nothing in the list." << endl;
    }
    return retVal;
}
