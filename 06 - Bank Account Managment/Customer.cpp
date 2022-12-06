#include "Person.cpp"

class Customer : public Person{
    private:
        int accountDolars;
        int accountCents;

        int * loans; // maybe add class named loan and make it array
        int loanCap;
        int loanSize;
    public:
        Customer(string name, string surname, int sex, string phoneNum);
        ~Customer();

        int * getLoans(){return loans;};
        int getLoanCap(){return loanCap;};
        int getLoanSize(){return loanSize;};

        void setLoanCap(int t){this->loanCap = t;};
        void setLoanSize(int t){this->loanSize = t;};
        void increaseSize();

        virtual double * getBalance() = 0; // [0] => real balance [1] => plus money balance [2] => loan sums
        virtual void takeLoan(int amaount) = 0;
        
        int getDolars(){return accountDolars;};
        int getCents(){return accountCents;};

        void addMoney(int dollarAmount, int centsAmount);
        bool takeMoney(int dollarAmount, int centsAmount);

};


Customer::Customer(string name, string surname, int sex, string phoneNum) : Person(name, surname, sex, phoneNum){
    loans = new int[8];
    loanCap = 8;
    loanSize = 0;
    accountDolars = 0;
    accountCents = 0;
}

void Customer::increaseSize(){
    loans = new int[loanCap*2];
    loanCap *= 2;
}

Customer::~Customer(){
    delete loans;
}

void Customer::addMoney(int dollarAmount, int centsAmount){
    this->accountCents += centsAmount;
    if(this->accountCents >= 100){
        this->accountDolars += 1;
        this->accountCents -= 100;
    }
    this->accountDolars += dollarAmount;
}
bool Customer::takeMoney(int dollarAmount, int centsAmount){
    if(dollarAmount == accountDolars && centsAmount == accountCents){
        accountCents = 0;
        accountDolars = 0;
        return true;
    }
    if(dollarAmount == accountDolars){
        if(accountCents >= centsAmount){
            accountDolars = 0;
            accountCents -= centsAmount;
            return true;
        }
        return false;
    }
    if(dollarAmount > accountDolars){
        if(centsAmount >= centsAmount){
            accountDolars -= dollarAmount;
            accountCents -= centsAmount;
            return true;
        }
    }
    return false;
}
// ENTERPRISE customer

class Enterprise : public Customer{
    private:
        int enterpriseStatus;
        double * balanceArr;
    public:
        Enterprise(string name, string phoneNum);
        ~Enterprise();

        double * getBalance();
        void takeLoan(int amaount);

        friend ostream & operator <<(ostream & os, Enterprise & obj);
};

Enterprise::Enterprise(string name, string phoneNum) : Customer(name, "COMP", -1, phoneNum){
    enterpriseStatus = 0;
}

double * Enterprise::getBalance(){
    double balance = getDolars() + getCents()/100;
    balanceArr = new double[2];
    balanceArr[0] = balance;
    balanceArr[1] = balance*(enterpriseStatus+4)*1.15;
    return balanceArr;
}

void Enterprise::takeLoan(int amaount){
    if(getLoanCap() - 1 == getLoanSize()){
        int * temp = new int[getLoanSize()*2];

        for(int a = 0; a < getLoanSize(); a++)
            temp[a] = getLoans()[a];
        
        increaseSize();

        for(int a = 0; a < getLoanSize(); a++)
            getLoans()[a] = temp[a];
    }
    getLoans()[getLoanSize()] = amaount;
    setLoanSize(getLoanSize()+1);
}

ostream & operator <<(ostream & os, Enterprise & obj){
    int sumLoans = 0;

    os << "Comp name : " << obj.getName()  << endl;
    os << "Orginial Balance : " << obj.getDolars() << "." << obj.getCents() << endl;
    os << "Added Balance : " << obj.getBalance()[1] << endl;
    os << "Loans : " << endl;

    for(int a = 0; a < obj.getLoanSize() ; a++){
        os << a+1 << ". Loan : " << obj.getLoans()[a] << endl;
        sumLoans += obj.getLoans()[a];
    }
    os << "Sum Of Loans : " << sumLoans;

    return os;
}

Enterprise::~Enterprise(){
    delete balanceArr;
}

class Individual : public Customer{
    private:
        int customerStatus;
        double * balanceArr;
    public:
        Individual(string name, string phoneNum);
        ~Individual();

        double * getBalance();
        void takeLoan(int amount);

        friend ostream & operator <<(ostream & os, Individual & ind);
};

Individual::Individual(string name, string phoneNum) : Customer(name, "COMP", -1, phoneNum){
    customerStatus = 0;
}

double * Individual::getBalance(){
    double balance = getDolars() + getCents()/100;
    balanceArr = new double[2];
    balanceArr[0] = balance;
    balanceArr[1] = balance*(customerStatus+1.1)*1.15;
    return balanceArr;
}

void Individual::takeLoan(int amaount){
    if(getLoanCap() - 1 == getLoanSize()){
        int * temp = new int[getLoanSize()*2];

        for(int a = 0; a < getLoanSize(); a++)
            temp[a] = getLoans()[a];
        
        increaseSize();

        for(int a = 0; a < getLoanSize(); a++)
            getLoans()[a] = temp[a];
    }
    getLoans()[getLoanSize()] = amaount;
    setLoanSize(getLoanSize()+1);
}

ostream & operator <<(ostream & os, Individual & obj){
    int sumLoans = 0;

    os << "Ind name : " << obj.getName()  << endl;
    os << "Orginial Balance : " << obj.getDolars() << "." << obj.getCents() << endl;
    os << "Added Balance : " << obj.getBalance()[1] << endl;
    os << "Loans : " << endl;

    for(int a = 0; a < obj.getLoanSize() ; a++){
        os << a+1 << ". Loan : " << obj.getLoans()[a] << endl;
        sumLoans += obj.getLoans()[a];
    }
    os << "Sum Of Loans : " << sumLoans;

    return os;
}

Individual::~Individual(){
    delete balanceArr;
}
