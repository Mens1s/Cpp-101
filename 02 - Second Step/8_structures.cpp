#include <iostream>

using namespace std;

struct Employee{
    int id;
    string Name;
    string department;
};

int main(){
    Employee user1 = {1,"mens1s","cs"};
    user1.department = "Software Engineer at Facebook";
    cout << user1.id << "   " << user1.Name << "    " << user1.department << endl;
    return 0;
}