#include <iostream>

using namespace std;

int main(){

    cout << "Hello World" << endl;
    cout << "Test";

    // int, float, double, char, bool

    int a = 32;
    float b = 3.52;
    double c = 4.546;
    char d = 'd';
    bool e = false; // 0 => false

    cout << "a => " << a << endl;
    cout << "b => " << b << endl;
    cout << "c => " << c << endl;
    cout << "d => " << d << endl;
    cout << "e => " << e << endl;

    int a1,b1,c1;
    a1 = 4;
    b1 = 3.5;
    c1 = 5;
    
    int sum = a1 + b1 + c1;

    cout << "sum => " << sum << endl; // 12

    return 0;
}