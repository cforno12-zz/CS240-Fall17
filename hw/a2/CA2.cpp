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

	DonorDatabase * database_ptr = new DonorDatabase();
    database_ptr->add();
    Donor test = database_ptr->access_data(0);
    test.view();

    cout << "\n";
    exit(0);
}
