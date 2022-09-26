#include <iostream> 

using namespace std;

// constant olarak tanımlanan ptr1 in gösterdiği yeri değiştirebiliriz ama asla değerini değiştiremeyiz
void printArray(const int * ptr1, const int *ptr2){

    while (ptr1 != ptr2 + 1){
        cout << *ptr1 << endl;
        ptr1++;
    }
}

int main(){
    int array[] = {10,20,30,40,50,60,70,80,90,100};

    printArray(array+2,array+7);

    return 0;
}
