#include <iostream>

using namespace std;

// abstraction is a hiding complexity from users
class AbstractEmployee{
    virtual void AskForPromotion() = 0;
};

class Employee: AbstractEmployee {    
    private:
        string Company;
        int Age;
    
    protected:
        string Name;

    public:
        Employee(string Name, string Company, int Age){
            this->Name = Name;
            this->Company = Company;
            this->Age = Age;
        }

        void setName(string Name){
            this->Name = Name;
        }
        string getName(){
            return this->Name;
        }

        void setCompany(string Company){
            this->Company = Company;
        }
        string getCompany(){
            return this->Company;
        }

        void setAge(string ComAgeany){
            this->Age = Age;
        }
        int getAge(){
            return this->Age;
        }
        
        void IntroduceYourself(){
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
        }

        void AskForPromotion(){
            if(Age > 30)
                cout << Name << "  Got promoted!" << endl;
            else
                cout << Name << "  Sorry not promotion for u :(" << endl;
        }

        virtual void Work() {
            cout << Name << " is checking email, task backlog, performing tasks... " << endl;
        }
};
// private değerler inherit alınsa bile access yok ancak protected ile erişilir ama protected ile değiştiremezsin
//                public olmazsa public verilerde / fonksiyonlarda dahil main de ya da başka objelerden çağrıyamayız
class Developer : public Employee{

    public:
        string FavProgrammingLanguage;

        Developer(string Name, string Company, int Age, string Lang) : Employee(Name, Company, Age){
            this->FavProgrammingLanguage = Lang;
        };

        void FixBug(){
            cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
        }

        void Work(){
            cout << Name << " is writing " << FavProgrammingLanguage << " ..." << endl;
        }
};

class Teacher : public Employee{
    public:
        Teacher(string name, string comp, int age, string subject) : Employee(name, comp, age) {
            this->Subject = subject;
        }

        string Subject;

        void PrepareLesson(){
                cout << Name << " is preparing  " << Subject << " lesson ! " << endl;
        }

        void Work(){// polymorphism
            cout << Name << " is teaching " << Subject << "..." << endl;
        }
};
// many forms is polymorphisim
int main(){

    Employee employee1("Mens1s", "Mens1sCorp", 21);
    Employee employee2("EMP2", "EMP2Corp", 31);

    Developer d("Mens1sDev","Turkcell",21,"JPC");
    Teacher t("Jack" , "nope", 32, "MATH");

    Employee *e1 = &d;
    Employee *e2 = &t;


    e1->Work();
    e2->Work();


    return 0;

}