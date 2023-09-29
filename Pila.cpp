#include "Pila.h"

void Pila::push (char dato)
{
     if (empty ())
     {
         tope = new Nodo(dato);
     }
     else
     {
         Nodo *nuevo = new Nodo(dato);
         nuevo->siguiente = tope;
         tope = nuevo; 
     }
}

Nodo* Pila::pop(void)
{

      if (empty())
      {
         return NULL;
      }
      else
      {
          Nodo* borrado = tope;     
          tope = tope->siguiente;
          borrado->siguiente = NULL;
          return borrado;
      }
}

bool Pila::empty (void)
{
     if (tope == NULL)
        return true;
     else
         return false;
}

void Pila::imprimir(void)
{
     cout << "tope" << endl;
     Nodo *tmp = tope;
     
     while (tmp != NULL)
     {
           cout << tmp->dato << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "fondo" << endl;
}

Nodo * Pila::peek()
{
     return tope;
     }

void doubleStack::push (double dato)
{
     if (empty ())
     {
         tope = new Nodo(dato);
     }
     else
     {
         Nodo *nuevo = new Nodo(dato);
         nuevo->siguiente = tope;
         tope = nuevo; 
     }
}

Nodo * doubleStack::pop(void)
{

      if (empty())
      {
         return NULL;
      }
      else
      {
          Nodo* borrado = tope;     
          tope = tope->siguiente;
          borrado->siguiente = NULL;
          return borrado;
      }
}

bool doubleStack::empty (void)
{
     if (tope == NULL)
        return true;
     else
         return false;
}

void doubleStack::imprimir(void)
{
     cout << "tope" << endl;
     Nodo *tmp = tope;
     
     while (tmp != NULL)
     {
           cout << tmp->dato << "  " << endl;
           tmp = tmp->siguiente;
     }
     cout << "fondo" << endl;
}

Nodo * doubleStack::peek()
{
     return tope;
     }