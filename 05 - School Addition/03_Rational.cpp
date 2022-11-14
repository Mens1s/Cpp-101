#include <iostream>
using namespace std;

class Rational{

    private:
        int up;
        int down;
        static int counter;

    public:
        Rational(int const up, int const down);
        static int getCounter();
        void doSimple();

        friend ostream& operator<<(ostream &os, Rational const &o);

        friend bool operator==(Rational const a, Rational const b);
        friend bool operator!=(Rational const a, Rational const b);

        friend Rational operator ++(Rational &a);
        friend Rational operator ++(Rational &a, int);

        friend Rational operator +(Rational const &a, Rational const &b);
        friend Rational operator -(Rational const &a, Rational const &b);
        
        friend Rational operator /(Rational const &a, Rational const &b);
        friend Rational operator *(Rational const &a, Rational const &b);

        friend Rational operator -(Rational &a);
};

int Rational::counter = 0;

Rational::Rational(int const up = 1, int const down = 1){
    if(down == 0)
        exit(0);
    this->up = up;
    this->down = down;
    Rational::counter++;
    doSimple();
}

int Rational::getCounter(){
    return counter;
}

void Rational::doSimple(){
    int maxx = this->down;
    if(this->down > this->up)
        maxx = this->up;
    
    int ekok = 1;
    for(int a = 1; a <= maxx; a++)
        if(this->down % a == 0 && this->up % a == 0)
            ekok = a;
    
    this->down /= ekok;
    this->up /= ekok;
}

ostream& operator <<(ostream &os, Rational const &o){
    os << o.up << "/" << o.down << endl;
    return os;
}

bool operator ==(Rational const a, Rational const b){
    return (a.down == b.down) && (a.up == b.up);
}

bool operator !=(Rational const a, Rational const b){
    return !(a == b);
}

Rational operator ++(Rational &a){
    a.up += a.down;
    return a;
}

Rational operator ++(Rational &a, int){
    Rational temp(a.up, a.down);
    a.up += a.down;
    return temp;
}

Rational operator +(Rational const &a, Rational const &b){
    int ekok = a.down * b.down;
    return Rational(a.up * (ekok / a.down) + b.up * (ekok / b.down), ekok);
}

Rational operator -(Rational const &a, Rational const &b){
    Rational temp = b;
    return a + (-temp);
}

Rational operator /(Rational const &a, Rational const &b){
    return Rational(a.up*a.down, a.down*b.up);
}

Rational operator *(Rational const &a, Rational const &b){
    return Rational(a.up*b.up, a.down*b.down);
}

Rational operator -(Rational &a){
    a.up *= -1;
    return a;
}

int main(){
    Rational a(36, 10); // 3.6
    Rational b(108, 20); // 5.4

    cout <<" topla : " << a+b << endl; // 9
    cout <<" cikar : " << a-b << endl; // -1.8

    Rational test = a++;
    cout << "post: "<< test << endl;

    Rational t1 = ++test;
    cout <<"pre : "<< t1 << endl;

    // a = 4.6, b = 5.4
    cout << a << "-------------" << b << endl;

    Rational bol(92, 10);
    Rational carp(90, 9);

    cout <<" bol : " << bol / a<< endl;
    cout <<" carp : " << carp * a<< endl;


    cout << "minle - " << -a << endl;
    cout << "a : " << a << endl;
    Rational d(46,10);
    if(a == -d){
        cout << a  << "== " << (d) << endl;

    }
    if ( a != b){
        cout << a  << "!= " << b << endl;
    }

    cout << "suana kadaar " << Rational::getCounter() << "adet obje olustu..." << endl;
}
