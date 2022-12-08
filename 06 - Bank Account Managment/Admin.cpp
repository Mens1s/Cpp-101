#include "Customer.cpp"
#include "Worker.cpp"
#include <map>

class Admin : Person{

    private:
        int loginStatus;
        string password;
        string username;

    public:
        Admin(string name, string surname, int sex, string phoneNum, string password, string username);
        ~Admin();

        void login(string password, string username);
        void logout();

        vector<Customer> getAllCustomers();
        map<string, vector<int> > getAllLoans();

        vector<Worker> getAllWorkers();
        vector<Worker> getSpecificWorkers(int day);

        // void doPayments();
        // void giveExtraPayment();
};

Admin::Admin(string name, string surname, int sex, string phoneNum, string password, string username) : Person(name, surname, sex, phoneNum){
    this->password = password;
    this->username = username;
    this->loginStatus = 0;
}

void Admin::login(string password, string username){
    if(this->password == password && this->username == username)
        this->loginStatus = 1;
    loginStatus = 0;
}

void Admin::logout(){this->loginStatus = 0;};

vector<Worker> Admin::getAllWorkers(){
    if(loginStatus == 0) throw range_error("INVALID PASSWORD");
    return Worker::getWorkers();
}

vector<Worker> Admin::getSpecificWorkers(int day){
    vector<Worker> res;
    if(loginStatus == 1){
        for(auto worker : getAllWorkers())
            if(worker.getWorkerDaysCount() >= day)
                res.push_back(worker);
    }
    return res;
}

vector<Customer> Admin::getAllCustomers(){
    if(loginStatus == 0) throw range_error("INVALID PASSWORD");
    return Customer::getCustomers();
}

map<string, vector<int> >  Admin::getAllLoans(){
    map<string, vector<int> > res;
    if(loginStatus == 1){
        for(auto customer : getAllCustomers()){
            vector<int> temp;
            int * t = customer.getLoans();

            for(int loan = 0; loan < customer.getLoanSize(); loan++)
                temp.push_back(t[loan]);
            
            res[customer.getName()] = temp;
        }
    }
    return res;
}
