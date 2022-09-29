#include <iostream>
#include "3_emp.h"
#include <string>

using namespace std;

string Emp::getInfo(){
    return std::to_string(Emp::id) + '\n' + Emp::name + '\n' + std::to_string(Emp::salary);
}

void Emp::setName(string n){
    Emp::name = n;
}