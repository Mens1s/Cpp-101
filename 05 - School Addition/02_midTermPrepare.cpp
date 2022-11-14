#include <iostream>
#include <string.h>
#include <sstream>  
using namespace std;

// Encapsulation:
    // Encapsulation is a way to restrict the direct access to some components of an object
    // so users cannot access state values for all the variable of a particular object.
    // Encapsulation can be used to hide both data members and data functions or methods associated with an instatntiated class or object.
// Tracing:
    // Tracing involves a specialized use of logging to record infromation about a program's execution.
    // This information is typically used by programmer for debugging purposes and additionally depending on the type and detail of information contained
    // in a trace log, by experienced system-admins.
// Debuging:
    // Debugging, in computer programming and engineering, is a multistep process that involves identifying a problem, isolating the source of the problem
    // and then either correcting the problem or determining a way to work around it.
    
int ekok(int a, int b){
    int temp = a;
    while(a % temp != 0 && b % temp != 0 )temp ++;
    return temp;
};

class Rational{
    private:
        int up;
        int down;
        static int counter;

    public:
        Rational(int up = 1, int down = 1){
            counter++;
            if (down == 0) exit(1);
            this->up = up;this->down = down;
            doSimple();
        };

        friend Rational operator +(const Rational &a,const Rational &b);
        friend Rational operator -(const Rational &a,const Rational &b);
        friend Rational operator -(Rational &a);
        friend Rational operator /(const Rational &a,const Rational &b);
        friend Rational operator *(const Rational &a,const Rational &b);
        friend ostream& operator <<(ostream &os, Rational & a );
        friend istream& operator >>(istream &is, Rational & a);
        friend bool operator ==(Rational &a, Rational &b);
        friend bool operator !=(Rational &a, Rational &b);
        friend Rational & operator ++(Rational & a);
        friend Rational operator ++(Rational & a, int);

        void doSimple();

        int getCounter(){return counter;};
        static void setCounter(){counter = 0;};


};

int Rational::counter = 0;

void Rational::doSimple(){
    int max = 1;
    for(int a = 1; a <= this->down || a <= this->up ; a++){
        
        if( down % a == 0 && up % a == 0)
            max = a;
    }   
    down /= max;
    up /= max;
}

Rational operator +(const Rational &a, const Rational &b){
    int down = a.down;
    int up = a.up + b.up;
    if(b.down != a.down){
        int d = ekok(a.down, b.down);
        up = (a.up * (d/a.down) + b.up * (d/b.down));
        down = d;
    }
    return Rational(up, down);
} 

Rational operator -(const Rational &a,const Rational &b){
    int down = a.down;
    int up = a.up + b.up;
    if(b.down != a.down){
        int d = ekok(a.down, b.down);
        up = (a.up * (d/a.down) - b.up * (d/b.down));
        down = d;
    }
    return Rational(up, down);
}

Rational operator -(Rational & a){
    a.down *= -1;
    return a;
}

Rational operator /(const Rational &a,const Rational &b){
    return Rational(a.up*b.down, a.down*b.up);
}

Rational operator *(const Rational &a, const Rational &b){
    return Rational(a.up*b.up, a.down*b.down);
}

istream& operator >>(istream &is, Rational & a){
    string str;
    is >> str;
    string upp = "";
    string downn = "";
    bool flag = true;

    for(int idx = 0; idx < str.length(); idx++){
        if(str[idx] == '/')
            flag = false;
        else if(flag)
            upp += str[idx];
        else
            downn += str[idx];
    }

    try
    {
        
        stringstream ss;
        ss << upp;
        ss >> a.up;
        ss.clear();
        ss << downn;
        ss >> a.down;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    return is;
}

ostream& operator <<(ostream &os, Rational & a ){
    os << a.up << "/" << a.down << endl;
    return os;
}

bool operator ==(Rational &a, Rational &b){
    a.doSimple();
    b.doSimple();
    return (a.up == b.up) && (a.down == b.down);
}

bool operator !=(Rational &a, Rational &b){
    return !(a==b);
}

Rational & operator ++(Rational & a){
    a.up += a.down;
    return a;
}

Rational operator ++(Rational & a, int){ // i++
    Rational temp(a.up-a.down, a.down);
    a.up += a.down;
    return temp;
}

int main(){


    Rational a(10, 4); // 2.5
    Rational a1(10, 4);
    Rational b(20, 5); // 4
    Rational two(16/8);
    Rational t = a + b;

    if(a == a1){
        cout << "equal";
    }

    cout << t << endl;
    t++;
    cout << t << endl;
    ++t;
    cout << t << endl;

    cout <<"carp iki" << endl;
    t = t * two;
    cout << t << endl;
    cout <<"Bol iki" << endl;

    t = t / two;
    cout << t << endl;
    cout <<"cikar iki" << endl;

    t = t - two;
    cout << t << endl;

    cout << "dene bi . ile gir : ";

    Rational temp;
    cin >> temp;
    cout << temp;
    return 0;
}
