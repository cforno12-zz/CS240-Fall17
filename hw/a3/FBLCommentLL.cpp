#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLCommentLL.h"

FBLCommentLL::FBLCommentLL(){
    head = nullptr;
}

FBLCommentLL::~FBLCommentLL(){
    if(head){
        delete head;
    }
}

FBLCommentNode* FBLCommentLL::get_head(){
    return head;
}

void FBLCommentLL::set_head(FBLCommentNode* h){
    head = h;
}

void FBLCommentLL::add(FBLCommentNode* post_node){
    if(head == nullptr){
        head = post_node;
    } else {
        post_node->set_next(head);
        head->set_prev(post_node);
        head = post_node;
    }
}

void FBLCommentLL::print_AZ(){
    cout << "Printing in order..." << endl;
    if(head){
        FBLCommentNode* curr = head;
        while(curr){
            FBLComment* cmmt = curr->get_data();
            cout << cmmt->get_first_name() << " " << cmmt->get_last_name() << " commented:" << cmmt->get_comment() << endl;
            curr = curr->get_next();
        }
    } else {
        cout << "There are no comments to display." << endl;
    }
}
void FBLCommentLL::print_ZA(){
    if(head){
        cout << "Printing in reverse order..." << endl;
        FBLCommentNode* curr = this->get_last_node();
        while(curr){
            FBLComment* cmmt = curr->get_data();
            cout << cmmt->get_first_name() << " " << cmmt->get_last_name() << " commented:" << cmmt->get_comment() << endl;
            curr = curr->get_prev();
        }
    } else {
        cout << "There are no comments to display." << endl;
    }
}

FBLCommentNode* FBLCommentLL::get_last_node(){
    FBLCommentNode* retVal = nullptr;
    if(head && head->get_next()){
        FBLCommentNode* curr =  head;
        while(curr->get_next()){
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

