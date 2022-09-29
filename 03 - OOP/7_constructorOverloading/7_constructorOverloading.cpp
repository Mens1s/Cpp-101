#include <iostream>
#include "emp.cpp"
using namespace std;


int main(){
    Emp * e = new Emp;

    cout << e->getAge() << endl;
    cout << e->getName() << endl;
    e->setAge(25);
    cout << e->getAge();


    return 0;
}