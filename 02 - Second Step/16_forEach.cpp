#include <iostream>

using namespace std;

int main(){

    int arr[] = {3,4,2,1,5,6,7,89};

    for (int item:arr)
        item += 10;
    // none of them changed
    
    for (int item:arr)
        cout << item << endl;

    
    return 0;
}