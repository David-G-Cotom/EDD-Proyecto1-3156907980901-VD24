//
// Created by Carlos Cotom on 8/12/2024.
//

#ifndef LISTATRANSACCIONES_H
#define LISTATRANSACCIONES_H
#include <string>

#include "NodoLista.h"
#include "../models/Transaccion.h"


class ListaTransacciones {

private:
    NodoLista *inicio;
    NodoLista *fin;

public:
    ListaTransacciones();

    void insertarTransaccion(Transaccion *transaccion);
    void insertarEnInicio(NodoLista *nodo);
    void insertarEnMedio(NodoLista *nodo, NodoLista *nodoSiguiente);
    void insertarEnFinal(NodoLista *nodo);

    bool recorrerListaTransaccion(std::string usuario);

    bool isVacia();

};



#endif //LISTATRANSACCIONES_H