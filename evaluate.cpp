#include "Pila.cpp"
#include "evaluate.h"
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

/*double getValue(double firstOperand, double secOperand, char op){
    switch(op){
        case '^':
            return pow(firstOperand, secOperand);
        case '/':
            return firstOperand/secOperand;
        case '*':
            return firstOperand*secOperand;
        case '+':
            return firstOperand+secOperand;
        case '-':
            return firstOperand-secOperand;
        default:
            return 0;
            }
}*/


int getPriority(char op) {
    switch (op) {
        case '^':
            return 8;
        case '*':
            return 6;
        case '/':
            return 6;
        case '+':
            return 4;
        case '-':
            return 4;
        default:
            return 0; // Default priority for unknown operators
    }
}

string buildPostfix(string infixExpression)       //TODO ADD STRING BUILDING FOR PARENTHESIS
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
        else if (indexPosition == '(') {
            mainStack->push(indexPosition);
            i++;
        } else if (indexPosition == ')') {
            while (!mainStack->empty() && mainStack->peek()->dato != '(') {
                postfixExpression += mainStack->peek()->dato;
                mainStack->pop();
            }
            if (!mainStack->empty() && mainStack->peek()->dato == '(')
                mainStack->pop();
            i++;
        }else{
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
    return postfixExpression;
}

double evalPostfix(string postfixExpression){

    double ultResult = 0.0;
    doubleStack * numberStack = new doubleStack();
    int i = 0;

    while(i < postfixExpression.length()){
        char indexPosition = postfixExpression[i];

        if(isdigit(indexPosition)){
            double num = indexPosition - '0';
            numberStack->push(num);
            i++;
        }
        
        else{

            double secOperand = numberStack->peek()->dato;
            numberStack->pop();
            double firstOperand = numberStack->peek()->dato;
            numberStack->pop();

            double result = 0.0;

            switch(indexPosition){
                case '^':
                    result = (double)pow(firstOperand, secOperand);
                    break;
                case '/':
                    result = (double)firstOperand/secOperand;
                    break;
                case '*':
                    result = (double)firstOperand*secOperand;
                    break;
                case '+':
                    result = (double)firstOperand+secOperand;
                    break;
                case '-':
                    result = (double)firstOperand-secOperand;
                    break;
                default:
                    return 0;
            }
            numberStack->push(result);
            ultResult = result;
            i++; 
        }
        }
        return ultResult;
    }