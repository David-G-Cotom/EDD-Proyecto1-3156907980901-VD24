//
// Created by Carlos Cotom on 12/12/2024.
//

#ifndef REPORTEARBOLAVL_H
#define REPORTEARBOLAVL_H

#include "ArbolAVL.h"

class ReporteArbolAVL {

private:
    ArbolAVL *arbolAVL;

    std::string recorrerActivosPreOrden(NodoArbol *nodo, std::string username);

public:
    ReporteArbolAVL(ArbolAVL *arbolAVL);

    void reporteActivosUsuario(NodoArbol *nodo, std::string username);

    std::string reporteActivosCabeceras(NodoArbol *nodo, std::string dot);

};



#endif //REPORTEARBOLAVL_H
