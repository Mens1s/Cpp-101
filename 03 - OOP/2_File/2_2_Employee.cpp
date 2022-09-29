#include "2_1_Employee.h"

#include <iostream>
using namespace std;

void Employee::showInfos(){
    cout << "ID : " << Employee::id << " NAME : " << Employee::name << " SALARY : " << Employee::salary << endl ;
}
