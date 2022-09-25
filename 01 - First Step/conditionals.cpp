#include <iostream>

using namespace std;

int main(){
    string password = "password";

    string input;

    cout << "Enter password : ";
    cin >> input;

    if (input == password)
        cout << "You logged in";
    
    else{
        cout << "You cannot logged in!!";
    }

    int x, y;

    string op;

    cout << endl << "Enter x : ";
    cin >> x;

    cout << "Enter y : ";
    cin >> y;

    cout <<  "Enter op : ";
    cin >> op;


    cout << "Result is : "; 

    if (op=="+")
        cout << x+y;

    else if(op =="-")
        cout << x-y;
    
    else if(op == "/")
        cout << x/y;
    else if(op == "*" || op == "x")
        cout << x*y;
    else 
        cout << "None | Wrong type op";

    return 0;
}