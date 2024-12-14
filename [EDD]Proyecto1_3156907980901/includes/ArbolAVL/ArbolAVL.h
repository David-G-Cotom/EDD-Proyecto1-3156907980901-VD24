//
// Created by Carlos Cotom on 12/12/2024.
//

#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoArbol.h"
#include <iostream>


class ArbolAVL {

private:
    NodoArbol *raiz;

    void insertar(NodoArbol *activo, NodoArbol *&raiz);
    void eliminar(std::string idActivo, NodoArbol *&raiz);

    int alturaMax(NodoArbol *nodo);
    int factorEquilibrio(NodoArbol *nodo);

    void rotacionIzquierda(NodoArbol *&nodo);
    void rotacionDerecho(NodoArbol *&nodo);

    void rotacionIzquierdaDoble(NodoArbol *&nodo);
    void rotacionDerechaDoble(NodoArbol *&nodo);

    bool isHoja(NodoArbol *nodo);

    NodoArbol *masDerecha(NodoArbol *&nodo);

    void equilibrarArbol(NodoArbol *raiz);

    void mostrarActivosPreOrden(NodoArbol *nodo, bool disponibilidadActivos);

public:
    ArbolAVL();

    NodoArbol* getRaiz();
    void setRaiz(NodoArbol* raiz);

    void insertar(Activo *nuevoActivo);
    void eliminar(std::string idActivo);

    bool mostrarActivos(bool disponibilidadActivos);

};



#endif //ARBOLAVL_H
