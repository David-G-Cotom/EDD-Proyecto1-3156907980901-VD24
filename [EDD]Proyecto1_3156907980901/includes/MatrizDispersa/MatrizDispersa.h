//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "Nodo.h"

class MatrizDispersa {

private:
    Nodo *cabeceraHorizontal;
    Nodo *cabeceraVertical;

public:
    MatrizDispersa();

    bool isVacia();

    Nodo *existCabeceraHorizontal(std::string nombreCabecera);
    Nodo *existCabeceraVertical(std::string valor);

    void insretarUsuario(std::string usuario, std::string cabeceraHorizontal, std::string cabeceraVertical);

    Nodo *insertarCabeceraHorizontal(std::string nombreCabecera);
    Nodo *insertarCabeceraVertical(std::string nombreCabecera);

    void insertarUsuarioFinal(std::string usuario, Nodo *cabeceraHorizontal, Nodo *cabeceraVertical);

    void insertarUsuarioFinalHorizontal(std::string usuario, Nodo *cabeceraHorizontal);
    void insertarMedioUsuarioVertical(std::string usuario, Nodo *cabeceraVertical);
    void insertarUsuarioFinalVertical(std::string usuario, Nodo *cabeceraVertical);
    void insertarMedioUsuarioHorizontal(std::string usuario, Nodo *cabeceraHorizontal);

    Nodo *buscarCabeceraHorizontal(Nodo *nodoActual);
    Nodo *buscarCabeceraVertical(Nodo *nodoActual);

};



#endif //MATRIZDISPERSA_H
