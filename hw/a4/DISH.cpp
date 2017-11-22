#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#include "DISH.h"

Dish::Dish(){
    curr_idx = 0;
}

bool Dish::insert(string s){

    if(curr_idx == 1023){
        return false;
    }
    //base case
    if(curr_idx == 0){
        lH.push_back(curr_idx);
        alpha.push_back(curr_idx);
        String_obj* str = new String_obj(s, 0, 0);
        main.push_back(str);
    } else {
        //put in main vector
        String_obj* str = new String_obj(s, -1, -1);
        main.push_back(str);
        //put index to the end of the length heap
        lH.push_back(curr_idx);
        int parent_idx = get_parent_idx(curr_idx);
        int temp = curr_idx;
        do {
            if(main[lH[temp]]->get_data().length() < main[lH[parent_idx]]->get_data().length()) {
                swap_lH(temp, parent_idx);
                main[lH[temp]]->set_lH_idx(temp);
                main[lH[parent_idx]]->set_lH_idx(parent_idx);
                temp = parent_idx;
                parent_idx = get_parent_idx(parent_idx);
            } else {
                break;
            }
        } while(temp != 0);
        str->set_lH_idx(temp);
        //now the alpha vector
        alpha.push_back(curr_idx);
        parent_idx = get_parent_idx(curr_idx);
        temp = curr_idx;
        do {
            if(main[alpha[temp]]->get_data() < main[alpha[parent_idx]]->get_data()) {
                swap_alpha(temp, parent_idx);
                main[alpha[temp]]->set_alpha_idx(temp);
                main[alpha[parent_idx]]->set_alpha_idx(parent_idx);
                temp = parent_idx;
                parent_idx = get_parent_idx(parent_idx);
            } else {
                break;
            }
        } while(temp != 0);
        str->set_alpha_idx(temp);
    }
    curr_idx++;
    return true;
}

int Dish::find(string s){
    int retVal = -1;
    bool got_it = false;
    for (int i = 0; i < (int)main.size(); i++){
        retVal++;
        if(main[i]->get_data() == s){
            got_it = true;
            break;
        }
    }
    if(!got_it){
        retVal = -1;
    }
    return retVal;
}

bool Dish::capitalize(int k){
    if(k > curr_idx){
        return false;
    }
    char c = toupper(main[k]->get_data()[0]);
    string str(1, c);
    for(int i = 1; i < (int)main[k]->get_data().length(); i++){
        str += main[k]->get_data()[i];
    }
    main[k]->set_data(str);
    heapify_alpha(main[k]->get_alpha_idx());
    return true;
}

bool Dish::all_caps(int k){
    if(k > curr_idx){
        return false;
    }
    string buff;
    for(int i = 0; i < (int)main[k]->get_data().length(); i++){
        buff += toupper(main[k]->get_data()[i]);
    }
    main[k]->set_data(buff);
    heapify_alpha(main[k]->get_alpha_idx());
    return true;
}

bool Dish::truncate(int k, int i){
    if(k > curr_idx){
        return false;
    } else if (i > (int)main[k]->get_data().length()){
        return true;
    }
    string new_str = main[k]->get_data();
    new_str.resize(i);
    main[k]->set_data(new_str);
    heapify_lH(main[k]->get_lH_idx());
    return true;
}
string Dish::get_shortest(){
    return main[lH[0]]->get_data();
}
string Dish::get_first(){
    return main[alpha[0]]->get_data();
}
int Dish::get_left_idx(int i){
    return 2*i + 1;
}

int Dish::get_right_idx(int i){
    return 2*i + 2;
}
int Dish::get_parent_idx(int i){
    return (i-1)/2;
}

void Dish::swap_lH(int s, int p){
    int temp = lH[s];
    lH[s] = lH[p];
    lH[p] = temp;
}

void Dish::print_main(){
    cout << "[ ";
    for (int i = 0; i < (int)main.size(); i++){
        cout << main[i]->get_data() << ", lH_idx: " << main[i]->get_lH_idx() << ", alpha_idx: " << main[i]->get_alpha_idx() << " // ";
    }
    cout << "]" << endl;
}

void Dish::swap_alpha(int s, int p){
    int temp = alpha[s];
    alpha[s] = alpha[p];
    alpha[p] = temp;
}

void Dish::print_alpha(){
    cout << "[ ";
    for (vector<int>::const_iterator i = alpha.begin(); i != alpha.end(); ++i){
        cout << *i << " ";
    }
    cout << "]" << endl;
}

void Dish::print_lH(){
    cout << "[ ";
    for (vector<int>::const_iterator i = lH.begin(); i != lH.end(); ++i){
        cout << *i << " ";
    }
    cout << "]" << endl;
}

void Dish::heapify_lH(int k){
    int parent_idx = get_parent_idx(k);
    int temp = k;
    do {
        if(main[lH[temp]]->get_data().length() < main[lH[parent_idx]]->get_data().length()) {
            swap_lH(temp, parent_idx);
            main[lH[temp]]->set_lH_idx(temp);
            main[lH[parent_idx]]->set_lH_idx(parent_idx);
            temp = parent_idx;
            parent_idx = get_parent_idx(parent_idx);
        } else {
            break;
        }
    } while(temp != 0);
}

void Dish::heapify_alpha(int k){
    int parent_idx = get_parent_idx(k);
    int temp = k;
    do {
        if(main[alpha[temp]]->get_data() < main[alpha[parent_idx]]->get_data()) {
            swap_alpha(temp, parent_idx);
            main[alpha[temp]]->set_alpha_idx(temp);
            main[alpha[parent_idx]]->set_alpha_idx(parent_idx);
            temp = parent_idx;
            parent_idx = get_parent_idx(parent_idx);
        } else {
            break;
        }
    } while(temp != 0);
}
