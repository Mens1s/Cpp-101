#include <iostream>
using namespace std;

class Math{
    public:
        static void cube(int x){
            cout << x*x*x << endl;
        }
        static void add2(int x){
            cout << x + 2 << endl;
        }
};

int main(){
    Math::cube(3);
    Math::add2(19);

    return 0;
}