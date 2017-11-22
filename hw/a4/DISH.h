#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "string_obj.h"

using namespace std;

class Dish {
 private:
    vector<String_obj*> main;
    vector<int> alpha;
    vector<int> lH;
    int curr_idx;
 public:
    Dish();
    void print_lH();
    void print_main();
    void print_alpha();
    //functions
    bool insert(string s);
    // insert it regularly in the main vector
    // increment curr_idx
    // calculate length of inserted string
    // insert it into heap of each
    void heapify_lH(int k);
    void heapify_alpha(int k);
    int find(string s);
    // ez
    // for loop
    // and compare strings
    // what is this cs140?
    bool capitalize(int k);
    bool all_caps(int k);
    bool truncate(int k, int i);
    string get_shortest();
    string get_first();
    // given an index in the either indexed vectors
    int get_left_idx(int i);
    int get_right_idx(int i);
    int get_parent_idx(int i);
    void swap_lH(int s, int p);
    void swap_alpha(int s, int p);
};
