#include <iostream>

using namespace std;

// Person interface
class Person
{
    private:
        string name;
        string surname;
        int sex;
        string phoneNum;
        
    public:
        Person();
        Person(string name, string surname, int sex, string phoneNum);
        ~Person();

        string getName(){return name;};
        string getSurname(){return surname;};
        int getSex(){return sex;};
        string getPhoneNum(){return phoneNum;};

 
};

Person::Person(string name, string surname, int sex, string phoneNum)
{
    this->name = name;
    this->surname = surname;
    this->sex = sex;
    this->phoneNum = phoneNum;
}

Person::~Person()
{   
    delete this;
}
