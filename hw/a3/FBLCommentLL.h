#ifndef CLINKED_H
#define CLINKED_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLCommentNode.h"

class FBLCommentLL {
 private:
    FBLCommentNode* head;
 public:
    //CONSTRUCTORS
    FBLCommentLL();
    ~FBLCommentLL();
    //GETTERS
    FBLCommentNode* get_head();
    //SETTERS
    void set_head(FBLCommentNode* comment_node);
    //OTHER FUNCTIONS
    FBLCommentNode* get_last_node();
    void add(FBLCommentNode* post_node);
    //void read();
    void print_AZ();
    void print_ZA();
};

#endif
