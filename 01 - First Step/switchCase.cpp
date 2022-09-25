#include <iostream>

using namespace std;

int main(){
    
    int x;

    cout << "Enter op : ";
    cin >> x;

    switch (x){
        
        case 0:
            cout << "Sum of all";
            break;
        case 1:
            cout << "Div of all";
            break;
        case 2:
            cout << "Mult of all";
            break;
        case 3:
            cout << "Inc of all";
            break;
        default:
            cout << "None";
            break;

    }
    return 0;
}