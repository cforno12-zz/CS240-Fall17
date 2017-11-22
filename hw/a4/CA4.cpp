#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "DISH.h"

using namespace std;

void print_all(Dish* dish);

int main(){
    Dish* dish = new Dish();
    dish->insert("planet");
    dish->insert("hello");
    dish->insert("hiy");
    dish->insert("a");
    cout << "BEFORE:" << endl;
    print_all(dish);
    cout << "AFTER:" << endl;
    dish->truncate(0, 2);
    print_all(dish);
}

void print_all(Dish * dish){
    cout << "lH: " << endl;
    dish->print_lH();
    cout << "alpha: " << endl;
    dish->print_alpha();
    cout << "main: " << endl;
    dish->print_main();
}
