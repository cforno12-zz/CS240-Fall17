//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLUserLL.h"
#include "FBLPostLL.h"
#include "FBLCommentLL.h"

using namespace std;

//CONSTRUCTOR
FBLUserLL::FBLUserLL(){
    head = nullptr;
}

FBLUserLL::~FBLUserLL()
{
    if(head)delete head;
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
                cout << "\tWelcome " << ui << "!"<< endl;
                do {
                    cout << "\tPlease select a command: [\"POST\", \"READ\", \"FRIEND\", \"MYFRIENDS\", \"MYFEED\", \"MYWALL\", or \"LOGOUT\"]:" << endl;
                    cout << "\t";
                    cin >> cmd;
                    if(cmd == "POST"){
                        getline(cin, post);
                        user->post(post);
                    } else if(cmd == "READ"){
                        //cout <<"\t" << endl;
                        if(!user->get_feed()->get_head()){
                            cout << "\tNothing to read." << endl;
                            continue;
                        }
                        FBLPost* post = user->get_feed()->get_last_node()->get_data();
                        bool quit = false;
                        string cmd = "";
                        cout << "\t\tLikes: "<< post->get_likes() << " " << post->get_post() << endl;
                        while(!quit){
                            cout << "\t\tWhat would you like to do to this post? [\"LIKE\", \"COMMENT\" \"READ_AZ\", \"READ_ZA\", or \"DONE\"]:" << endl;
                            cout << "\t\t";
                            cin >> cmd;
                            if(cmd == "LIKE"){
                                post->upvote();
                            } else if (cmd == "COMMENT"){
                                string cmmt = "";
                                getline(cin, cmmt);
                                FBLComment* temp = new FBLComment(cmmt, user->get_first_name(), user->get_last_name());
                                FBLCommentNode* temp_node = new FBLCommentNode(temp);
                                post->add_comment(temp_node);
                                //put cmmt in the same post in everyone's feed.
                            } else if(cmd == "READ_AZ"){
                                post->print_comments_AZ();
                            } else if (cmd == "READ_ZA"){
                                post->print_comments_ZA();
                            } else if (cmd == "DONE"){
                                quit = true;
                            } else {
                                cout << "\t\tUnknown command." << endl;
                            }
                        }
                        quit = false;
                        //"popping oldest post in user's feed"
                        FBLPostNode* penultimum_post = user->get_feed()->get_penultimum_node();
                        if(penultimum_post){
                            user->get_feed()->get_penultimum_node()->set_next(nullptr);
                            delete user->get_feed()->get_last_node();
                        } else {
                            //there is only the head
                            user->get_feed()->set_head(nullptr);
                            delete user->get_feed()->get_head();
                        }
                        //TODO: pop the last node of the feed.
                    } else if(cmd == "LOGOUT"){
                        quit = true;
                    } else if(cmd == "FRIEND"){
                        cin >> fuser;
                        //check if fuser is in the linked list..
                        if(this->check_userid(fuser) && fuser != user->get_user_id()){
                            FBLUser* add_me = nullptr;
                            FBLUserNode* curr_friend = head;
                            while(curr_friend != nullptr) {
                                if(curr_friend->get_data()->get_user_id() == fuser){
                                    //found friend.
                                    add_me = curr_friend->get_data();
                                    break;
                                }
                                curr_friend = curr_friend->get_next();
                            }
                            //this stores the pointer of the friend into the vector
                            //the vector lies inside the user class
                            user->make_friend(add_me);
                            add_me->make_friend(user);
                        } else {
                            cout << "User does not exist." << endl;
                        }
                    } else if(cmd == "MYFRIENDS"){
                        //display all the friends in the current linked list
                        user->print_friends();
                    } else if(cmd == "MYFEED"){
                        //print friends posts.
                        cout << "\t\tThis is your feed:" << endl;
                        user->print_feed();
                    } else if(cmd == "MYWALL"){
                        //print your posts.
                        cout << "\t\tThis is your wall:" << endl;
                        user->print_wall();
                    } else {
                        cout << "\tInput not valid." << endl;
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
//i created this function in hopes that we would delete users from the linked list.
// doesn't work either...
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
            curr->get_data()->print_user();
        } else {
            FBLUserNode* curr = head;
            while(curr != nullptr) {
                curr->get_data()->print_user();
                curr = curr->get_next();
            }
        }
    }
    else {
        cout << "List is empty." << endl;
    }
}

FBLUserLL* FBLUserLL::sort_users(FBLUserLL* main_list){
    //this is a merge sort for users

    //merge sort is described on the internet that it is the best
    //sort for linked lists

    FBLUserNode* this_head = main_list->get_head();
    FBLUserLL* left = new FBLUserLL();
    FBLUserLL* right = new FBLUserLL();

    //base case
    if(this_head->get_next() == nullptr || this_head == nullptr){
        return main_list;
    }

    // recursive case
    FBLUserNode* curr = this_head;
    bool a = true;
    while(curr != nullptr){
        FBLUser* obj = curr->get_data();
        if (a){
            FBLUserNode* new_left = new FBLUserNode(obj);
            left->add_merge(new_left);
        } else {
            FBLUserNode* new_right = new FBLUserNode(obj);
            right->add_merge(new_right);
        }
        a = !a;
        curr = curr->get_next();
    }

    left = sort_users(left);
    right = sort_users(right);

    FBLUserLL* result = merge(left, right); 
    delete left;
    delete right;
    return result;

    //divide list into 2 halves
    //sort the two halfs
    //merge the two sorted lists

}

FBLUserLL* FBLUserLL::merge(FBLUserLL* left, FBLUserLL* right){
    FBLUserLL* result = new FBLUserLL();
    FBLUserNode* left_curr = left->get_head();
    FBLUserNode* right_curr = right->get_head();

    while(left_curr && right_curr){
        FBLUser* left_data = left_curr->get_data();
        FBLUser* right_data = right_curr->get_data();
        if(left_data->get_last_name() <= right_data->get_last_name()){
            FBLUserNode* new_left = new FBLUserNode(left_data);
            result->add_merge(new_left);
            left_curr = left_curr->get_next();
        } else {
            FBLUserNode* new_right = new FBLUserNode(right_data);
            result->add_merge(new_right);
            right_curr = right_curr->get_next();
        }
    }

    while(left_curr){
        FBLUserNode* new_left = new FBLUserNode(left_curr->get_data());
        result->add_merge(new_left);
        left_curr = left_curr->get_next();
    }
    while(right_curr){
        FBLUserNode* new_right = new FBLUserNode(right_curr->get_data());
        result->add_merge(new_right);
        right_curr = right_curr->get_next();
    }
    return result;
}

void FBLUserLL::add_node(FBLUserNode* node){
    if(head == nullptr){
        head = node;
        head->set_next(nullptr);
    } else {
        node->set_next(head);
        head = node;
    }
}

FBLUserNode* FBLUserLL::get_last_node(){
    FBLUserNode* retVal = nullptr;
    if(head && head->get_next()){
        FBLUserNode* curr =  head;
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

void FBLUserLL::add_merge(FBLUserNode* user){
    if(!head) {
        head = user;
        head->set_next(nullptr);
        return;
    }
    FBLUserNode* temp = head;
    while(temp->get_next() != nullptr){
        temp = temp->get_next();
    }
    temp->set_next(user);
}
