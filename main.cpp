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
        default:
            return 0; // Default priority for unknown operators
    }
}

void buildPostfix(string infixExpression)       //TODO ADD STRING BUILDING FOR PARENTHESIS
{
    string postfixExpression = "";
    Pila * mainStack = new Pila;
    int i = 0;

    while (i < infixExpression.length()){
        char indexPosition = infixExpression[i];

        if(isdigit(indexPosition)){
            postfixExpression += indexPosition;   
            i++;
        }
        else{
            if(!mainStack->empty()){
                char topElement = mainStack->peek()->dato;

                if (!isdigit(topElement)){

                    if (getPriority(topElement) < getPriority(indexPosition)){           //op > peek = pushPila
                        mainStack->push(indexPosition);
                        i++;
                    }
                    else{
                        postfixExpression += topElement;
                        mainStack->pop();
                    }
                }
                else{
                    mainStack->push(indexPosition);
                    i++;
                }
            }
            else{
                mainStack->push(indexPosition);
                i++;
            }
        }
        
    
    }
    while(!mainStack->empty()){
        char topElement = mainStack->peek()->dato;
        postfixExpression += topElement;
        mainStack->pop();

    }
    cout << postfixExpression << endl;
}

int main(int argc, char const *argv[])
{
 
    //Pila * toPostfix = new Pila();

    //toPostfix->push(9);
    //toPostfix->push(10);
    //toPostfix->push(5);
    //toPostfix->imprimir();

    //cout << toPostfix->peek(); //Imprime una posicion de memoria

    //int x = getPriority('+');
    //int y = getPriority('-');
    //cout << x << endl;
    //cout << y << endl;
    buildPostfix("1+5*7-9");

    return 0;
}
