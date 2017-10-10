#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLUserLL.h"

using namespace std;

int main(){
    FBLUserLL* linked_list = new FBLUserLL();
    linked_list->add("cforno", "password", "Forno", "Cris");
    linked_list->add("ebaule", "password", "Baule", "Evan");
    linked_list->add("mlewis", "password", "Lewis", "Mike");
    linked_list->print_list();
    cout << endl;
    cout << endl;
    linked_list->remove("mlewis");
    linked_list->remove("ebaule");
    linked_list->remove("cforno");
    cout << "EXPECTED: should be cleared." << endl;
    linked_list->print_list();
}
