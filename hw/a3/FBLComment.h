#ifndef COMMENT_H
#define COMMENT_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class FBLComment {
 private:
    string comment;
    string user_first_name, user_last_name;
 public:
    //CONSTRUCTORS
    FBLComment();
    FBLComment(string c);
    FBLComment(string c, string fn, string ln);
    ~FBLComment();
    //GETTERS
    string get_comment();
    string get_first_name();
    string get_last_name();
    //SETTERS
    void set_comment(string c);
    void set_first_name(string fn);
    void set_last_name(string ln);
};

#endif
