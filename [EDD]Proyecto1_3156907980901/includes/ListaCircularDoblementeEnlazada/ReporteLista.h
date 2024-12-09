//
// Created by Carlos Cotom on 9/12/2024.
//

#ifndef REPORTELISTA_H
#define REPORTELISTA_H
#include "ListaTransacciones.h"


class ReporteLista {

private:
    ListaTransacciones *listaTransacciones;

public:
    ReporteLista(ListaTransacciones *listaTransacciones);

    void reporteActivosRentadosUsuario(std::string usuairo);
    std::string contenidoReporteActivosRentadosUsuario(std::string dot, std::string usuario);

    void reporteTransacciones();

};



#endif //REPORTELISTA_H
