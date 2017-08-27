#ifndef HELLO_H
#define HELLO_H
#include "string"
using namespace std;

class Hello_Class{
 public:
    Hello_Class(int i);
    void print_hello();
 private:
    string output_string;
};
#endif
