//
// Created by Carlos Cotom on 8/12/2024.
//

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "../models/Transaccion.h"


class NodoLista {

private:
    NodoLista *siguiente;
    NodoLista *anterior;
    Transaccion *transaccion;

public:
    NodoLista(Transaccion *transaccion);

    NodoLista *getSiguiente();
    void setSiguiente(NodoLista *siguiente);
    NodoLista *getAnterior();
    void setAnterior(NodoLista *anterior);
    Transaccion *getTransaccion();
    void setTransaccion(Transaccion *transaccion);

};



#endif //NODOLISTA_H
