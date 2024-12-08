//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/MatrizDispersa/Nodo.h"

Nodo::Nodo(std::string nombreCabecera) {
    this->siguiente = nullptr;
    this->previo = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
    this->nombreCabecera = nombreCabecera;
}

Nodo *Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    this->siguiente = siguiente;
}

Nodo *Nodo::getPrevio() {
    return previo;
}

void Nodo::setPrevio(Nodo *previo) {
    this->previo = previo;
}

Nodo *Nodo::getArriba() {
    return arriba;
}

void Nodo::setArriba(Nodo *arriba) {
    this->arriba = arriba;
}

Nodo *Nodo::getAbajo() {
    return abajo;
}

void Nodo::setAbajo(Nodo *abajo) {
    this->abajo = abajo;
}

Nodo *Nodo::getAdelante() {
    return adelante;
}

void Nodo::setAdelante(Nodo *adelante) {
    this->adelante = adelante;
}

Nodo *Nodo::getAtras() {
    return atras;
}

void Nodo::setAtras(Nodo *atras) {
    this->atras = atras;
}

std::string Nodo::getNombreCabecera() {
    return nombreCabecera;
}

void Nodo::setNombreCabecera(std::string nombreCabecera) {
    this->nombreCabecera = nombreCabecera;
}


