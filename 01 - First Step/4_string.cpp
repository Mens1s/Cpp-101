#include <iostream>

using namespace std;

int main(){
    string str1 = "That is a string";
    string str2 = "Dou you copy";

    cout << "str1 : " << str1 << endl;
    cout << "str2 : " << str2 << endl;

    string str3 = str1 +"  "+ str2;

    cout << "str3 : " << str3 << endl; 

    return 0;
}