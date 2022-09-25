#include <iostream>


using namespace std;

int main(){
    int i = -1;

    while(i++ < 10){
        if (i == 7)
            break;
        else if(i==5)
            continue;

        cout << i << endl;
        
    }

    return 0;
}