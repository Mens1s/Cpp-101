#include <iostream>

using namespace std;

int main(){

    string username = "mens1s";
    string password = "password";

    string userName;
    string userPassword;

    cout << "Enter username : ";
    cin >> userName;

    cout << "Enter Password : ";
    cin >> userPassword;

    if (username == userName && password == userPassword)
        cout << "Log in!" << endl;
    
    else if(username != userName && password == userPassword)
        cout << "Username wrong!";

    else if(username == userName && password != userPassword)
        cout << "Password wrong!";
    
    else
        cout << "Username and password are wrong!";
    return 0;
}