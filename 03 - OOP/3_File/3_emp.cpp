#include <iostream>
#include "empFunct.cpp"

using namespace std;

int main(){
    Emp emp1;
    emp1.setId(10);
    emp1.setSalary(2000);
    emp1.setName("Mens1s");

    cout << emp1.getInfo();

    return 0;
}