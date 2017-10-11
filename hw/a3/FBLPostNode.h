#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLPost.h"

class FBLPostNode {
 private:
    FBLPost* data;
    FBLPostNode* next;
 public:
    //CONSTRUCTORS
    FBLPostNode();
    FBLPostNode(FBLPost* fbp);
    //GETTERS
    FBLPost* get_data();
    FBLPostNode* get_next();
    //SETTERS
    void set_data(FBLPost* fbp);
    void set_next(FBLPostNode* fbn);
};
