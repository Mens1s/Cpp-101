#include <iostream>

using namespace std;

void degerDegistir(int * a){
    *a = 19;
}


int main(){
    int a = 5;

    int *ptr;

    cout << &a << endl;
    cout << ptr<< endl << endl;


    ptr = &a;

    *ptr = 4;

    cout << &a << endl;
    cout << ptr<< endl << endl;

    cout << a << endl;
    cout << *ptr << endl << endl;

    degerDegistir(&a);
    cout << a << endl;

    return 0;
}