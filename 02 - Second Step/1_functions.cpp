#include <iostream>

using namespace std;

void greetings(){
    cout << "Hi Sir";
}

int fact(int a){
    int x = 1;
    for(int i = 2; i <= a; i++)
        x *= i;

    return x;
}

int main(){
    
    greetings();
    cout << endl << "Enter a number which will be factoried : ";
    int a;
    cin >> a;
    cout << fact(a);

    return 0;
} 