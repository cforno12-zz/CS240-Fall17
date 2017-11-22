#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "DISH.h"

using namespace std;

void print_all(Dish* dish);

int main(){
    Dish* dish = new Dish();
    bool quit = true;
    string cmd;
    while(quit){
        cout << "Command: insert(i), find(f), capitalize(c), all_caps(a), truncate(t), get_shortest(s), get_first(gf), print_all(p), quit(q):" << endl;
        cin >> cmd;
        string temp;
        int temp01;
        if(cmd == "i"){
            cin >> temp;
            dish->insert(temp);
        } else if (cmd == "f"){
            cin >> temp;
            cout << "String is at index: " << dish->find(temp) << endl;
        } else if(cmd == "c"){
            cin >> temp01;
            dish->capitalize(temp01);
        } else if(cmd == "a"){
            cin >> temp01;
            dish->all_caps(temp01);
        } else if(cmd == "t"){
            cout << "Put in the index of the string, then the length of the string" << endl;
            int temp02;
            cin >> temp01;
            cin >> temp02;
            dish->truncate(temp01, temp02);
        } else if(cmd == "s"){
            cout << dish->get_shortest() << endl;
        } else if(cmd == "gf"){
            cout << dish->get_first() << endl;
        } else if(cmd == "q"){
            quit = false;
        } else if(cmd == "p"){
            print_all(dish);
        } else {
            cout << "command not recognized." << endl;
            cmd = "";
        }
    }
}

void print_all(Dish * dish){
    cout << "lH: " << endl;
    dish->print_lH();
    cout << "alpha: " << endl;
    dish->print_alpha();
    cout << "main: " << endl;
    dish->print_main();
}
