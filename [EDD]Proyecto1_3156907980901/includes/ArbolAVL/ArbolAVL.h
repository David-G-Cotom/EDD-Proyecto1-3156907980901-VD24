//
// Created by Carlos Cotom on 12/12/2024.
//

#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoArbol.h"


class ArbolAVL {

private:
    NodoArbol *raiz;

    void insertar(NodoArbol *activo, NodoArbol *&raiz);

    int alturaMax(NodoArbol *nodo);
    int factorEquilibrio(NodoArbol *nodo);

    void rotacionIzquierda(NodoArbol *&nodo);
    void rotacionDerecho(NodoArbol *&nodo);

    void rotacionIzquierdaDoble(NodoArbol *&nodo);
    void rotacionDerechaDoble(NodoArbol *&nodo);

    bool isHoja(NodoArbol *nodo);

public:
    ArbolAVL();

    NodoArbol* getRaiz();
    void setRaiz(NodoArbol* raiz);

    void insertar(Activo *nuevoActivo);

};



#endif //ARBOLAVL_H
