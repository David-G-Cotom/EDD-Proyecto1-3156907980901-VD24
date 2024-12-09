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

NodoMatriz *MatrizDispersa::existCabeceraHorizontal(std::string nombreCabecera) {
    if (isVacia()) return nullptr;

    NodoMatriz *aux = this->cabeceraHorizontal;
    while (aux != nullptr) {

        if (aux->getNombreCabecera() == nombreCabecera) return aux;

        aux = aux->getSiguiente();
    }
    return nullptr;
}

NodoMatriz *MatrizDispersa::existCabeceraVertical(std::string nombreCabecera) {
    if (isVacia()) return nullptr;

    NodoMatriz *aux = this->cabeceraVertical;
    while (aux != nullptr) {

        if (aux->getNombreCabecera() == nombreCabecera) return aux;

        aux = aux->getAbajo();
    }
    return nullptr;
}

void MatrizDispersa::insretarUsuario(Usuario *usuario, std::string cabeceraHorizontal, std::string cabeceraVertical) {
    NodoMatriz *cabeceraHorizontalActual = nullptr;
    NodoMatriz *cabeceraVerticalActual = nullptr;

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

NodoMatriz *MatrizDispersa::insertarCabeceraHorizontal(std::string nombreCabecera) {
    auto *nuevaCabecera = new NodoMatriz(nombreCabecera);
    if (this->cabeceraHorizontal == nullptr) {
        this->cabeceraHorizontal = nuevaCabecera;
        return nuevaCabecera;
    }
    NodoMatriz *aux = this->cabeceraHorizontal;

    while (aux->getSiguiente() != nullptr) aux = aux->getSiguiente();

    aux->setSiguiente(nuevaCabecera);
    nuevaCabecera->setPrevio(aux);
    return nuevaCabecera;
}

NodoMatriz *MatrizDispersa::insertarCabeceraVertical(std::string nombreCabecera) {
    auto *nuevaCabecera = new NodoMatriz(nombreCabecera);
    if (this->cabeceraVertical == nullptr) {
        this->cabeceraVertical = nuevaCabecera;
        return nuevaCabecera;
    }
    NodoMatriz *aux = this->cabeceraVertical;

    while (aux->getAbajo() != nullptr) aux = aux->getAbajo();

    aux->setAbajo(nuevaCabecera);
    nuevaCabecera->setArriba(aux);
    return nuevaCabecera;
}

void MatrizDispersa::insertarUsuarioFinal(Usuario *usuario, NodoMatriz *cabeceraHorizontal, NodoMatriz *cabeceraVertical) {
    auto *usuarioNuevo = new NodoMatriz(usuario);
    NodoMatriz *auxCabeceraHorizontal = cabeceraHorizontal;
    NodoMatriz *auxCabeceraVertical = cabeceraVertical;

    while (auxCabeceraHorizontal->getAbajo() != nullptr) auxCabeceraHorizontal = auxCabeceraHorizontal->getAbajo();

    auxCabeceraHorizontal->setAbajo(usuarioNuevo);
    usuarioNuevo->setArriba(auxCabeceraHorizontal);

    while (auxCabeceraVertical->getSiguiente() != nullptr) auxCabeceraVertical = auxCabeceraVertical->getSiguiente();

    auxCabeceraVertical->setSiguiente(usuarioNuevo);
    usuarioNuevo->setPrevio(auxCabeceraVertical);
}

void MatrizDispersa::insertarUsuarioFinalHorizontal(std::string usuario, NodoMatriz *cabeceraHorizontal) {

}

void MatrizDispersa::insertarMedioUsuarioVertical(std::string usuario, NodoMatriz *cabeceraVertical) {

}

void MatrizDispersa::insertarUsuarioFinalVertical(std::string usuario, NodoMatriz *cabeceraVertical) {

}

void MatrizDispersa::insertarMedioUsuarioHorizontal(std::string usuario, NodoMatriz *cabeceraHorizontal) {

}

NodoMatriz *MatrizDispersa::buscarCabeceraHorizontal(NodoMatriz *nodoActual) {
    NodoMatriz *aux = nodoActual;

    while (aux->getArriba() != nullptr) aux = aux->getArriba();

    return aux;
}

NodoMatriz *MatrizDispersa::buscarCabeceraVertical(NodoMatriz *nodoActual) {
    NodoMatriz *aux = nodoActual;

    while (aux->getPrevio() != nullptr) aux = aux->getPrevio();

    return aux;
}

NodoMatriz *MatrizDispersa::existeNodoInterseccion(std::string departamento, std::string empresa) {
    NodoMatriz *nodoDepartamento = this->existCabeceraHorizontal(departamento);
    NodoMatriz *nodoEmpresa = this->existCabeceraVertical(empresa);

    if (nodoDepartamento == nullptr || nodoEmpresa == nullptr) return nullptr;

    NodoMatriz *aux = nodoDepartamento->getAbajo();
    while (aux != nullptr) {

        if (nodoEmpresa->getNombreCabecera() == buscarCabeceraVertical(aux)->getNombreCabecera()) return aux;

        aux = aux->getAbajo();
    }
    return nullptr;
}


