#ifndef POST_H
#define POST_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
//user headers
#include "FBLPostLL.h"
#include "FBLPostNode.h"

using namespace std;

class FBLPost{
 private:
    string post;
 public:
    //GETTERS
    string get_post();
    //SETTERS
    void set_post(string p);
    //OTHER FUNCTIONS
    void check_valid_post();
}
