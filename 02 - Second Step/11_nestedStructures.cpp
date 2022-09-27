#include <iostream>

using namespace std;

struct Addres{
    string cityName;
    int No;
};

struct Emp{
    int id;
    string name;
    string department;
    Addres addres; 
};

void changeAd(Emp e1){
    e1.addres.cityName = "Ankara";
}

void changeAdr(Emp * e1){
    e1->addres.cityName = "Ankara";
}

int main(){

    Emp emp = {12, "Ahmet", "CS", {"Istanbul", 34}};

    cout << emp.addres.cityName;
    changeAd(emp);

    cout << emp.addres.cityName;
    changeAdr(&emp);

    cout << emp.addres.cityName;

    return 0;
}