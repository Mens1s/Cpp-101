#include <iostream>
using namespace std;

class Test{
    public:
        int a;
        Test(int a){
            this->a = a;
        }
};

int main(){

    Test t1(10);
    t1.a = 20;
    cout << t1.a;

    Test const t2(30);
    cout << t2.a;

}