#include <iostream>
using namespace std;

class Gamer{
    public:
        static int gamers;
        Gamer(){
            gamers++;
            cout << "new player created" << endl;
        }
};
int Gamer::gamers = 0;
int main(){
    Gamer g1;
    Gamer g2;
    Gamer g3;
    cout << Gamer::gamers << endl;
    return 0;
}