#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class Team {
    unsigned int wins, losses;

public:
    Team(int w, int l, string n){
        wins = w;
        losses = l;
        name = n;
    }
    string name;

    friend bool operator<= (const Team &t1, const Team &t2);
};

bool operator<=(const Team &t1, const Team &t2){
    double win_per_1 = (t1.wins*1.0) / (t1.wins + t1.losses);
    double win_per_2 = (t2.wins*1.0) / (t2.wins + t2.losses);
    return win_per_1 <= win_per_2;
}

template <class T>
vector <T> merge(vector<T> left, vector<T> right){
    vector<T> result;
    while(!left.empty() && !right.empty()){
        if(left.front() <= right.front()){
            result.push_back(left.front());
            left.erase(left.begin());
        } else {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    while(!left.empty()){
        result.push_back(left.front());
        left.erase(left.begin());
    }
    while(!right.empty()){
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

template <class T>
vector<T> merge_sort(vector<T> input){
    //base case
    vector<T> left;
    vector<T> right;
    if(input.size() == 1){
        return input;
    }
    bool a = true;
    for(typename vector<T>::iterator it = input.begin(); it != input.end(); ++it){
        if(a){
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
        a = !a;
    }
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}
int main(){
    vector<Team> teams;
    teams.push_back(Team(7,4, "Chelsea"));
    teams.push_back(Team(4,5, "Newcastle"));
    teams.push_back(Team(10,0, "Man. City"));
    teams.push_back(Team(5,6, "Liverpool"));
    cout << "unsorted" << endl;
    for(vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it){
        cout << it->name << " ";
    }
    cout << endl;
    teams = merge_sort(teams);
    cout << "sorted" << endl;
    for(vector<Team>::iterator it = teams.begin(); it != teams.end(); ++it){
        cout << it->name << " ";
    }
    cout << endl;

    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(0);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(5);
    vec.push_back(9);
    cout << "unsorted" << endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    vec = merge_sort(vec);
    cout << "sorted" << endl;
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
