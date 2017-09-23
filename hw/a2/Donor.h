#ifndef DON_H
#define DON_H
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Donor {
 private:
    string last_name, first_name, street_name, town, zip_code, userid, password, state;
    enum State {NY, PA, RI, NH, VT, MA, CT, ME};
    int age, street_num;
    float donated;
 public:
    Donor();
    //getters
    string getlast_name();
    string getfirst_name();
    string getstreet_name();
    string gettown();
    string getzip_code();
    string getuserid();
    string getpassword();
    string getstate();
    int getage();
    int getstreet_num();
    float getdonated();
    //setters
    void setlast_name(string ln);
    void setfirst_name(string fn);
    void setstreet_name(string sn);
    void settown(string t);
    void setzip_code(string zc);
    void setuserid(string ui);
    void setpassword(string pw);
    void setstate(string st);
    void setage(int a);
    void setstreet_num(int sn);
    void setdonated(float d);
    //other functions
    bool comparedonor(const Donor &other);
    void manage();
    void change_password();
    void view();
    void donate();
    void total();
    void change_password();
};

#endif
