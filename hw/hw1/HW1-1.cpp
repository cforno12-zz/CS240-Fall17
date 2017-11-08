#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void print_mult_3_inorder(int in);

int main(){
    int in;
    cout << "How many multiples of 3 do you want?:" << endl;
    cin >> in;
    print_mult_3_inorder(in);
    cout << endl;
}

void print_mult_3_inorder(int in){
    if(in == 1){
        //base case
        cout << 3 << " ";
    } else {
        //recursive case
        print_mult_3_inorder(in-1);
        cout << 3*in << " ";
    }
}
