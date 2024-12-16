//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/MatrizDispersa/MatrizDispersa.h"
#include <iostream>
#include "../../includes/utils/Utils.h"

MatrizDispersa::MatrizDispersa() {
    this->cabeceraHorizontal = nullptr;
    this->cabeceraVertical = nullptr;
}

NodoMatriz *MatrizDispersa::getCabeceraHorizontal() {
    return this->cabeceraHorizontal;
}

void MatrizDispersa::setCabeceraHorizontal(NodoMatriz *nodoHorizontal) {
    this->cabeceraHorizontal = nodoHorizontal;
}

NodoMatriz *MatrizDispersa::getCabeceraVertical() {
    return this->cabeceraVertical;
}

void MatrizDispersa::setCabeceraVertical(NodoMatriz *nodoVertical) {
    this->cabeceraVertical = nodoVertical;
}

bool MatrizDispersa::isVacia() {
    return (this->cabeceraHorizontal == nullptr) || (this->cabeceraVertical == nullptr);
}

NodoMatriz *MatrizDispersa::existeDepartamento(std::string nombreCabecera) {
    if (isVacia()) return nullptr;

    NodoMatriz *aux = this->cabeceraHorizontal;
    while (aux != nullptr) {

        if (Utils::isEquals(aux->getNombreCabecera(), nombreCabecera)) return aux;

        aux = aux->getSiguiente();
    }
    return nullptr;
}

NodoMatriz *MatrizDispersa::existeEmpresa(std::string nombreCabecera) {
    if (isVacia()) return nullptr;

    NodoMatriz *aux = this->cabeceraVertical;
    while (aux != nullptr) {

        if (Utils::isEquals(aux->getNombreCabecera(), nombreCabecera)) return aux;

        aux = aux->getAbajo();
    }
    return nullptr;
}

void MatrizDispersa::insretarUsuario(Usuario *usuario, std::string departamento, std::string empresa) {
    NodoMatriz *cabeceraHorizontalActual = nullptr;
    NodoMatriz *cabeceraVerticalActual = nullptr;
    auto *usuarioNuevo = new NodoMatriz(usuario);

    if (isVacia()) {
        cabeceraHorizontalActual = insertarDepartamento(departamento);
        cabeceraVerticalActual = insertarEmpresa(empresa);
        insertarUsuarioFinal(usuarioNuevo, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }

    cabeceraHorizontalActual = existeDepartamento(departamento);
    cabeceraVerticalActual = existeEmpresa(empresa);

    if (cabeceraHorizontalActual == nullptr && cabeceraVerticalActual == nullptr) {
        cabeceraHorizontalActual = insertarDepartamento(departamento);
        cabeceraVerticalActual = insertarEmpresa(empresa);
        insertarUsuarioFinal(usuarioNuevo, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }

    if (cabeceraHorizontalActual == nullptr) {
        cabeceraHorizontalActual = insertarDepartamento(departamento);
        insertarUsuarioFinal(usuarioNuevo, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }
    if (cabeceraVerticalActual == nullptr) {
        cabeceraVerticalActual = insertarEmpresa(empresa);
        insertarUsuarioFinal(usuarioNuevo, cabeceraHorizontalActual, cabeceraVerticalActual);
        return;
    }

    //CASOS EN DONDE LAS DOS CABECERAS YA EXISTEN
    NodoMatriz *usuarios = existeNodoInterseccion(departamento, empresa);
    if (usuarios != nullptr) {
        if (existeUsuario(usuarios, usuario->getUsername(), usuario->getPassword())) {
            std::cout << "Error!!! El usuario ingresado ya se encuentra en el Departamento y Empresa" << std::endl;
        } else {
            char opcion;
            do {
                std::cout << "¿En que posicion quiere guardar al usuario?" << std::endl;
                std::cout << "1.Delante de los Usuarios actuales" << std::endl;
                std::cout << "2.Atras de los usuario actuales" << std::endl;
                std::cin >> opcion;
                switch (opcion) {
                    case '1': {
                        insertarUsuarioEnFrente(usuarioNuevo, usuarios);
                        std::cout << "Nuevo Usuario Ingresado al Sistema" << std::endl;
                        break;
                    }
                    case '2': {
                        insertarUsuarioAtras(usuarioNuevo, usuarios);
                        std::cout << "Nuevo Usuario Ingresado al Sistema" << std::endl;
                        break;
                    }
                    default: {
                        std::cout << "Error!!! Opcion no valida." << std::endl;
                        break;
                    }
                }
            } while (opcion != '1' && opcion != '2');
        }
        return;
    }

    NodoMatriz *auxCabeceraHorizontal = cabeceraHorizontalActual->getAbajo();
    NodoMatriz *usuarioCabeceraVertical = nullptr;
    bool isAbajo = false;
    while (auxCabeceraHorizontal != nullptr) {
        usuarioCabeceraVertical = buscarCabeceraVertical(auxCabeceraHorizontal);
        isAbajo = masAbajo(usuarioCabeceraVertical, empresa);
        if (!isAbajo) break;
        auxCabeceraHorizontal = auxCabeceraHorizontal->getAbajo();
    }
    if (isAbajo) {
        insertarUsuarioFinalHorizontal(usuarioNuevo, cabeceraHorizontalActual);
    } else {
        insertarMedioUsuarioHorizontal(usuarioNuevo, auxCabeceraHorizontal);
    }

    NodoMatriz *auxCabeceraVertical = cabeceraVerticalActual->getSiguiente();
    NodoMatriz *usuarioCabeceraHorizontal = nullptr;
    bool isDerecha = false;
    while (auxCabeceraVertical != nullptr) {
        usuarioCabeceraHorizontal = buscarCabeceraHorizontal(auxCabeceraVertical);
        isDerecha = masDerecha(usuarioCabeceraHorizontal, departamento);
        if (!isDerecha) break;
        auxCabeceraVertical = auxCabeceraVertical->getSiguiente();
    }
    if (isDerecha) {
        insertarUsuarioFinalVertical(usuarioNuevo, cabeceraVerticalActual);
    } else {
        insertarMedioUsuarioVertical(usuarioNuevo, auxCabeceraVertical);
    }
    std::cout << "Nuevo Usuario Ingresado al Sistema" << std::endl;
}

NodoMatriz *MatrizDispersa::insertarDepartamento(std::string nombreCabecera) {
    auto *nuevaCabecera = new NodoMatriz(nombreCabecera);
    NodoMatriz::contadorGrupo++;
    nuevaCabecera->setGrupo(NodoMatriz::contadorGrupo);
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

NodoMatriz *MatrizDispersa::insertarEmpresa(std::string nombreCabecera) {
    auto *nuevaCabecera = new NodoMatriz(nombreCabecera);
    nuevaCabecera->setGrupo(1);
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

void MatrizDispersa::insertarUsuarioFinal(NodoMatriz *usuarioNuevo, NodoMatriz *cabeceraHorizontal, NodoMatriz *cabeceraVertical) {
    insertarUsuarioFinalHorizontal(usuarioNuevo, cabeceraHorizontal);
    insertarUsuarioFinalVertical(usuarioNuevo, cabeceraVertical);
    std::cout << "Registro Realizado con Exito!!!" << std::endl;
}

void MatrizDispersa::insertarUsuarioFinalHorizontal(NodoMatriz *usuarioNuevo, NodoMatriz *cabeceraHorizontal) {
    NodoMatriz *aux = cabeceraHorizontal;

    while (aux->getAbajo() != nullptr) aux = aux->getAbajo();

    aux->setAbajo(usuarioNuevo);
    usuarioNuevo->setArriba(aux);
    usuarioNuevo->setGrupo(aux->getGrupo());
}

void MatrizDispersa::insertarUsuarioFinalVertical(NodoMatriz *usuarioNuevo, NodoMatriz *cabeceraVertical) {
    NodoMatriz *aux = cabeceraVertical;

    while (aux->getSiguiente() != nullptr) aux = aux->getSiguiente();

    aux->setSiguiente(usuarioNuevo);
    usuarioNuevo->setPrevio(aux);
}

void MatrizDispersa::insertarMedioUsuarioHorizontal(NodoMatriz *usuario, NodoMatriz *cabeceraHorizontal) {
    cabeceraHorizontal->getArriba()->setAbajo(usuario);
    usuario->setAbajo(cabeceraHorizontal);
    usuario->setArriba(cabeceraHorizontal->getArriba());
    cabeceraHorizontal->setArriba(usuario);
    usuario->setGrupo(cabeceraHorizontal->getGrupo());
}

void MatrizDispersa::insertarMedioUsuarioVertical(NodoMatriz *usuario, NodoMatriz *cabeceraVertical) {
    cabeceraVertical->getPrevio()->setSiguiente(usuario);
    usuario->setSiguiente(cabeceraVertical);
    usuario->setPrevio(cabeceraVertical->getPrevio());
    cabeceraVertical->setPrevio(usuario);
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

bool MatrizDispersa::masAbajo(NodoMatriz *cabeceraVertical, std::string empresa) {
    NodoMatriz *aux = cabeceraVertical;
    while (aux != nullptr) {

        if (Utils::isEquals(aux->getNombreCabecera(), empresa)) return true;

        aux = aux->getAbajo();
    }
    return false;
}

bool MatrizDispersa::masDerecha(NodoMatriz *cabeceraHorizontal, std::string departamento) {
    NodoMatriz *aux = cabeceraHorizontal;
    while (aux != nullptr) {

        if (Utils::isEquals(aux->getNombreCabecera(), departamento)) return true;

        aux = aux->getSiguiente();
    }
    return false;
}

NodoMatriz *MatrizDispersa::existeNodoInterseccion(std::string departamento, std::string empresa) {
    NodoMatriz *nodoDepartamento = this->existeDepartamento(departamento);
    NodoMatriz *nodoEmpresa = this->existeEmpresa(empresa);

    if (nodoDepartamento == nullptr || nodoEmpresa == nullptr) return nullptr;

    NodoMatriz *aux = nodoDepartamento->getAbajo();
    while (aux != nullptr) {

        if (Utils::isEquals(nodoEmpresa->getNombreCabecera(), buscarCabeceraVertical(aux)->getNombreCabecera())) return aux;

        aux = aux->getAbajo();
    }
    return nullptr;
}

bool MatrizDispersa::existeUsuario(NodoMatriz *usuarios, std::string username, std::string password) {
    NodoMatriz *aux = usuarios;
    if (aux != nullptr) {
        while (aux != nullptr) {

            if (Utils::isEquals(aux->getUsuario()->getUsername(), username) && Utils::isEquals(aux->getUsuario()->getPassword(), password)) return true;

            aux = aux->getAtras();
        }
    }
    return false;
}

void MatrizDispersa::insertarUsuarioAtras(NodoMatriz *nuevoUsuario, NodoMatriz *usuarios) {
    NodoMatriz *aux = usuarios;

    while (aux->getAtras() != nullptr) aux = aux->getAtras();

    aux->setAtras(nuevoUsuario);
    nuevoUsuario->setAdelante(aux);
    nuevoUsuario->setGrupo(aux->getGrupo());
}

void MatrizDispersa::insertarUsuarioEnFrente(NodoMatriz *nuevoUsuario, NodoMatriz *usuarios) {
    usuarios->setAdelante(nuevoUsuario);
    nuevoUsuario->setAtras(usuarios);

    usuarios->getPrevio()->setSiguiente(nuevoUsuario);
    nuevoUsuario->setSiguiente(usuarios->getSiguiente());
    if (usuarios->getSiguiente() != nullptr) {
        usuarios->getSiguiente()->setPrevio(nuevoUsuario);
    }
    nuevoUsuario->setPrevio(usuarios->getPrevio());
    usuarios->setPrevio(nullptr);
    usuarios->setSiguiente(nullptr);

    usuarios->getArriba()->setAbajo(nuevoUsuario);
    nuevoUsuario->setAbajo(usuarios->getAbajo());
    if (usuarios->getAbajo() != nullptr) {
        usuarios->getAbajo()->setArriba(nuevoUsuario);
    }
    nuevoUsuario->setArriba(usuarios->getArriba());
    usuarios->setArriba(nullptr);
    usuarios->setAbajo(nullptr);

    nuevoUsuario->setGrupo(usuarios->getGrupo());
}

NodoArbol *MatrizDispersa::catalogoActivos(Usuario *usuario, bool disponibilidadActivos, std::string idActivo) {
    if (!this->isVacia()) {
        return this->catalogoActivos(usuario, this->cabeceraVertical, disponibilidadActivos, idActivo);
    }
}

NodoArbol *MatrizDispersa::catalogoActivos(Usuario *usuario, NodoMatriz *nodo, bool disponibilidadActivos, std::string idActivo) {
    NodoMatriz *aux = nodo;
    NodoMatriz *aux2;
    if (aux != nullptr) {
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
            aux2 = aux;
            do {
                if (aux2->getUsuario() != usuario) {
                    if (disponibilidadActivos) {
                        aux2->getUsuario()->getArbol()->mostrarActivos(true);
                    } else {
                        NodoArbol *activoRentado = aux2->getUsuario()->getArbol()->buscarActivo(idActivo, aux2->getUsuario()->getArbol()->getRaiz());

                        if (activoRentado != nullptr) return activoRentado;

                    }
                }
                aux2 = aux->getAtras();
            } while (aux2 != nullptr);
        }
        return catalogoActivos(usuario, nodo->getAbajo(), disponibilidadActivos, idActivo);
    }
}


