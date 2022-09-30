#include <iostream>
using namespace std;

void Test(){
    static int i = 3;
    i++;
    cout << i << endl;
}

int main(){

    Test();
    Test();
    Test();
    Test();
    // output'umuz 
    // 4, 5, 6, 7
    // static degiskenler bir kere olusur ve o variable hep memory de durur
    return 0;
}