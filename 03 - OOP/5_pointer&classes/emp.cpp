#include <iostream>
#include "emp.h"

using namespace std;

void Emp::setName(string n){
    Emp::name = n;
}

void Emp::setAge(int n){
    if(n < 0){
        Emp::age = 0;
        cout << "You cannot enter under 0 numbers" << endl;
    }
    else{
        Emp::age = n;
    }
}