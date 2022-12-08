#include "Customer.cpp"

class Director;

class Worker : public Person{
    private:
        static vector<Worker> workers;

        int sallaryDollarPart;  
        int sallaryCentPart;

        int extraPayment;

        string title;

        double * monthlyPayment;
        int * workedDays;

    public:
        Worker(string name, string surname, int sex, string phoneNum, string title);
        ~Worker();

        void setWorkedDays(int day, bool isWorked);
        int * getWorkedDays(){return workedDays;};
        int getWorkerDaysCount();

        void setMonthlyPayment(int mounth, int sallaryDollarPart, int sallaryCentPart);
        double * getMonthlyPayment(){return monthlyPayment;};

        double getSalary();
        virtual void giveLoan(Individual &customer, int amountDollarPart);

        static vector<Worker> getWorkers(){return Worker::workers;};
};

Worker::Worker(string name, string surname, int sex, string phoneNum, string title) : Person(name, surname, sex, phoneNum)
{
    this->title = title;
    this->extraPayment = 0;
    this->sallaryCentPart = 0;
    this->sallaryDollarPart = 0;

    monthlyPayment = new double[12];
    workedDays = new int[30];

    for(int i = 0; i < 12; i++) monthlyPayment[i] = 0;
    for(int i = 0; i < 39; i++) workedDays[i] = 0;

    workers.push_back(*this);
}

Worker::~Worker(){
    delete monthlyPayment;
    delete workedDays;
}

void Worker::setWorkedDays(int day, bool isWorked){
    if(day > 30 || day < 1) throw out_of_range ("OUT OF RANGE FROM DAY");;
    if(isWorked) workedDays[day] = 1;
    else workedDays[day] = 0;
}

int Worker::getWorkerDaysCount(){
    int a = 0;
    for(int day = 0; day < 30 ;day++)
        if(workedDays[day] == 1)
            a++;
    
    return a;
}

void Worker::setMonthlyPayment(int mount, int sallaryDollarPart, int sallaryCentPart){
    if(mount < 1 ||mount > 12) throw out_of_range("OUT OF RANGE MONTH");
    if(sallaryCentPart >= 100){
        sallaryDollarPart += (sallaryCentPart/100);
        sallaryCentPart /= 100;
    }
    monthlyPayment[mount] = sallaryDollarPart + (sallaryCentPart/100);
}

double Worker::getSalary(){
    return sallaryDollarPart + sallaryCentPart/100 +extraPayment;
}

class Officer : public Worker{
    private:
        int level;

    public:
        Officer(string name, string surname, int sex, string phoneNum, string title, int level);

        void getAccessFromDirector(Director &director, Individual &customer, int amountDollarPart);
        void giveLoan(Individual &customer, int amountDollarPart);
        void takeMoneyFromCustomer(Individual &customer, int amountDollarPart);
        
};

Officer::Officer(string name, string surname, int sex, string phoneNum, string title, int level) : Worker(name, surname, sex, phoneNum, title){
    this->level = level;
}

void Officer::giveLoan(Individual &customer, int amountDollarPart){

    if(amountDollarPart <= level * 1000){
        customer.takeLoan(amountDollarPart);
        cout <<" ASAGIDAKI KULLANICIYA KREDI ISLEMLERI BASARILI BIR SEKILDE TAMAMLANDI \n";
        cout << customer;    
    }else
        cout << "GET HELP FROM DIRECTOR!\n";
    
    
}

void Officer::getAccessFromDirector(Director &director, Individual &customer, int amountDollarPart){
    director.giveLoan(customer, amountDollarPart);
}   

void Officer::takeMoneyFromCustomer( Individual &customer, int amountDollarPart){
    customer.takeMoney(amountDollarPart, 0); // can be minus
}   

class Director : public Worker{
    private:
        int level;

    public:
        void giveLoan(Individual &customer, int amountDollarPart);
};

void Director::giveLoan(Individual &customer, int amountDollarPart){
    customer.takeLoan(amountDollarPart);
    cout <<" ASAGIDAKI KULLANICIYA KREDI ISLEMLERI BASARILI BIR SEKILDE TAMAMLANDI \n";
    cout << customer;  
}