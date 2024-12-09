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

    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getUsername();
    void setUsername(std::string username);
    std::string getPassword();
    void setPassword(std::string password);

};



#endif //USUARIO_H
