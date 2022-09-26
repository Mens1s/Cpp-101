#include <iostream>

using namespace std;

int main(){

    string sys_password = "12345";
    string userPassword;

    do{
        cout << "Enter Password : ";
        cin >> userPassword;
    }while (userPassword != sys_password);
    
    cout << "Password correct!";

    return 0;
}