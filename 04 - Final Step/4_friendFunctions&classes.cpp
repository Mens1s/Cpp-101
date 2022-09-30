#include <iostream>
using namespace std;

class Emp{
    private:
        string name;
        int age;
        int salary;
    public:
        Emp(string name, int age, int salary){
            this->name = name;
            this->age = age;
            this->salary = salary;
        }
        friend void showInfos(Emp e1);
        friend class Test;
};

// normalde name age ve salary erişilmez durumda
class Test{
    public:
        void showInfos(Emp e1){
            cout << e1.name << "###" << e1.age << "###" << e1.salary << endl;
        }
};

// normalde name age ve salary erişilmez durumda
void showInfos(Emp e1){
    cout << e1.name << "###" << e1.age << "###" << e1.salary << endl;
}

int main(){
    Emp e1("ahmet", 19, 4000);
    showInfos(e1);
    Test e2;
    e2.showInfos(e1);
    // Test::showInfos(e1);
    return 0;
}