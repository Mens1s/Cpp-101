#include <iostream>
using namespace std;

class Emp{
    public:
        Emp(){
            cout << "counstructor called" << endl;
        }

        ~Emp(){
            cout << "Destructor called" << endl;
        }
};

int main(){

    Emp * e1 = new Emp;
    delete e1;
    
    return 0;
}