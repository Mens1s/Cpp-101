#include <iostream>

using namespace std;

struct Emp{
    int id;
    string name;
    string department;
};

int main(){

    Emp user1 = {1,"mens1s","cs"};

    Emp *ptr;

    ptr = &user1;

    cout << ptr->id << "    " << ptr->name << "    " << ptr->department << endl;
    return 0;
}