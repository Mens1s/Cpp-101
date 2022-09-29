
#include <iostream>
using namespace std;

class Student{
    public:
        string name;

        void tellName(){
            cout << "My name is " << name << endl;
        }

};

int main(){

    Student s1 = {"Ahmet"};
    // s1.name = "Ahmet";
    // samething

    s1.tellName();

    return 0;
}