//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/ListaCircularDoblementeEnlazada/NodoLista.h"

NodoLista::NodoLista(Transaccion *transaccion) {
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->transaccion = transaccion;
}

NodoLista *NodoLista::getSiguiente() {
    return this->siguiente;
}

void NodoLista::setSiguiente(NodoLista *nodo) {
    this->siguiente = nodo;
}

NodoLista *NodoLista::getAnterior() {
    return this->anterior;
}

void NodoLista::setAnterior(NodoLista *nodo) {
    this->anterior = nodo;
}

Transaccion *NodoLista::getTransaccion() {
    return this->transaccion;
}

void NodoLista::setTransaccion(Transaccion *transaccion) {
    this->transaccion = transaccion;
}


