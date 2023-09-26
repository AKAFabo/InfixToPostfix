#include "Pila.cpp"

int main(int argc, char const *argv[])
{


    
    Pila * toPostfix = new Pila();

    toPostfix->push(9);
    toPostfix->push(10);
    toPostfix->push(5);
    toPostfix->imprimir();

    cout << toPostfix->peek();

    Pila * operatorStack = new Pila();
    Pila * numberStack = new Pila();

    return 0;
}
