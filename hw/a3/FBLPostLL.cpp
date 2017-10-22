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
//pops oldest post
void FBLPostLL::read(){
    if(head && head->get_next()){
        FBLPostNode* curr = head;
        FBLPostNode* previous = nullptr;
        while (curr->get_next()){
            previous = curr;
            curr = curr->get_next();
        }
        string temp_post = curr->get_data()->get_post();
        cout << "Most recent post:"<< temp_post << endl;
        //remove post
        previous->set_next(nullptr);
        delete curr;
        curr = nullptr;
    } else if (head){
        string temp_post = head->get_data()->get_post();
        cout << "Most recent post:" << temp_post << endl;
        delete head;
        head = nullptr;
    } else {
        cout << "Nothing to READ." << endl;
    }
}

void FBLPostLL::print_posts(){
    if(head != nullptr){
        if(!head->get_next()){
            FBLPostNode* curr = head;
            cout << "->";
            string temp = curr->get_data()->get_post();
            cout << temp << endl;
        } else {
            FBLPostNode* curr = head;
            int counter = 0;
            while(curr != nullptr) {
                counter++;
                cout << "->";
                cout << curr->get_data()->get_post() << endl;
                curr = curr->get_next();
            }
        }
    }
    else {
        cout << "This user has not posted anything." << endl;
    }

}
