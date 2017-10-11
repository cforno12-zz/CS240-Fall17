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

void FBLPostLL::read(){
    if(head && head->get_next()){
        string temp_post = head->get_data()->get_post();
        cout << temp_post << endl;
        
    } else {
        cout << "List is empty." << endl;
    }
}



