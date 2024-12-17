//
// Created by Carlos Cotom on 7/12/2024.
//

#include "../../includes/models/Activo.h"
#include "../../includes/utils/Utils.h"

Activo::Activo(std::string nombre, std::string descripcion, int diasDisponibles) {
    this->id = Utils::generarIDAlfanumerico();
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->disponibilidad = true;
    this->diasDisponibles = diasDisponibles;
}

std::string Activo::getId() {
    return id;
}

void Activo::setId(std::string id) {
    this->id = id;
}

std::string Activo::getNombre() {
    return nombre;
}

void Activo::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Activo::getDescripcion() {
    return descripcion;
}

void Activo::setDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

bool Activo::getDisponibilidad() {
    return disponibilidad;
}

void Activo::setDisponibilidad(bool disponibilidad) {
    this->disponibilidad = disponibilidad;
}

int Activo::getDiasDisponibles() {
    return diasDisponibles;
}

void Activo::setDiasDisponibles(int diasDisponibles) {
    this->diasDisponibles = diasDisponibles;
}


