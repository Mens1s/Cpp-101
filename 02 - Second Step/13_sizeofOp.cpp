#include <iostream>

using namespace std;

struct Student{
    int no;
    string name;
    char color; 
};

int main(){
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(string) << endl << endl;

    cout << sizeof(Student) << endl << endl;
    Student std = {12,"Ahmet",'W'};

    cout << sizeof(std.no) << endl;
    cout << sizeof(std.name) << endl;
    cout << sizeof(std.color) << endl;


    

    return 0;
}