#ifndef POST_H
#define POST_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class FBLPost{
 private:
    string post;
 public:
    //CONSTRUCTOR
    FBLPost(string p);
    ~FBLPost();
    //GETTERS
    string get_post();
    //SETTERS
    void set_post(string p);
};
#endif
