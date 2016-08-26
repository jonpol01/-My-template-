#include <iostream>

using namespace std;

struct node{
    int Data;
    node* Left;
    node* Right;

}
int main() {
    Dice* ptrDice = new Dice;
    for (int i=0; i<5; i++) {
        cout << "You rolled" << ptrDice->roll() << '\n';
    }
    delete ptrDice;
}