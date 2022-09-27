#include <iostream>

using namespace std;


struct employee{
    int id;
    string name;
    string department;
};

void showEmp(employee e1){
    cout << e1.id << endl;
    cout << e1.name << endl;
    cout << e1.department << endl;
    e1.department = "cs";
}

void showE(employee * e1){
    cout << e1->id << endl;
    cout << e1->name << endl;
    cout << e1->department << endl;
    e1->department = "cs";
}
int main(){

    employee e1 = {1, "ahmet", "non-official"};

    cout << e1.department << endl;
    showEmp(e1);
    cout << endl << e1.department << endl << endl;

    showE(&e1);
    cout << endl << e1.department << endl;

    return 0;
}