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

