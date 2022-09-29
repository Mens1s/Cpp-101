#include <iostream>
#include "emp.cpp"
using namespace std;


int main(){
    Emp e;
    e.setName("a");
    cout << "My name is " << e.getName();
    return 0;
}