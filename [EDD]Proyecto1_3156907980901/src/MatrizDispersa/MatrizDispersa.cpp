//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/MatrizDispersa/MatrizDispersa.h"

MatrizDispersa::MatrizDispersa() {
    this->cabeceraHorizontal = nullptr;
    this->cabeceraVertical = nullptr;
}

bool MatrizDispersa::isVacia() {
    return (this->cabeceraHorizontal == nullptr) || (this->cabeceraVertical == nullptr);
}

Nodo *MatrizDispersa::existCabeceraHorizontal(std::string nombreCabecera) {
    if (isVacia()) return nullptr;

    Nodo *aux = this->cabeceraHorizontal;
    while (aux != nullptr) {

        if (aux->getNombreCabecera() == nombreCabecera) return aux;

        aux = aux->getSiguiente();
    }
}

Nodo *MatrizDispersa::existCabeceraVertical(std::string nombreCabecera) {
    if (isVacia()) return nullptr;

    Nodo *aux = this->cabeceraVertical;
    while (aux != nullptr) {

        if (aux->getNombreCabecera() == nombreCabecera) return aux;

        aux = aux->getAbajo();
    }
}

void MatrizDispersa::insretarUsuario(std::string usuario, std::string cabeceraHorizontal, std::string cabeceraVertical) {
    Nodo *cabeceraHorizontalActual = nullptr;
    Nodo *cabeceraVerticalActual = nullptr;

    if (isVacia()) {
        cabeceraHorizontalActual = insertarCabeceraHorizontal(cabeceraHorizontal);
        cabeceraVerticalActual = insertarCabeceraVertical(cabeceraVertical);
        insertarUsuarioFinal(usuario, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }

    cabeceraHorizontalActual = existCabeceraHorizontal(cabeceraHorizontal);
    cabeceraVerticalActual = existCabeceraVertical(cabeceraVertical);

    if (cabeceraHorizontalActual == nullptr && cabeceraVerticalActual == nullptr) {
        cabeceraHorizontalActual = insertarCabeceraHorizontal(cabeceraHorizontal);
        cabeceraVerticalActual = insertarCabeceraVertical(cabeceraVertical);
        insertarUsuarioFinal(usuario, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }

    if (cabeceraHorizontalActual == nullptr) {
        cabeceraHorizontalActual = insertarCabeceraHorizontal(cabeceraHorizontal);
        insertarUsuarioFinal(usuario, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }
    if (cabeceraVerticalActual == nullptr) {
        cabeceraVerticalActual = insertarCabeceraVertical(cabeceraVertical);
        insertarUsuarioFinal(usuario, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }


}

Nodo *MatrizDispersa::insertarCabeceraHorizontal(std::string nombreCabecera) {
    Nodo *nuevaCabecera = new Nodo(nombreCabecera);
    if (this->cabeceraHorizontal == nullptr) {
        this->cabeceraHorizontal = nuevaCabecera;
        return nuevaCabecera;
    }
    Nodo *aux = this->cabeceraHorizontal;

    while (aux->getSiguiente() != nullptr) aux = aux->getSiguiente();

    aux->setSiguiente(nuevaCabecera);
    nuevaCabecera->setPrevio(aux);
    return nuevaCabecera;
}

Nodo *MatrizDispersa::insertarCabeceraVertical(std::string nombreCabecera) {
    Nodo *nuevaCabecera = new Nodo(nombreCabecera);
    if (this->cabeceraVertical == nullptr) {
        this->cabeceraVertical = nuevaCabecera;
        return nuevaCabecera;
    }
    Nodo *aux = this->cabeceraVertical;

    while (aux->getAbajo() != nullptr) aux = aux->getAbajo();

    aux->setAbajo(nuevaCabecera);
    nuevaCabecera->setArriba(aux);
    return nuevaCabecera;
}

void MatrizDispersa::insertarUsuarioFinal(std::string usuario, Nodo *cabeceraHorizontal, Nodo *cabeceraVertical) {
    Nodo *usuarioNuevo = new Nodo(usuario);
    Nodo *auxCabeceraHorizontal = cabeceraHorizontal;
    Nodo *auxCabeceraVertical = cabeceraVertical;

    while (auxCabeceraHorizontal->getAbajo() != nullptr) auxCabeceraHorizontal = auxCabeceraHorizontal->getAbajo();

    auxCabeceraHorizontal->setAbajo(usuarioNuevo);
    usuarioNuevo->setArriba(auxCabeceraHorizontal);

    while (auxCabeceraVertical->getSiguiente() != nullptr) auxCabeceraVertical = auxCabeceraVertical->getSiguiente();

    auxCabeceraVertical->setSiguiente(usuarioNuevo);
    usuarioNuevo->setPrevio(auxCabeceraVertical);
}

void MatrizDispersa::insertarUsuarioFinalHorizontal(std::string usuario, Nodo *cabeceraHorizontal) {

}

void MatrizDispersa::insertarMedioUsuarioVertical(std::string usuario, Nodo *cabeceraVertical) {

}

void MatrizDispersa::insertarUsuarioFinalVertical(std::string usuario, Nodo *cabeceraVertical) {

}

void MatrizDispersa::insertarMedioUsuarioHorizontal(std::string usuario, Nodo *cabeceraHorizontal) {

}

Nodo *MatrizDispersa::buscarCabeceraHorizontal(Nodo *nodoActual) {
    Nodo *aux = nodoActual;

    while (aux->getArriba() != nullptr) aux = aux->getArriba();

    return aux;
}

Nodo *MatrizDispersa::buscarCabeceraVertical(Nodo *nodoActual) {
    Nodo *aux = nodoActual;

    while (aux->getPrevio() != nullptr) aux = aux->getPrevio();

    return aux;
}












