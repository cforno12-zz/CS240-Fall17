//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUserLL.h"

using namespace std;

//CONSTRUCTOR
FBLUserLL::FBLUserLL(){
    head = nullptr;
}
FBLUserNode* FBLUserLL::get_head(){
    return head;
}
void FBLUserLL::set_head(FBLUserNode* h){
    head = h;
}

void FBLUserLL::login(string ui){
    //traverse through linked list and find userid == temp_user
    bool user_found = false;
    if(head != nullptr){
        FBLUserNode* curr = head;
        while(curr != nullptr){
            if(curr->get_data()->get_user_id() == ui){
                //user found
                user_found = true;
                string cmd = "";
                cout << "Welcome " << ui << "! "<< endl; 
                do {
                    cout << "Please select a command: ['POST' or 'LOGOUT']:" << endl;
                    cin >> cmd;
                    if(cmd == "POST"){
                        //post some shit boi
                    }
                } while (cmd != "LOGOUT");
                break;
            } else {
                curr = curr->get_next();
            }
        }
    } else {
        cout << "List is empty" << endl;
    }
    if(user_found == false){
        cout << "User ID does not exist." << endl;
    }
}

void FBLUserLL::add(string ui, string pw, string fn, string ln){
    //making a new user obj
    FBLUser* temp_user = new FBLUser();
    temp_user->set_user_id(ui);
    temp_user->set_password(pw);
    temp_user->set_first_name(fn);
    temp_user->set_last_name(ln);
    //setting user obj into node
    FBLUserNode* temp = new FBLUserNode(temp_user);
    //setting the node to the beginning of the list so that the runtime is constant :)
    if(head == nullptr){
        head = temp;
    } else {
        temp->set_next(head);
        head = temp;
    }
}

void FBLUserLL::remove(string ui){
    bool deleteFlag = false;
    if(head != nullptr && head->get_next() != nullptr){
        FBLUserNode* curr = head;
        FBLUserNode* previous = nullptr;
        while(curr != nullptr){
            if(curr->get_data()->get_user_id() == ui){
                if(curr->get_next() != nullptr){
                    if(previous != nullptr){
                        previous->set_next(curr->get_next());
                        delete curr;
                        deleteFlag = true;
                        break;
                    } else {
                        //if this is the head of the list
                        head = curr->get_next();
                        delete curr;
                        deleteFlag = true;
                        break;
                    }
                } else {
                    //if this is the end of the list
                    previous->set_next(nullptr);
                    delete curr;
                    deleteFlag = true;
                    break;
                }
            }
            previous = curr;
            curr = curr->get_next();
        }
    }else if(head != nullptr){
        if(head->get_data()->get_user_id() == ui){
            delete head;
            deleteFlag = true;
        } else {
            cout << "User ID does not exist." << endl;
        }
    } else {
        cout << "List is empty." << endl;
    }
    if(deleteFlag == false){
        cout << "User ID was not found." << endl;
    }
}

void FBLUserLL::print_list(){
    if(head != nullptr){
        FBLUserNode* curr = head;
        int counter = 0;
        while(curr != nullptr){
            cout << "-----------------------------------------------" << endl;
            cout << "User #" << counter << endl;
            counter++;
            curr->get_data()->print_user();
            curr = curr->get_next();
        }
    } else {
        cout << "List is empty." << endl;
    }
}
