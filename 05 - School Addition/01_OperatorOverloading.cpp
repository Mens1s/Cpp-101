#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Vehicle{
    private:
        int maxSpeed;
        vector<string> properties;
    public:
    // getter
        int getMaxSpeed() const {return maxSpeed;};
        void setMaxSpeed(int speed) { maxSpeed = speed; };
    // constructor
        Vehicle(int speed){ maxSpeed = speed; properties = {"that", "is", "special", "car"};};
    // binary operators
        const Vehicle operator +(const Vehicle  &nVehicle);
        const Vehicle operator -(const Vehicle  &nVehicle);
        const Vehicle operator /(const Vehicle  &nVehicle);
        const Vehicle operator *(const Vehicle  &nVehicle);
        const bool operator ==(const Vehicle  &nVehicle);
        const bool operator !=(const Vehicle &nVehicle);
    // subscript
        const string operator [](int index); 
    // functionCall
        const bool operator ()(int num);
    // preincrement
        void operator++ ();
    // postincrement
        void operator++(int);
    // predecrement
        void operator --();
    // postdecremnt
        void operator --(int);

    
        
};
// << operator
ostream& operator <<(ostream& outputStream, const Vehicle &vehicle){
    cout << "my car is so special its max speed is " << vehicle.getMaxSpeed() << endl;
    return cout;
}
// >> operator
istream& operator >>(istream& inputStream, Vehicle& vehicle){
    cout << "enter max speed : ";
    int maxSpeed;
    inputStream >> maxSpeed;
    vehicle.setMaxSpeed(maxSpeed);
    return cin;
}
// function operators
const Vehicle Vehicle::operator +(const Vehicle  &nVehicle){return Vehicle(getMaxSpeed() + nVehicle.getMaxSpeed() );}
const Vehicle Vehicle::operator -(const Vehicle  &nVehicle){return Vehicle(getMaxSpeed() - nVehicle.getMaxSpeed() );}
const Vehicle Vehicle::operator /(const Vehicle  &nVehicle){return Vehicle(getMaxSpeed() / nVehicle.getMaxSpeed() );}
const Vehicle Vehicle::operator *(const Vehicle  &nVehicle){ return Vehicle(getMaxSpeed() * nVehicle.getMaxSpeed()); }
const bool Vehicle::operator ==(const Vehicle  &nVehicle){ return getMaxSpeed() == nVehicle.getMaxSpeed(); }
const bool Vehicle::operator !=(const Vehicle &nVehicle){ return !(maxSpeed == nVehicle.getMaxSpeed()); }
const string Vehicle::operator [](int index) { return properties[index]; };
const bool Vehicle::operator ()(int num) { return num == getMaxSpeed(); };
void Vehicle::operator ++(){ setMaxSpeed( this->getMaxSpeed()+1 ) ; };
void Vehicle::operator --(){ setMaxSpeed( this->getMaxSpeed()-1 ) ; };
void Vehicle::operator ++(int){ setMaxSpeed( this->getMaxSpeed()+1 ) ; };
void Vehicle::operator --(int){ setMaxSpeed( this->getMaxSpeed()-1 ) ; };

int main(){
    Vehicle a(360);
    Vehicle b(120);
    Vehicle temp = a + b;
    cout << "sum is " << temp.getMaxSpeed() << endl;
    temp = a - b;
    cout << "min is " << temp.getMaxSpeed() << endl;
    temp = a * b;
    cout << "product is " << temp.getMaxSpeed() << endl;
    temp = a / b;
    cout << "divison is " << temp.getMaxSpeed() << endl;
    cout << "isEqual  : " << (a == b) << endl;
    cout << "NOTisEqual  : " << (a != b) << endl;
    cout << "isEqual  : " << (a(360)) << endl;
    cout << "isEqual  : " << (a(120)) << endl;
    cout << a[2] << endl;
    cout << "my speed is : " << a.getMaxSpeed() << endl;
    ++a;
    cout << "my speed is : " << a.getMaxSpeed() << endl;
    --a;
    cout << "my speed is : " << a.getMaxSpeed() << endl;
    a++;
    cout << "my speed is : " << a.getMaxSpeed() << endl;
    a--;
    cout << "my speed is : " << a.getMaxSpeed() << endl;

    cout << a;

    cin >> a;
    cout << "my speed is : " << a.getMaxSpeed() << endl;
    return 0;
}