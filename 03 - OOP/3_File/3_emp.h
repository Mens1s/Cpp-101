#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
using namespace std;

class Emp{
    private:
        string name;
        int id;
        int salary;
    public:
        void setName(string n);
        void setId(int i){
            id = i;
        }
        void setSalary(int s){
            salary = s;
        }
        string getInfo();
};


#endif /* EMPLOYEE_H_ */
