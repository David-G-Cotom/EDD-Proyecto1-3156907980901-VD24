//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>

#include "../ArbolAVL/ArbolAVL.h"
#include "../ArbolAVL/ReporteArbolAVL.h"


class Usuario {

private:
    std::string nombre;
    std::string username;
    std::string password;
    ArbolAVL *arbol;
    ReporteArbolAVL *reporte;

public:
    Usuario(std::string nombre, std::string username, std::string password);

    std::string getNombre();
    void setNombre(std::string nombre);
    std::string getUsername();
    void setUsername(std::string username);
    std::string getPassword();
    void setPassword(std::string password);
    ArbolAVL *getArbol();
    void setArbol(ArbolAVL *arbol);
    ReporteArbolAVL *getReporteArbol();
    void setReporte(ReporteArbolAVL *reporte);

};



#endif //USUARIO_H
