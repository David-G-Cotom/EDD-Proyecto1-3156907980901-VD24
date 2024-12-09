//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/MatrizDispersa/NodoMatriz.h"

NodoMatriz::NodoMatriz(std::string nombreCabecera) {
    this->siguiente = nullptr;
    this->previo = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
    this->nombreCabecera = nombreCabecera;
    this->usuario = nullptr;
}

NodoMatriz::NodoMatriz(Usuario *usuario) {
    this->siguiente = nullptr;
    this->previo = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
    this->nombreCabecera = "";
    this->usuario = usuario;
}

NodoMatriz *NodoMatriz::getSiguiente() {
    return siguiente;
}

void NodoMatriz::setSiguiente(NodoMatriz *siguiente) {
    this->siguiente = siguiente;
}

NodoMatriz *NodoMatriz::getPrevio() {
    return previo;
}

void NodoMatriz::setPrevio(NodoMatriz *previo) {
    this->previo = previo;
}

NodoMatriz *NodoMatriz::getArriba() {
    return arriba;
}

void NodoMatriz::setArriba(NodoMatriz *arriba) {
    this->arriba = arriba;
}

NodoMatriz *NodoMatriz::getAbajo() {
    return abajo;
}

void NodoMatriz::setAbajo(NodoMatriz *abajo) {
    this->abajo = abajo;
}

NodoMatriz *NodoMatriz::getAdelante() {
    return adelante;
}

void NodoMatriz::setAdelante(NodoMatriz *adelante) {
    this->adelante = adelante;
}

NodoMatriz *NodoMatriz::getAtras() {
    return atras;
}

void NodoMatriz::setAtras(NodoMatriz *atras) {
    this->atras = atras;
}

std::string NodoMatriz::getNombreCabecera() {
    return nombreCabecera;
}

void NodoMatriz::setNombreCabecera(std::string nombreCabecera) {
    this->nombreCabecera = nombreCabecera;
}

Usuario *NodoMatriz::getUsuario() {
    return usuario;
}

void NodoMatriz::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}


