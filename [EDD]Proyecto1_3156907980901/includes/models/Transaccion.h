//
// Created by Carlos Cotom on 8/12/2024.
//

#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <string>
#include "Activo.h"


class Transaccion {

private:
    std::string id;
    Activo *activo;
    std::string usuario;
    std::string departamentoUsuario;
    std::string empresaUsuario;
    std::string fecha;
    int dias;

public:
    Transaccion(Activo *activo, std::string usuario, std::string departamentoUsuario, std::string empresaUsuario, std::string fecha, int dias);

    std::string getId();
    void setId(std::string id);
    Activo *getActivo();
    void setActivo(Activo *activo);
    std::string getUsuario();
    void setUsuario(std::string usuario);
    std::string getDepartamentoUsuario();
    void setDepartamentoUsuario(std::string nombreDepartamento);
    std::string getEmpresaUsuario();
    void setEmpresaUsuario(std::string nombreEmpresa);
    std::string getFecha();
    void setFecha(std::string fecha);
    int getDias();
    void setDias(int dias);

};



#endif //TRANSACCION_H
