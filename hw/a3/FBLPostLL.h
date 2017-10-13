#ifndef PLINKED_H
#define PLINKED_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPostNode.h"

class FBLPostLL {
 private:
    FBLPostNode* head;
 public:
    //CONSTRUCTOR
    FBLPostLL();
    //GETTERS
    FBLPostNode* get_head();
    //SETTERS
    void set_head(FBLPostNode* h);
    //OTHER FUNCTIONS
    void add(FBLPostNode* post_node);
    void read();
};

#endif
