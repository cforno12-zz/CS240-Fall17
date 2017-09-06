#ifndef DON_H
#define DON_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Donor {
 private:
    string last_name, first_name, street_name, town, zip_code;
    int age, street_num;
    float amount_donated, tot;
 public:
    Donor();
    void add();
    void view();
    void donate();
    void total();
};

#endif
