#include "Customer.cpp"

int main(){
    Enterprise c("Mens1s","5459739699");

    cout << c;
    c.addMoney(9800, 65);
    c.takeLoan(1000);
    c.takeLoan(2000);
    c.takeLoan(3000);
    c.takeLoan(4000);
    c.takeLoan(5000);
    c.takeLoan(6000);
    c.takeLoan(7000);
    c.takeLoan(8000);
    c.takeLoan(9000);
    c.takeLoan(9999);

    cout << c;
    return 0;
}