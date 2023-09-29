#include <cstdlib>
#include <iostream>

using namespace std;


struct Nodo {
       char dato; 
       Nodo* siguiente;
  
       
       Nodo(char d) 
       {
                dato = d; 
                siguiente = NULL; 
       }

      void imprimir();
       
};


struct Pila {

       Nodo *tope;
       
       Pila()
       {
                    tope = NULL;
       }
       
       // encabezados de funcion
       void push (char dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimir(void);
};

struct doubleStack {
       Nodo * tope;

       doubleStack()
       {
              tope = NULL;
       }

       void push (double dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimir(void);
};