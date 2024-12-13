//
// Created by Carlos Cotom on 12/12/2024.
//

#include "../../includes/ArbolAVL/ArbolAVL.h"

ArbolAVL::ArbolAVL() {
    this->raiz = nullptr;
}

NodoArbol *ArbolAVL::getRaiz() {
    return this->raiz;
}

void ArbolAVL::setRaiz(NodoArbol *raiz) {
    this->raiz = raiz;
}

void ArbolAVL::insertar(NodoArbol *activo, NodoArbol *&raiz) {
    if (raiz == nullptr) {
        raiz = activo;
        raiz->setFactorEquilibrio(this->factorEquilibrio(raiz));
        return;
    }

    if (activo->getActivo()->getId() < raiz->getActivo()->getId()) {
        insertar(activo, raiz->getHijoIzquierdo());
    } else {
        insertar(activo, raiz->getHijoDerecho());
    }
    raiz->setFactorEquilibrio(this->factorEquilibrio(raiz));
    if (raiz->getFactorEquilibrio() < -1) {
        if (raiz->getHijoIzquierdo()->getFactorEquilibrio() > 0) {
            rotacionDerechaDoble(raiz);
            return;
        }
        rotacionIzquierda(raiz);
        return;
    }
    if (raiz->getFactorEquilibrio() > 1) {
        if (raiz->getHijoDerecho()->getFactorEquilibrio() < 0) {
            rotacionIzquierdaDoble(raiz);
            return;
        }
        rotacionDerecho(raiz);
    }
}

int ArbolAVL::alturaMax(NodoArbol *nodo) {

    if (nodo == nullptr) return 0;

    int alturaIzquierda =  alturaMax(nodo->getHijoIzquierdo());
    int alturaDerecha =  alturaMax(nodo->getHijoDerecho());
    return 1 + (alturaIzquierda > alturaDerecha ? alturaIzquierda: alturaDerecha);
}

int ArbolAVL::factorEquilibrio(NodoArbol *nodo) {
    return alturaMax(nodo->getHijoIzquierdo()) - alturaMax(nodo->getHijoDerecho());
}

void ArbolAVL::rotacionIzquierda(NodoArbol *&nodo) {
    NodoArbol *aux = nodo->getHijoIzquierdo();
    nodo->setHijoIzquierdo(aux->getHijoDerecho());
    aux->setHijoDerecho(nodo);
    nodo = aux;
    nodo->setFactorEquilibrio(this->factorEquilibrio(nodo));
    nodo->getHijoDerecho()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoDerecho()));

    if (nodo->getHijoIzquierdo() == nullptr) return;

    nodo->getHijoIzquierdo()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoIzquierdo()));
}

void ArbolAVL::rotacionDerecho(NodoArbol *&nodo) {
    NodoArbol *aux = nodo->getHijoDerecho();
    nodo->setHijoDerecho(aux->getHijoIzquierdo());
    aux->setHijoIzquierdo(nodo);
    nodo = aux;
    nodo->setFactorEquilibrio(this->factorEquilibrio(nodo));
    nodo->getHijoIzquierdo()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoIzquierdo()));

    if (nodo->getHijoDerecho() == nullptr) return;

    nodo->getHijoDerecho()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoDerecho()));
}

void ArbolAVL::rotacionIzquierdaDoble(NodoArbol *&nodo) {
    rotacionIzquierda(nodo->getHijoDerecho());
    rotacionDerecho(nodo);
}

void ArbolAVL::rotacionDerechaDoble(NodoArbol *&nodo) {
    rotacionDerecho(nodo->getHijoIzquierdo());
    rotacionIzquierda(nodo);
}

bool ArbolAVL::isHoja(NodoArbol *nodo) {
    return nodo->getHijoIzquierdo() == nullptr && nodo->getHijoDerecho() == nullptr;
}


void ArbolAVL::insertar(Activo *nuevoActivo) {
    auto *nuevoNodo = new NodoArbol(nuevoActivo);
    insertar(nuevoNodo, this->raiz);
}


