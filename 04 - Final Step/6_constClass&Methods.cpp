#include <iostream>
using namespace std;

class Test{
    private: 
        int a;
    public:
        Test(int a){
            this->a = a;
        }
        int getValue() const{ // bu method herhangi bir degeri degistiremez. Const olmayan metodları cagiramaz!
            return this->a;
        }
};

void test(const Test &t){ // bu method herhangi bir degeri degistiremez. Const olmayan metodları cagiramaz!
    cout << t.getValue() << endl;
}
int main(){

    Test t1(10);
    cout << t1.getValue() << endl;
    test(t1);
}