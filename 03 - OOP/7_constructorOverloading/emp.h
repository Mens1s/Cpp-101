#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
using namespace std;

class Emp{
  
    private:
        string name;
        int age;
        int salary;
    public:
        Emp(){
            salary = 0;
            this->age = 0;
            name = "none";
        }
        Emp(string name, int salary){
            this->salary = salary;
            this->name = name;
            this->age = 30;
        }   
        // constructor yapisi class yapisi ile aynı olmali
        Emp(string name, int age, int salary){
            this->name = name;
            this->age = age;
            this->salary = salary;
        }

        void setName(string n);
        void setAge(int n);
        void setSalary(int n){
            this->salary = n;
        }

        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        int getSalary(){
            return salary;
        }
};

#endif /* EMPLOYEE_H_ */