#include <cstdlib>
#include <iostream>

using namespace std;


// estructura nodo para lista simple
struct Nodo {
       char dato; // parte de datos
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor
       
       Nodo(char d) 
       {
                dato = d; // asigna los datos 
                siguiente = NULL; // sig es null
       }

      void imprimir();
       
};


struct Pila {
       // solo con pN es suficiente
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