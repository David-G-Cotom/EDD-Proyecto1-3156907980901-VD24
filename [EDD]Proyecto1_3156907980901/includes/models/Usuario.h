//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>


class Usuario {

private:
    std::string nombre;
    std::string username;
    std::string password;

public:
    Usuario(std::string nombre, std::string username, std::string password);

    std::string get_nombre();
    void set_nombre(std::string nombre);
    std::string get_username();
    void set_username(std::string username);
    std::string get_password();
    void set_password(std::string password);

};



#endif //USUARIO_H
