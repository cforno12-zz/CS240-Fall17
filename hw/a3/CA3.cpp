#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <vector>

#include "FBLUserLL.h"

using namespace std;

int main(){
    FBLUserLL* linked_list = new FBLUserLL();
    cout << "Welcome to Facebook Lite!" << endl;
    string cmd, temp_userid, temp_password, temp_first_name, temp_last_name;
    bool quit = false;
    while (!quit){
        cout << "Please enter a command: [\"CREATE\", \"LOGIN\", \"USERS\", \"SORTUSERS\" or \"QUIT\"]" << endl;
        cin >> cmd;
        if(cmd == "CREATE"){
            cin >> temp_userid;
            cin >> temp_password;
            cin >> temp_first_name;
            cin >> temp_last_name;
            if(linked_list->check_userid(temp_userid)){
                cout << "User ID already taken." << endl;
                continue;
            }
            FBLUser* new_user = new FBLUser(temp_last_name, temp_first_name, temp_password, temp_userid);
            FBLUserNode* new_user_node = new FBLUserNode(new_user);
            linked_list->add_node(new_user_node);
        } else if (cmd == "LOGIN"){
            cin >> temp_userid;
            cin >> temp_password;
            linked_list->login(temp_userid, temp_password);
        } else if (cmd == "USERS"){
            linked_list->print_list();
        } else if(cmd == "SORTUSERS"){
            linked_list = linked_list->sort_users(linked_list);
        } else if (cmd == "QUIT"){
            quit = true;
        } else {
            cout << "Command not found." << endl;
        }
    }
    //delete linked_list;
}
