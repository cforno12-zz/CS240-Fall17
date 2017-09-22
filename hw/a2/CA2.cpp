#include <iostream>
#include <stdlib.h>
#include <string>
#include "Donor.h"
#include "DonorDatabase.h"
#define MAX_DONORS 1000

using namespace std;

int main(){

    /*Donor *donor = new Donor();

    donor->login();
    donor->add();
    donor->view();*/

	DonorDatabase * data = new DonorDatabase();
    data->add();

    cout << "\n";
    exit(0);
}
