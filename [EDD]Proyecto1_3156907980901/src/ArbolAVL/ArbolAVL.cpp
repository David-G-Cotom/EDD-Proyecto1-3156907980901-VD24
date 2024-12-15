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

    this->equilibrarArbol(raiz);
}

void ArbolAVL::eliminar(std::string idActivo, NodoArbol *&raiz) {
    if (raiz == nullptr) {
        std::cout << "Error en Eliminar Activo!!! Activo NO Existente" << std::endl;;
        return;
    }
    if (idActivo == raiz->getActivo()->getId()) {
        if (this->isHoja(raiz)) {
            raiz = nullptr;
            return;
        }

        if (raiz->getHijoIzquierdo() == nullptr) {
            raiz = raiz->getHijoDerecho();
            return;
        }
        if (raiz->getHijoDerecho() == nullptr) {
            raiz = raiz->getHijoIzquierdo();
            return;
        }

        NodoArbol *nodoDerecho = this->masDerecha(raiz->getHijoIzquierdo());
        raiz->setActivo(nodoDerecho->getActivo());
        eliminar(nodoDerecho->getActivo()->getId(), raiz->getHijoIzquierdo());
        idActivo = raiz->getActivo()->getId();
    }
    if (idActivo < raiz->getActivo()->getId()) {
        eliminar(idActivo, raiz->getHijoIzquierdo());
    }
    if (idActivo > raiz->getActivo()->getId()) {
        eliminar(idActivo, raiz->getHijoDerecho());
    }

    this->equilibrarArbol(raiz);
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
    NodoArbol *aux = nodo->getHijoDerecho();
    nodo->setHijoDerecho(aux->getHijoIzquierdo());
    aux->setHijoIzquierdo(nodo);
    nodo = aux;
    nodo->setFactorEquilibrio(this->factorEquilibrio(nodo));
    nodo->getHijoIzquierdo()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoIzquierdo()));

    if (nodo->getHijoDerecho() == nullptr) return;

    nodo->getHijoDerecho()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoDerecho()));
}

void ArbolAVL::rotacionDerecho(NodoArbol *&nodo) {
    NodoArbol *aux = nodo->getHijoIzquierdo();
    nodo->setHijoIzquierdo(aux->getHijoDerecho());
    aux->setHijoDerecho(nodo);
    nodo = aux;
    nodo->setFactorEquilibrio(this->factorEquilibrio(nodo));
    nodo->getHijoDerecho()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoDerecho()));

    if (nodo->getHijoIzquierdo() == nullptr) return;

    nodo->getHijoIzquierdo()->setFactorEquilibrio(this->factorEquilibrio(nodo->getHijoIzquierdo()));
}

void ArbolAVL::rotacionIzquierdaDoble(NodoArbol *&nodo) {
    rotacionDerecho(nodo->getHijoDerecho());
    rotacionIzquierda(nodo);
}

void ArbolAVL::rotacionDerechaDoble(NodoArbol *&nodo) {
    rotacionIzquierda(nodo->getHijoIzquierdo());
    rotacionDerecho(nodo);
}

bool ArbolAVL::isHoja(NodoArbol *nodo) {
    return nodo->getHijoIzquierdo() == nullptr && nodo->getHijoDerecho() == nullptr;
}

NodoArbol *ArbolAVL::masDerecha(NodoArbol *&nodo) {
    if (nodo->getHijoDerecho() == nullptr) {
        return nodo;
    }
    return masDerecha(nodo->getHijoDerecho());
}

void ArbolAVL::equilibrarArbol(NodoArbol *raiz) {
    raiz->setFactorEquilibrio(this->factorEquilibrio(raiz));
    if (raiz->getFactorEquilibrio() < -1) {
        if (raiz->getHijoIzquierdo()->getFactorEquilibrio() > 0) {
            rotacionDerechaDoble(raiz);
            return;
        }
        rotacionDerecho(raiz);
        return;
    }
    if (raiz->getFactorEquilibrio() > 1) {
        if (raiz->getHijoDerecho()->getFactorEquilibrio() < 0) {
            rotacionIzquierdaDoble(raiz);
            return;
        }
        rotacionIzquierda(raiz);
    }
}

void ArbolAVL::mostrarActivosPreOrden(NodoArbol *nodo, bool disponibilidadActivos) {
    if (nodo != nullptr) {
        if (nodo->getActivo()->getDisponibilidad() == disponibilidadActivos) {
            std::cout << ">> ID = " << nodo->getActivo()->getId() << "; Nombre = " << nodo->getActivo()->getNombre() << "; Descripcion = " << nodo->getActivo()->getDescripcion() << std::endl;
        }
        mostrarActivosPreOrden(nodo->getHijoIzquierdo(), disponibilidadActivos);
        mostrarActivosPreOrden(nodo->getHijoDerecho(), disponibilidadActivos);
    }
}

NodoArbol *ArbolAVL::buscarActivo(std::string idActivo, NodoArbol *nodo) {
    if (nodo != nullptr) {
        if (nodo->getActivo()->getId() == idActivo) {
            return nodo;
        }
        if (idActivo > nodo->getActivo()->getId()) {
            return buscarActivo(idActivo, nodo->getHijoDerecho());
        }
        if (idActivo < nodo->getActivo()->getId()) {
            return buscarActivo(idActivo, nodo->getHijoIzquierdo());
        }
    } else {
        return nullptr;
    }
}

void ArbolAVL::insertar(Activo *nuevoActivo) {
    auto *nuevoNodo = new NodoArbol(nuevoActivo);
    insertar(nuevoNodo, this->raiz);
    std::cout << "Nuevo Activo Ingresado!!!" << std::endl;
}

void ArbolAVL::eliminar(std::string idActivo) {
    this->eliminar(idActivo, this->raiz);
    std::cout << "Activo Eliminado Exitosamente!!!" << std::endl;
}

bool ArbolAVL::mostrarActivos(bool disponibilidadActivos) {
    if (this->raiz != nullptr) {
        this->mostrarActivosPreOrden(this->raiz, disponibilidadActivos);
        return true;
    }
    return false;
}

void ArbolAVL::modificarActivo(std::string idActivo, std::string nuevaDescripcion) {
    NodoArbol *activo = this->buscarActivo(idActivo, this->raiz);
    if (activo != nullptr) {
        activo->getActivo()->setDescripcion(nuevaDescripcion);
        std::cout << "Activo Modificado:" << std::endl;
        std::cout << "ID = " << activo->getActivo()->getId() << "; Nombre = " << activo->getActivo()->getNombre() << "; Descripcion = " << activo->getActivo()->getDescripcion() << std::endl;
        return;
    }
    std::cout << "No Existe el Activo";
}


