#ifndef POST_H
#define POST_H
//libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "FBLCommentLL.h"

using namespace std;

class FBLPost {
 private:
    string post;
    int likes;
    FBLCommentLL* comments;
 public:
    //CONSTRUCTOR
    FBLPost(string p);
    FBLPost(FBLPost* obj);
    ~FBLPost();
    //GETTERS
    string get_post();
    int get_likes();
    FBLCommentLL* get_comment_list();
    //SETTERS
    void set_post(string p);
    //OTHER FUNCTIONS
    void upvote();
    void add_comment(FBLCommentNode* fpn);
    void print_comments_AZ();
    void print_comments_ZA();
};

#endif
