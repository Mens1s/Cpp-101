#include <iostream>

using namespace std;

int main(){

    // int * ptr;
    // int a[] = {1,2,3,4,5};
    // ptr = a;
    // cout << ptr[1] << endl;

    int size;

    cout << "Enter size of array : ";
    cin >> size;

    int *ptr;
    ptr = new int[size];

    for(int a = 0; a < size; a++){
        cout << "Enter " << a + 1 <<" of element : ";
        cin >> ptr[a];
    }

    for(int a = 0; a < size; a++){
        cout << ptr[a] << endl;
    }

    delete [] ptr;

    return 0; 
}