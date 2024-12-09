//
// Created by Carlos Cotom on 8/12/2024.
//

#ifndef MENUS_H
#define MENUS_H
#include <string>
#include <iostream>

#include "../MatrizDispersa/NodoMatriz.h"


class Menus {

public:
    void menuPrincipal();
    void login();

    void menuAdministrador();
    void registroUsuario();
    void reporteActivosUsuario();

    void menuUsuario(NodoMatriz *usuarioLogeado);
    void modificarActivo();
    void rentaActivo(NodoMatriz *usuarioLogeado);
    void activosRentados(NodoMatriz *usuarioLogeado);

};



#endif //MENUS_H
