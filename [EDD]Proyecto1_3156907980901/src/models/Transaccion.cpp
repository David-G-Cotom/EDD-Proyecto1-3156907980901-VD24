//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/models/Transaccion.h"

Transaccion::Transaccion(Activo *activo, std::string usuario, std::string nombreDepartamento, std::string nombreEmpresa, std::string fecha, int dias) {
    this->activo = activo;
    this->usuario = usuario;
    this->nombreDepartamento = nombreDepartamento;
    this->nombreEmpresa = nombreEmpresa;
    this->fecha = fecha;
    this->dias = dias;
}

std::string Transaccion::getId() {
    return this->id;
}

void Transaccion::setId(std::string id) {
    this->id = id;
}

Activo *Transaccion::getActivo() {
    return this->activo;
}

void Transaccion::setActivo(Activo *activo) {
    this->activo = activo;
}

std::string Transaccion::getUsuario() {
    return this->usuario;
}

void Transaccion::setUsuario(std::string usuario) {
    this->usuario = usuario;
}

std::string Transaccion::getNombreDepartamento() {
    return this->nombreDepartamento;
}

void Transaccion::setNombreDepartamento(std::string nombreDepartamento) {
    this->nombreDepartamento = nombreDepartamento;
}

std::string Transaccion::getNombreEmpresa() {
    return this->nombreEmpresa;
}

void Transaccion::setNombreEmpresa(std::string nombreEmpresa) {
    this->nombreEmpresa = nombreEmpresa;
}

std::string Transaccion::getFecha() {
    return this->fecha;
}

void Transaccion::setFecha(std::string fecha) {
    this->fecha = fecha;
}

int Transaccion::getDias() {
    return this->dias;
}

void Transaccion::setDias(int dias) {
    this->dias = dias;
}




