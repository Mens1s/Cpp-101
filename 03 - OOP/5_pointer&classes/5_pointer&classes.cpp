#include <iostream>
#include "emp.cpp"
using namespace std;


int main(){
    Emp * e = new Emp();

    e->setName("Ahmet");
    e->setAge(20);

    cout << e->getName() << endl;
    cout << e->getAge() << endl;
    return 0;
}