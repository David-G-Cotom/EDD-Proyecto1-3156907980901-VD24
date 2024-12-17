//
// Created by Carlos Cotom on 12/12/2024.
//

#include "../../includes/ArbolAVL/ReporteArbolAVL.h"
#include <fstream>

ReporteArbolAVL::ReporteArbolAVL(ArbolAVL *arbolAVL) {
    this->arbolAVL = arbolAVL;
}

std::string ReporteArbolAVL::recorrerActivosPreOrden(NodoArbol *nodo, std::string dot) {
    std::string dotAux;
    if (nodo != nullptr && nodo->getActivo()->getDisponibilidad()) {
        dotAux += "\"" + nodo->getActivo()->getId() + "\"[label=<" + nodo->getActivo()->getId() + "<br/>" + nodo->getActivo()->getNombre() + "> fillcolor=\"#8080F0\"];\n";
        if (nodo->getHijoIzquierdo() != nullptr) {
            dotAux += recorrerActivosPreOrden(nodo->getHijoIzquierdo(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoIzquierdo()->getActivo()->getId() + "\";\n";
        }
        if (nodo->getHijoDerecho() != nullptr) {
            dotAux += recorrerActivosPreOrden(nodo->getHijoDerecho(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoDerecho()->getActivo()->getId() + "\";\n";
        }
    }
    if (nodo != nullptr && !nodo->getActivo()->getDisponibilidad()) {
        dotAux += nodo->getActivo()->getId() + "\"[label=<\"" + nodo->getActivo()->getId() + "\"<br/>" + nodo->getActivo()->getNombre() + "> fillcolor=\"#F08080\"];\n";
        if (nodo->getHijoIzquierdo() != nullptr) {
            dotAux += recorrerActivosPreOrden(nodo->getHijoIzquierdo(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoIzquierdo()->getActivo()->getId() + "\";\n";
        }
        if (nodo->getHijoDerecho() != nullptr) {
            dotAux += recorrerActivosPreOrden(nodo->getHijoDerecho(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoDerecho()->getActivo()->getId() + "\";\n";
        }
    }
    return dotAux;
}

void ReporteArbolAVL::reporteActivosUsuario(NodoArbol *nodo, std::string username) {
    std::string dot = "digraph{\nrankdir = TB;\nlabel = \"Activos de un Usuario\";\nlabelloc = t;\nnode[color=transparent style=filled];\nnode[shape = box]\n" + username + "\nnode[shape = circle]; \n";
    dot += recorrerActivosPreOrden(nodo, dot) + "\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteActivosUsuario.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteActivosUsuario.txt -o ../Graficas/ReporteActivosUsuario.png");
    std::cout << ">> Reporte Generado!!!" << std::endl;
}

std::string ReporteArbolAVL::reporteActivosCabeceras(NodoArbol *nodo, std::string dot) {
    std::string dotAux;
    if (nodo != nullptr && nodo->getActivo()->getDisponibilidad()) {
        dotAux += "\"" + nodo->getActivo()->getId() + "\"[label=<" + nodo->getActivo()->getId() + "<br/>" + nodo->getActivo()->getNombre() + "> fillcolor=\"#8080F0\"];\n";
        if (nodo->getHijoIzquierdo() != nullptr) {
            dotAux += reporteActivosCabeceras(nodo->getHijoIzquierdo(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoIzquierdo()->getActivo()->getId() + "\";\n";
        }
        if (nodo->getHijoDerecho() != nullptr) {
            dotAux += reporteActivosCabeceras(nodo->getHijoDerecho(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoDerecho()->getActivo()->getId() + "\";\n";
        }
    }
    if (nodo != nullptr && !nodo->getActivo()->getDisponibilidad()) {
        dotAux += nodo->getActivo()->getId() + "\"[label=<\"" + nodo->getActivo()->getId() + "\"<br/>" + nodo->getActivo()->getNombre() + "> fillcolor=\"#F08080\"];\n";
        if (nodo->getHijoIzquierdo() != nullptr) {
            dotAux += recorrerActivosPreOrden(nodo->getHijoIzquierdo(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoIzquierdo()->getActivo()->getId() + "\";\n";
        }
        if (nodo->getHijoDerecho() != nullptr) {
            dotAux += recorrerActivosPreOrden(nodo->getHijoDerecho(), dotAux) + "\"" + nodo->getActivo()->getId() + "\" -> \"" + nodo->getHijoDerecho()->getActivo()->getId() + "\";\n";
        }
    }
    return dotAux;
}


