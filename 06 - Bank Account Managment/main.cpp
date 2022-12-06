#include "Worker.cpp"

int Person::id = 1;


int main(){
    Individual c("1","5459739699");
    Individual cd("2","5459739699");
    Individual cf("3","5459739699");
    Individual cg("4","5459739699");
    Individual ch("5","5459739699");
    Individual cj("6","5459739699");
    Officer officer("Ahmet", "Yiğit",1, "5459739699","director",93);
    // cout << c << endl << endl;
    // c.addMoney(9800, 65);
    // cout << c<< endl << endl;

    officer.giveLoan(c,10000);
 
    officer.giveLoan(c,20000);

    officer.giveLoan(c,30000);
    officer.giveLoan(c,40000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    // c.takeLoan(10000);
    cout <<  endl << endl;
    cout << c<< endl << endl;
    return 0;
}