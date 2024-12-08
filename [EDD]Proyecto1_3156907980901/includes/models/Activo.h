//
// Created by Carlos Cotom on 7/12/2024.
//

#ifndef ACTIVO_H
#define ACTIVO_H
#include <string>


class Activo {

private:
    std::string id;
    std::string nombre;
    std::string descripcion;
    bool disponibilidad;

public:
    Activo(std::string nombre, std::string descripcion);

    std::string getId();
    void setId(std::string id);

    std::string getNombre();
    void setNombre(std::string nombre);

    std::string getDescripcion();
    void setDescripcion(std::string descripcion);

    bool getDisponibilidad();
    void setDisponibilidad(bool disponibilidad);

};



#endif //ACTIVO_H
