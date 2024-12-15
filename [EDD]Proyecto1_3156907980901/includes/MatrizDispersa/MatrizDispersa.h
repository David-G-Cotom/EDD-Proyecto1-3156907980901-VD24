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

    void insertarUsuarioFinal(NodoMatriz *usuarioNuevo, NodoMatriz *cabeceraHorizontal, NodoMatriz *cabeceraVertical);

    void insertarUsuarioFinalHorizontal(NodoMatriz *usuarioNuevo, NodoMatriz *cabeceraHorizontal);
    void insertarUsuarioFinalVertical(NodoMatriz *usuarioNuevo, NodoMatriz *cabeceraVertical);
    void insertarMedioUsuarioHorizontal(NodoMatriz *usuario, NodoMatriz *cabeceraHorizontal);
    void insertarMedioUsuarioVertical(NodoMatriz *usuario, NodoMatriz *cabeceraVertical);

    bool masAbajo(NodoMatriz *cabeceraVertical, std::string empresa);
    bool masDerecha(NodoMatriz *cabeceraHorizontal, std::string departamento);

    bool existeUsuario(NodoMatriz *usuarios, std::string userName, std::string password);

    void insertarUsuarioAtras(NodoMatriz *nuevoUsuario, NodoMatriz *usuarios);
    void insertarUsuarioEnFrente(NodoMatriz *nuevoUsuario, NodoMatriz *usuarios);

    NodoArbol *catalogoActivos(Usuario *usuario, NodoMatriz *nodo, bool disponibilidadActivos, std::string idActivo);

public:
    MatrizDispersa();

    NodoMatriz *getCabeceraHorizontal();
    void setCabeceraHorizontal(NodoMatriz *nodoHorizontal);
    NodoMatriz *getCabeceraVertical();
    void setCabeceraVertical(NodoMatriz *nodoVertical);

    bool isVacia();

    NodoMatriz *existeDepartamento(std::string nombreCabecera);
    NodoMatriz *existeEmpresa(std::string valor);

    void insretarUsuario(Usuario *usuario, std::string departamento, std::string empresa);

    NodoMatriz *insertarDepartamento(std::string nombreCabecera);
    NodoMatriz *insertarEmpresa(std::string nombreCabecera);

    NodoMatriz *buscarCabeceraHorizontal(NodoMatriz *nodoActual);
    NodoMatriz *buscarCabeceraVertical(NodoMatriz *nodoActual);

    NodoMatriz *existeNodoInterseccion(std::string departamento, std::string empresa);

    NodoArbol *catalogoActivos(Usuario *usuario, bool disponibilidadActivos, std::string idActivo);

};



#endif //MATRIZDISPERSA_H
