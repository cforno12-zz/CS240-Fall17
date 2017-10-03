#ifndef LINKED_H
#define LINKED_H
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class FBLUserLL {
 private:
    FBLUser user;
 public:
    void login();
    void add();
    void remove();
    void clear();
};

#endif
