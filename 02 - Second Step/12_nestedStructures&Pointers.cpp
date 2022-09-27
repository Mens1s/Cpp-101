#include <iostream>

using namespace std;

struct Address{
    string cityName;
    int No;
};
struct Emp{
    int id;
    string name;
    string department;
    Address* address;
};
void addAdr(Address * adr){
    adr->cityName = "Ankara";
    adr->No = 6;
}
int main(){
    Address adr;
    Emp emp = {1, "Ahmet", "Bilisim", &adr};
    addAdr(&adr);

    Emp * ptr = &emp;
    cout << ptr->id << endl;
    cout << ptr->name << endl;
    cout << ptr->department << endl;
    cout << ptr->address->cityName << endl;
    cout << ptr->address->No << endl;

    return 0;
}