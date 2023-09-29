#include "Pila.cpp"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPriority(char op) {
    switch (op) {
        case '^':
            return 7;
        case '*':
            return 6;
        case '/':
            return 5;
        case '+':
            return 4;
        case '-':
            return 3;
        case '(':
            return 2;
        case ')':
            return 1;
        default:
            return 0; // Default priority for unknown operators
    }
}


int main(int argc, char const *argv[])
{


    
    //Pila * toPostfix = new Pila();

    //toPostfix->push(9);
    //toPostfix->push(10);
    //toPostfix->push(5);
    //toPostfix->imprimir();

    //cout << toPostfix->peek(); //Imprime una posicion de memoria

    Pila * operatorStack = new Pila();
    Pila * numberStack = new Pila();

    int x = getPriority('+');
    int y = getPriority('-');
    cout << x << endl;
    cout << y << endl;




    return 0;
}
