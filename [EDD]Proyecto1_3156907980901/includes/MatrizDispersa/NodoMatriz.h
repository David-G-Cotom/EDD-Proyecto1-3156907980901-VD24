//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef NODO_H
#define NODO_H
#include <string>
#include "../models/Usuario.h"


class NodoMatriz {

private:
    NodoMatriz *siguiente;
    NodoMatriz *previo;

    NodoMatriz *arriba;
    NodoMatriz *abajo;

    NodoMatriz *adelante;
    NodoMatriz *atras;

    std::string nombreCabecera;
    Usuario *usuario;

    int id;
    int grupo;

public:
    static int contadorID;
    static int contadorGrupo;

    NodoMatriz(std::string nombreCabecera);
    NodoMatriz(Usuario *usuario);

    NodoMatriz *getSiguiente();
    void setSiguiente(NodoMatriz *siguiente);

    NodoMatriz *getPrevio();
    void setPrevio(NodoMatriz *previo);

    NodoMatriz *getArriba();
    void setArriba(NodoMatriz *arriba);

    NodoMatriz *getAbajo();
    void setAbajo(NodoMatriz *abajo);

    NodoMatriz *getAdelante();
    void setAdelante(NodoMatriz *adelante);

    NodoMatriz *getAtras();
    void setAtras(NodoMatriz *atras);

    std::string getNombreCabecera();
    void setNombreCabecera(std::string nombreCabecera);

    Usuario *getUsuario();
    void setUsuario(Usuario *usuario);

    int getId();
    void setId(int id);

    int getGrupo();
    void setGrupo(int grupo);

};



#endif //NODO_H
