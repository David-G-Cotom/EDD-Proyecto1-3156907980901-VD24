//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/models/Usuario.h"

Usuario::Usuario(std::string nombre, std::string username, std::string password) {
    this->nombre = nombre;
    this->username = username;
    this->password = password;
}

std::string Usuario::get_nombre() {
    return this->nombre;
}

void Usuario::set_nombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Usuario::get_username() {
    return this->username;
}

void Usuario::set_username(std::string username) {
    this->username = username;
}

std::string Usuario::get_password() {
    return this->password;
}

void Usuario::set_password(std::string password) {
    this->password = password;
}


