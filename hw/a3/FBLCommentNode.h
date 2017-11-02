#ifndef CNODE_H
#define CNODE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLComment.h"

class FBLCommentNode {
 private:
    FBLCommentNode* prev;
    FBLComment* data;
    FBLCommentNode* next;
 public:
    //CONSTRUCTORS
    FBLCommentNode();
    FBLCommentNode(FBLComment* fbc);
    ~FBLCommentNode();
    //GETTERS
    FBLCommentNode* get_prev();
    FBLCommentNode* get_next();
    FBLComment* get_data();
    //SETTERS
    void set_data(FBLComment* fbc);
    void set_next(FBLCommentNode* fnc);
    void set_prev(FBLCommentNode* fnc);
};

#endif
