//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUserLL.h"
#include "FBLPostLL.h"

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

void FBLUserLL::login(string ui, string pass){
    //traverse through linked list and find userid == temp_user
    bool user_found = false;
    if(head != nullptr){
        FBLUserNode* curr = head;
        while(curr != nullptr){
            if(curr->get_data()->get_user_id() == ui && curr->get_data()->get_password() == pass){
                //user found
                user_found = true;
                string cmd = "";
                bool quit = false;
                string post = "";
                string fuser = "";
                FBLUser* user = curr->get_data();
                cout << "Welcome " << ui << "!"<< endl;
                do {
                    cout << "Please select a command: [\"POST\", \"READ\", or \"LOGOUT\"]:" << endl;
                    cin >> cmd;
                    if(cmd == "POST"){
                        getline(cin, post);
                        user->post(post);
                    } else if(cmd == "READ"){
                        user->read();
                    }else if(cmd == "print"){
                        user->print_posts();
                    } else if(cmd == "LOGOUT"){
                        quit = true;
                    } else if(cmd == "FRIEND"){
                        cin >> fuser;
                        //check if fuser is in the linked list..
                        if(this->check_userid(fuser)){
                            FBLUser* curr_friend = nullptr;
                            FBLUserNode* finding_friend = head;
                            while(finding_friend != nullptr) {
                                if(finding_friend->get_data()->get_user_id() == fuser){
                                    //found friend.
                                    curr_friend = finding_friend->get_data();
                                    break;
                                }
                                finding_friend = finding_friend->get_next();
                            }
                            //this stores the name of the friend into the vector
                            //the vector lies inside the user class
                            user->make_friend(curr_friend);
                        } else {
                            cout << "User does not exist." << endl;
                        }
                    } else if(cmd == "MYFRIENDS"){
                        //display all the friends in the current linked list
                        user->print_friends();
                    } else if(cmd == "MYFEED"){
                        //print friends posts.
                        user->feed();
                    } else if(cmd == "MYWALL"){
                        //print your posts.
                        cout << "This is your wall:" << endl;
                        user->print_posts();
                    } else {
                        cout << "Input not valid." << endl;
                    }
                } while (!quit);
                break;
            } else {
                curr = curr->get_next();
            }
        }
        if(user_found == false){
            cout << "User ID does not exist or incorrect password." << endl;
        }
    } else {
        cout << "List is empty" << endl;
    }
}
//if username is already being used, it returns true
bool FBLUserLL::check_userid(string ui){
    bool retVal = false;
    FBLUserNode* curr = head;
    while (curr != nullptr){
        if(curr->get_data()->get_user_id() == ui){
            retVal = true;
            break;
        }
        curr = curr->get_next();
    }
    return retVal;
}

void FBLUserLL::add(string ui, string pw, string fn, string ln){
    bool check = this->check_userid(ui);
    if(check == true){
        cout << "User ID already taken." << endl;
        return;
    }
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
                        curr = nullptr;
                        deleteFlag = true;
                        break;
                    } else {
                        //if this is the head of the list
                        head = curr->get_next();
                        delete curr;
                        curr = nullptr;
                        deleteFlag = true;
                        break;
                    }
                } else {
                    //if this is the end of the list
                    previous->set_next(nullptr);
                    delete curr;
                    curr = nullptr;
                    deleteFlag = true;
                    break;
                }
            }
            previous = curr;
            curr = curr->get_next();
        }
    } else if(head != nullptr && head->get_data() == nullptr){
        //if it is the last node
        if(head->get_data()->get_user_id() == ui){
            //TODO: fix remove when last node in the list (not part of phase 1)
            // i think i fixed this... DONE
            delete head;
            head = nullptr;
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
        if(!head->get_next()){
            FBLUserNode* curr = head;
            cout << "-----------------------------------------------" << endl;
            cout << "User #0" << endl;
            curr->get_data()->print_user();
        } else {
            FBLUserNode* curr = head;
            int counter = 0;
            while(curr) {
                cout << "-----------------------------------------------" << endl;
                cout << "User #" << counter << endl;
                counter++;
                curr->get_data()->print_user();
                curr = curr->get_next();
            }
        }
    }
    else {
        cout << "List is empty." << endl;
    }
}
