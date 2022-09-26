#include <iostream>

using namespace std;

int main(){

    string array[] = {"123","12345","123456789"};

    cout << array << endl;      // 24 bytlik yer ayiriliyor
    cout << array + 1 << endl;
    cout << array + 2 << endl << endl;

    cout << *array << endl;
    cout << *(array + 2) << endl;

    return 0;
}