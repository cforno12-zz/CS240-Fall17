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
    string cmd = "";
    bool quit = false;
    while (!quit){
        cout << "Please enter a command: [\"CREATE\", \"LOGIN\", or \"LOGOUT\"]" << endl;
        getline(cin, cmd);
        string buff = "";
        stringstream stream(cmd);
        vector<string> user_line;
        user_line.clear();
        while(stream >> buff) {
            user_line.push_back(buff);
            if(user_line[0] == "CREATE"){
                linked_list->add(user_line[1], user_line[2], user_line[3], user_line[4]);
                continue;
            } else if (user_line[0] == "LOGIN"){
                linked_list->login(user_line[1]);
            } else if (user_line[0] == "PRINT"){
                linked_list->print_list();
            } else if (user_line[0] == "LOGOUT"){
                quit = true;
            } else {
                cout << "Command not recognized." << endl;
            }
        }
    }
}
