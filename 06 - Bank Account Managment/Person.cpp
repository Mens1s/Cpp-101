#include <iostream>
#include <vector>

using namespace std;

// Person interface
class Person
{
    private:
        static int id;

        int sex;
        string name;
        string surname;
        string phoneNum;
        
    public:
        Person();
        Person(string name, string surname, int sex, string phoneNum);
        ~Person();

        int getSex(){return sex;};
        string getName(){return name;};
        string getSurname(){return surname;};
        string getPhoneNum(){return phoneNum;};

        int getID(){return id;};
};

Person::Person(string name, string surname, int sex, string phoneNum)
{
    cout << "my id : " << id << endl;
    this->name = name;
    this->surname = surname;
    this->sex = sex;
    this->phoneNum = phoneNum;
    id++;
}

Person::~Person()
{   
    delete this;
}

