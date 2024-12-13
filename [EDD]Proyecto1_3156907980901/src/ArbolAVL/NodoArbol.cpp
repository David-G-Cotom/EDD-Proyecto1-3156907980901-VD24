//
// Created by Carlos Cotom on 12/12/2024.
//

#include "../../includes/ArbolAVL/NodoArbol.h"

NodoArbol::NodoArbol(Activo *activo) {
    this->activo = activo;
    this->hijoIzquierdo = nullptr;
    this->hijoDerecho = nullptr;
    this->factorEquilibrio = 0;
}

Activo *NodoArbol::getActivo() {
    return this->activo;
}

void NodoArbol::setActivo(Activo *activo) {
    this->activo = activo;
}

NodoArbol *&NodoArbol::getHijoIzquierdo() {
    return this->hijoIzquierdo;
}

void NodoArbol::setHijoIzquierdo(NodoArbol *hijoIzquierdo) {
    this->hijoIzquierdo = hijoIzquierdo;
}

NodoArbol *&NodoArbol::getHijoDerecho() {
    return this->hijoDerecho;
}

void NodoArbol::setHijoDerecho(NodoArbol *hijoDerecho) {
    this->hijoDerecho = hijoDerecho;
}

int NodoArbol::getFactorEquilibrio() {
    return this->factorEquilibrio;
}

void NodoArbol::setFactorEquilibrio(int factor) {
    this->factorEquilibrio = factor;
}



