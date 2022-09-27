#include <iostream>

using namespace std;

void hi(){
    cout << "hi" << endl;
}
void hi(string a){
    cout << "hi MR. " << a << endl;
}
int main(){

    hi();
    hi("Ahmet");
    return 0;
}