//
// Created by Carlos Cotom on 8/12/2024.
//

#ifndef MENUS_H
#define MENUS_H
#include <string>


class Menus {

public:
    void menuPrincipal();
    void login(bool isAdmin);
    void menuAdministrador();
    void menuUsuario(std::string nombreUsuario);

};



#endif //MENUS_H
