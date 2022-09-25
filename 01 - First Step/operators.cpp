#include <iostream>

using namespace std;

int main(){

    int num1 = 10;
    int num2 = 4;

    cout << "Sum : " << num1+num2 << endl;
    cout << "Mult : " << num1*num2 << endl;
    cout << "Diff : " << num1-num2 << endl;
    cout << "Div : " << num1/float(num2) << endl;

    cout << "++ : " << num1++ << endl;
    cout << "++ : " << ++num1 << endl; 

    return 0;
}