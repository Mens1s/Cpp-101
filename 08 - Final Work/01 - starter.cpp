#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

class Money{

    private:
        int dolar;
    
    public:
        Money(){ dolar = 100; };
        friend ostream & operator <<(ostream & os, const Money& amount);
        friend istream & operator >>(istream & is, Money & amount);
        virtual int getMoney(){
            return dolar;
        }
        // abstract class yapar Money i virtual int gettDolar() = 0;
};
class M1{
    public:
        virtual int getone() = 0;
};
class Bank : public M1{
    private:
        int tl;
    public:
        Bank (){
            tl = 23;
        }
        int getTl(){return tl;};
        int getone() override{
            return 1;
        }
};
ostream & operator <<(ostream & os, const Money& amount){
    os << "You have fucking : " << amount.dolar << "$\n";
    return os;
}
istream & operator >>(istream & is, Money & amount){

    is >> amount.dolar;;
    return is;
}

int main(){
    
    //cpp 11 types

    auto x = 40;        // int
    decltype(x*3.5) y;  // double

    // int 2.99 => 2

    // constants
    const int NUMBER_OF_MINUTES_PER_HOUR = 60;

    // type casting
    int var1 = 10;
    double var2 = static_cast<double>(var1);

    // cin does not read after space Ahmet Yigit => Ahmet
    string name;
    //cin >> name; // enter Ahmet Yigit name = Ahmet
    //cin >> name; // name = Yigit
    cout << "Name : " << name << endl;

    // one line if statements
    int max = (var1 > x) ? var1 : x;

    // comma operator not quarentee
    int var3 = 0, var4 = 0;

    var3 = (var3 = 2, var4 = var3 + 1);
    cout << var3 << " : " << var4 << endl; // 3 : 3

    // file input & output #include <fstream>
    ifstream inputStream;
    inputStream.open("input.txt");
    //inputStream.get(name);
    while(!inputStream.eof()){ // reads last word twice also not read \n
        inputStream >> name;
        cout << name;
    }   
    cout << endl;
    inputStream.close();
    
    ofstream outputStream;
    outputStream.open("output.txt");
    outputStream << "run away ";
    outputStream.close();

    outputStream.open("output.txt", ios::app);
    if(outputStream.fail())
        cout << "Acamadim aq";
    outputStream << " slowly :!" << endl;
    outputStream.close();


    // set double .xx xx number
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double pi = static_cast<double>(22) / 7;

    cout << pi << endl; // 3.14

    // random number
    int die_roll = rand() % 6 + 1; // 1 - 6

    // parameters
    // call by value - copy of value is passed
    // call by reference - address of actual argument is passed
    /// overloading s(int, int) => s(int, int, int)

    Money m1;
    cin >> m1;
    cout << m1;
    cout << m1.getMoney() << endl;
    Bank b1;
    cout << b1.getone();
    return 0;
}