#ifndef PNODE_H
#define PNODE_H
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPost.h"
class FBLPost;

class FBLPostNode {
 private:
    FBLPost* data;
    FBLPostNode* next;
 public:
    //CONSTRUCTORS
    FBLPostNode();
    FBLPostNode(FBLPost* fbp);
    ~FBLPostNode();
    //GETTERS
    FBLPost* get_data();
    FBLPostNode* get_next();
    //SETTERS
    void set_data(FBLPost* fbp);
    void set_next(FBLPostNode* fbn);
};

#endif
