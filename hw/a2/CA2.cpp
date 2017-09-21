#include <iostream>
#include <stdlib.h>
#include "Donor.h"

using namespace std;

int main(){

    Donor *donor = new Donor();

    donor->login();

    cout << "\n";
    exit(0);
}
