//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/utils/Utils.h"


std::string Utils::generarIDAlfanumerico() {
    const int longitudID = 15;
    const std::string alfanumericos = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string ID;

    for (int i = 0; i < longitudID; i++) {
        ID += alfanumericos[rand()%(alfanumericos.size()-1)];
    }
    return ID;
}

bool Utils::isEquals(std::string cadena1, std::string cadena2) {
    int longitud1 = cadena1.length();
    int longitud2 = cadena2.length();

    if (longitud1 != longitud2) return false;

    for (int i = 0; i < longitud1; i++) {
        if (std::tolower(static_cast<unsigned char>(cadena1[i]))
            != std::tolower(static_cast<unsigned char>(cadena2[i]))) {
            return false;
        }
    }
    return true;
}


