//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/ListaCircularDoblementeEnlazada/ListaTransacciones.h"
#include <iostream>
#include <ostream>

ListaTransacciones::ListaTransacciones() {
    this->inicio  = nullptr;
    this->fin = nullptr;
    this->ordenListaAscendente = false;
}

NodoLista *ListaTransacciones::getInicio() {
    return this->inicio;
}

void ListaTransacciones::setInicio(NodoLista *inicio) {
    this->inicio = inicio;
}

NodoLista *ListaTransacciones::getFin() {
    return this->fin;
}

void ListaTransacciones::setFin(NodoLista *fin) {
    this->fin = fin;
}

bool ListaTransacciones::getOrdenListaAscendente() {
    return this->ordenListaAscendente;
}

void ListaTransacciones::setOrdenListaAscendente(bool ordenListaAscendente) {
    this->ordenListaAscendente = ordenListaAscendente;
}

void ListaTransacciones::insertarTransaccion(Transaccion *transaccion) {
    auto *nodoNuevo = new NodoLista(transaccion);
    if (!isVacia()) {
        NodoLista *aux = this->inicio;
        if ((aux == this->inicio) && (aux == this->fin)) {
            if (nodoNuevo->getTransaccion()->getId() > aux->getTransaccion()->getId()) {
                insertarEnFinal(nodoNuevo);
            } else {
                insertarEnInicio(nodoNuevo);
            }
        } else {
            while (aux != this->fin) {
                if (nodoNuevo->getTransaccion()->getId() > aux->getTransaccion()->getId()
                    && nodoNuevo->getTransaccion()->getId() < aux->getSiguiente()->getTransaccion()->getId()) {
                    insertarEnMedio(nodoNuevo, aux->getSiguiente());
                    return;
                }
                if (nodoNuevo->getTransaccion()->getId() < aux->getTransaccion()->getId()) {
                    insertarEnInicio(nodoNuevo);
                    return;
                }
                aux = aux->getSiguiente();
            }
            insertarEnFinal(nodoNuevo);
        }
    } else {
        nodoNuevo->setSiguiente(nodoNuevo);
        nodoNuevo->setAnterior(nodoNuevo);
        this->inicio = this->fin = nodoNuevo;
    }
}

void ListaTransacciones::insertarEnInicio(NodoLista *nodo) {
    nodo->setSiguiente(this->inicio);
    nodo->setAnterior(this->inicio->getAnterior());
    this->inicio->getAnterior()->setSiguiente(nodo);
    this->inicio->setAnterior(nodo);
    this->inicio = nodo;
}

void ListaTransacciones::insertarEnMedio(NodoLista *nodo, NodoLista *nodoSiguiente) {
    nodo->setSiguiente(nodoSiguiente);
    nodo->setAnterior(nodoSiguiente->getAnterior());
    nodoSiguiente->getAnterior()->setSiguiente(nodo);
    nodoSiguiente->setAnterior(nodo);
}

void ListaTransacciones::insertarEnFinal(NodoLista *nodo) {
    nodo->setAnterior(this->fin);
    nodo->setSiguiente(this->fin->getSiguiente());
    this->fin->getSiguiente()->setAnterior(nodo);
    this->fin->setSiguiente(nodo);
    this->fin = nodo;
}

bool ListaTransacciones::recorrerListaTransaccion(std::string usuario) {
    if (!isVacia()) {
        NodoLista *aux = this->inicio;
        do {
            if (aux->getTransaccion()->getUsuario() == usuario
                && !aux->getTransaccion()->getActivo()->getDisponibilidad()) {
                std::cout << "ID = " << aux->getTransaccion()->getActivo()->getId()
                        << "; Nombre = " << aux->getTransaccion()->getActivo()->getNombre()
                        << "; Tiempo de Renta = " << aux->getTransaccion()->getDias() << std::endl;
            }
            aux = aux->getSiguiente();
        } while (aux != this->inicio);
        return true;
    }
    std::cout << "No hay Transacciones Disponibles";
    return false;
}

bool ListaTransacciones::isVacia() {
    return this->inicio == nullptr;
}


