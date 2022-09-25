#include <iostream>

using namespace std;

int main(){

    for (int i = 0 ; i < 10; i++)
        cout << "i : " << i << endl;
    
    int fakt=1;
    
    for (int a = 6 ; a > 1; a--)
        fakt *= a;
    
    cout << "fakt : " << fakt;
    return 0;
}