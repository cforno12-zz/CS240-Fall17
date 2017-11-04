#ifndef PLINKED_H
#define PLINKED_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPostNode.h"
class FBLPostNode;

class FBLPostLL {
 private:
    FBLPostNode* head;
 public:
    //CONSTRUCTOR
    FBLPostLL();
    ~FBLPostLL();
    //GETTERS
    FBLPostNode* get_head();
    //SETTERS
    void set_head(FBLPostNode* h);
    //OTHER FUNCTIONS
    FBLPostNode* get_penultimum_node();
    FBLPostNode* get_last_node();
    void add(FBLPostNode* post_node);
    //FBLPost* read();
    void read_helper(FBLPostNode* fpn);
    void print_posts();
};

#endif
