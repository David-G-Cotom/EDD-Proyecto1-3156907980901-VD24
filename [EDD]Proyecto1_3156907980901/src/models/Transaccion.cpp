//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/models/Transaccion.h"

#include "../../includes/utils/Utils.h"

Transaccion::Transaccion(Activo *activo, std::string usuario, std::string departamentoUsuario, std::string empresaUsuario, std::string fecha, int dias) {
    this->id = Utils::generarIDAlfanumerico();
    this->activo = activo;
    this->usuario = usuario;
    this->departamentoUsuario = departamentoUsuario;
    this->empresaUsuario = empresaUsuario;
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

std::string Transaccion::getDepartamentoUsuario() {
    return this->departamentoUsuario;
}

void Transaccion::setDepartamentoUsuario(std::string nombreDepartamento) {
    this->departamentoUsuario = nombreDepartamento;
}

std::string Transaccion::getEmpresaUsuario() {
    return this->empresaUsuario;
}

void Transaccion::setEmpresaUsuario(std::string nombreEmpresa) {
    this->empresaUsuario = nombreEmpresa;
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




