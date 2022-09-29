#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
using namespace std;

class Emp{
    // detayları public private olarak ayarlamak
    private:
        string name;

    public:
        void setName(string n);
        string getName(){
            return name;
        }
};

#endif /* EMPLOYEE_H_ */