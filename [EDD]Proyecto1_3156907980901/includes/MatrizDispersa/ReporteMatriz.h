//
// Created by Carlos Cotom on 10/12/2024.
//

#ifndef REPORTEMATRIZ_H
#define REPORTEMATRIZ_H
#include "MatrizDispersa.h"


class ReporteMatriz {

private:
    MatrizDispersa *matrizDispersa;

public:
    ReporteMatriz(MatrizDispersa *matrizDispersa);

    void reporteActivosEmpresa(std::string empresa);
    void reporteActivosDepartamento(std::string departamento);

    void reporteMatrizDispersa();

};



#endif //REPORTEMATRIZ_H
