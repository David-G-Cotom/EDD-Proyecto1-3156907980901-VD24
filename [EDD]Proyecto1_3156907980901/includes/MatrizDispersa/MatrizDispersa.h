//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "NodoMatriz.h"

class MatrizDispersa {

private:
    NodoMatriz *cabeceraHorizontal;
    NodoMatriz *cabeceraVertical;

public:
    MatrizDispersa();

    bool isVacia();

    NodoMatriz *existCabeceraHorizontal(std::string nombreCabecera);
    NodoMatriz *existCabeceraVertical(std::string valor);

    void insretarUsuario(Usuario *usuario, std::string cabeceraHorizontal, std::string cabeceraVertical);

    NodoMatriz *insertarCabeceraHorizontal(std::string nombreCabecera);
    NodoMatriz *insertarCabeceraVertical(std::string nombreCabecera);

    void insertarUsuarioFinal(Usuario *usuario, NodoMatriz *cabeceraHorizontal, NodoMatriz *cabeceraVertical);

    void insertarUsuarioFinalHorizontal(std::string usuario, NodoMatriz *cabeceraHorizontal);
    void insertarMedioUsuarioVertical(std::string usuario, NodoMatriz *cabeceraVertical);
    void insertarUsuarioFinalVertical(std::string usuario, NodoMatriz *cabeceraVertical);
    void insertarMedioUsuarioHorizontal(std::string usuario, NodoMatriz *cabeceraHorizontal);

    NodoMatriz *buscarCabeceraHorizontal(NodoMatriz *nodoActual);
    NodoMatriz *buscarCabeceraVertical(NodoMatriz *nodoActual);

    NodoMatriz *existeNodoInterseccion(std::string departamento, std::string empresa);

};



#endif //MATRIZDISPERSA_H
