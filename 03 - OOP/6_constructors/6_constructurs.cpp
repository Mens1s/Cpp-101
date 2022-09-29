#include <iostream>
#include "emp.cpp"
using namespace std;


int main(){
    Emp * e = new Emp("ahmet", 20 , 20);

    cout << e->getAge() << endl;

    e->setAge(25);
    cout << e->getAge();


    return 0;
}