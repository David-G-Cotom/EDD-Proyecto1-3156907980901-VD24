//
// Created by Carlos Cotom on 8/12/2024.
//

#ifndef MENUS_H
#define MENUS_H

#include "../MatrizDispersa/NodoMatriz.h"


class Menus {

public:
    void cargarDatos();

    void menuPrincipal();

private:
    void login();

    void menuAdministrador();
    void registroUsuario();
    void reporteActivosUsuario();

    void menuUsuario(NodoMatriz *usuarioLogeado);
    void modificarActivo(NodoMatriz *usuarioLogeado);
    void rentaActivo(NodoMatriz *usuarioLogeado);
    void activosRentados(NodoMatriz *usuarioLogeado);

    void regresarMenu();

};



#endif //MENUS_H
