#include "Admin.cpp"

int Person::id = 1;
vector<Worker> Worker::workers;
vector<Customer> Customer::customers;

int main(){
    Individual c("user1","5459739699");
    Individual cd("user2","5459739699");
    Individual cf("user3","5459739699");
    Individual cg("user4","5459739699");
    Individual ch("user5","5459739699");
    Individual cj("user6","5459739699");
    Officer officer("Ahmet", "Yiğit",1, "5459739699","director",93);

    officer.giveLoan(c,10000);
    officer.giveLoan(c,20000);
    officer.giveLoan(c,30000);
    officer.giveLoan(c,40000);

    officer.giveLoan(ch,10000);
    officer.giveLoan(ch,20000);
    officer.giveLoan(cg,30000);
    officer.giveLoan(cg,40000);

    officer.giveLoan(cf,10000);
    officer.giveLoan(cd,20000);
    officer.giveLoan(cf,30000);
    officer.giveLoan(cd,40000);

    cout <<  endl << endl;
    cout << c<< endl << endl;

    Admin admin("Ahmet", "Yiğit",1, "5459739699", "admin", "admin");
    admin.login("admin","admin"); // very secured password a&& username :d

    map<string, vector<int> > loans = admin.getAllLoans();

    for (const auto& user : loans){
        cout << user.first << endl;
        for(const auto& loan : user.second)
            cout << "\t" << loan;
        cout << endl << endl;
    }

    return 0;
}