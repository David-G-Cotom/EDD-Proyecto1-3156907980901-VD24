//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef NODO_H
#define NODO_H
#include <string>


class Nodo {

private:
    Nodo *siguiente;
    Nodo *previo;

    Nodo *arriba;
    Nodo *abajo;

    Nodo *adelante;
    Nodo *atras;

    std::string nombreCabecera;

public:
    Nodo(std::string nombreCabecera);

    Nodo *getSiguiente();
    void setSiguiente(Nodo *siguiente);

    Nodo *getPrevio();
    void setPrevio(Nodo *previo);

    Nodo *getArriba();
    void setArriba(Nodo *arriba);

    Nodo *getAbajo();
    void setAbajo(Nodo *abajo);

    Nodo *getAdelante();
    void setAdelante(Nodo *adelante);

    Nodo *getAtras();
    void setAtras(Nodo *atras);

    std::string getNombreCabecera();
    void setNombreCabecera(std::string nombreCabecera);

};



#endif //NODO_H
