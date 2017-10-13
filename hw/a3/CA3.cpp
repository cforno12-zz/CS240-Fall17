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
        cout << "Please enter a command: [\"CREATE\", \"LOGIN\", or \"QUIT\"]" << endl;
        cin >> cmd;
        if(cmd == "CREATE"){
            cin >> temp_userid;
            cin >> temp_password;
            cin >> temp_first_name;
            cin >> temp_last_name;
            linked_list->add(temp_userid, temp_password, temp_first_name, temp_last_name);
        } else if (cmd == "LOGIN"){
            cin >> temp_userid;
            cin >> temp_password;
            linked_list->login(temp_userid, temp_password);
        } else if (cmd == "PRINT"){
            linked_list->print_list();
        } else if (cmd == "QUIT"){
            quit = true;
        } else {
            cout << "Command not found." << endl;
        }
    }
}
