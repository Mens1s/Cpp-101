#include <iostream>

using namespace std;

int main(){
    
    int a = 10;
    int &ref = a;

    ref++;

    cout << "New value of a " << a << endl;
    cout << "New value of ref " << ref << endl;
    cout << "New value of ref " << &ref<< endl;

    return 0;
}