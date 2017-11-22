#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class String_obj {
 private:
    string data;
    int lH_idx, alpha_idx;
 public:
    String_obj(string s);
    String_obj(string s, int a, int l);
    string get_data();
    int get_lH_idx();
    int get_alpha_idx();
    void set_data(string d);
    void set_lH_idx(int i);
    void set_alpha_idx(int i);
};
