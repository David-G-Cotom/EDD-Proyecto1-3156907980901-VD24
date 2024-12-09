//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/models/Usuario.h"

Usuario::Usuario(std::string nombre, std::string username, std::string password) {
    this->nombre = nombre;
    this->username = username;
    this->password = password;
}

std::string Usuario::getNombre() {
    return this->nombre;
}

void Usuario::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Usuario::getUsername() {
    return this->username;
}

void Usuario::setUsername(std::string username) {
    this->username = username;
}

std::string Usuario::getPassword() {
    return this->password;
}

void Usuario::setPassword(std::string password) {
    this->password = password;
}


