//
// Created by Carlos Cotom on 12/12/2024.
//

#ifndef NODOARBOL_H
#define NODOARBOL_H
#include "../models/Activo.h"


class NodoArbol {

private:
    Activo *activo;
    NodoArbol *hijoIzquierdo;
    NodoArbol *hijoDerecho;
    int factorEquilibrio;

public:
    NodoArbol(Activo *activo);

    Activo *getActivo();
    void setActivo(Activo *activo);

    NodoArbol *&getHijoIzquierdo();
    void setHijoIzquierdo(NodoArbol *hijoIzquierdo);

    NodoArbol *&getHijoDerecho();
    void setHijoDerecho(NodoArbol *hijoDerecho);

    int getFactorEquilibrio();
    void setFactorEquilibrio(int factorEquilibrio);

};



#endif //NODOARBOL_H
