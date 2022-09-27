#include <iostream>

using namespace std;

int main(){
    int *ptr = nullptr;

    ptr = new int;
    *ptr = 11;

    delete ptr;
    // dangling pointer dangling reference which pointer deleted
    return 0;
}