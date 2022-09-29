#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
using namespace std;

class Emp{
    // detayları public private olarak ayarlamak
    private:
        string name;
        int age;
    public:
        void setName(string n);
        void setAge(int n);
        
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
};

#endif /* EMPLOYEE_H_ */