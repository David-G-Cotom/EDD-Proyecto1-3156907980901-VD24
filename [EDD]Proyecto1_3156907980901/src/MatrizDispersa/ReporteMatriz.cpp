//
// Created by Carlos Cotom on 10/12/2024.
//

#include "../../includes/MatrizDispersa/ReporteMatriz.h"
#include <fstream>

ReporteMatriz::ReporteMatriz(MatrizDispersa *matrizDispersa) {
    this->matrizDispersa = matrizDispersa;
}

void ReporteMatriz::reporteActivosEmpresa(std::string empresa) {
    std::string dot = "digraph{\nrankdir = TB;\nlabel = \"Activos de una Empresa\";\nlabelloc = t;\nnode[style = filled];\nnode[shape=box color=red fillcolor=\"#8080F0\"];\n" + empresa + ";\n";
    NodoMatriz *nodoEmpresa = this->matrizDispersa->existeEmpresa(empresa);
    NodoMatriz *aux = nodoEmpresa->getSiguiente();
    NodoMatriz *aux2 = nullptr;
    while (aux != nullptr) {
        aux2 = aux;
        while (aux2 != nullptr) {
            dot += "node[shape=box color=transparent fillcolor=\"#808080\"];\n" + aux2->getUsuario()->getUsername() + ";\nnode[shape = circle];\n";
            dot += aux2->getUsuario()->getReporteArbol()->reporteActivosCabeceras(aux2->getUsuario()->getArbol()->getRaiz(), dot);
            aux2 = aux2->getAtras();
        }
        aux = aux->getSiguiente();
    }
    dot += "\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteActivosEmpresa.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteActivosEmpresa.txt -o ../Graficas/ReporteActivosEmpresa.png");
}

void ReporteMatriz::reporteActivosDepartamento(std::string departamento) {
    std::string dot = "digraph{\nrankdir = TB;\nlabel = \"Activos de un Departamento\";\nlabelloc = t;\nnode[style = filled];\nnode[shape=box color=red fillcolor=\"#8080F0\"];\n" + departamento + ";\n";
    NodoMatriz *nodoDepartemento = this->matrizDispersa->existeDepartamento(departamento);
    NodoMatriz *aux = nodoDepartemento->getAbajo();
    NodoMatriz *aux2 = nullptr;
    while (aux != nullptr) {
        aux2 = aux;
        while (aux2 != nullptr) {
            dot += "node[shape=box color=transparent fillcolor=\"#808080\"];\n" + aux2->getUsuario()->getUsername() + ";\n node[shape = circle];\n";
            dot += aux2->getUsuario()->getReporteArbol()->reporteActivosCabeceras(aux2->getUsuario()->getArbol()->getRaiz(), dot);
            aux2 = aux2->getAtras();
        }
        aux = aux->getAbajo();
    }
    dot += "\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteActivosDepartamento.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteActivosDepartamento.txt -o ../Graficas/ReporteActivosDepartamento.png");
}

void ReporteMatriz::reporteMatrizDispersa() {
    std::string dot = "digraph G {\n\tbgcolor=\"#1a1a1a\";\n\tfontcolor=white;\n\tlabel=\"Matriz Dispersa\";\n\t"
                    "labelloc=t;\n\tnodesep=0.5;\n\tnode [shape=box width=1.2 style=filled fillcolor=\"#313638\" fontcolor=white "
                    "color=transparent];\n\tedge [fontcolor=white color=\"#ff5400\"];\n\n\tn0 [shape=point style=invis group=0];\n\n\t";
    if (this->matrizDispersa->isVacia()) {
        dot += "}";
        std::ofstream file;
        file.open("../Graficas/ReporteMatrizDispersa.txt");
        if (file.is_open()) {
            file << dot;
            file.close();
        }
        system("dot -Tpng ../Graficas/ReporteMatrizDispersa.txt -o ../Graficas/ReporteMatrizDispersa.png");
        return;
    }
    NodoMatriz *departamento = this->matrizDispersa->getCabeceraHorizontal();
    NodoMatriz *usuarios;
    dot += "n0 -> n" + std::to_string(departamento->getId()) + " -> n0 [color=transparent];\n\t";
    std::string ranks = "{ rank=same; n0; ";
    while (departamento != nullptr) {
        dot += "n" + std::to_string(departamento->getId()) + "[label=\"" + departamento->getNombreCabecera() + "\" group=" + std::to_string(departamento->getGrupo()) + " ];\n\t";
        usuarios = departamento->getAbajo();
        dot += "n" + std::to_string(departamento->getId()) + " -> n" + std::to_string(usuarios->getId()) + " -> n" + std::to_string(departamento->getId()) + ";\n\t";
        while (usuarios != nullptr) {
            dot += "n" + std::to_string(usuarios->getId()) + " [label=\"" + usuarios->getUsuario()->getUsername() + "\" group=" + std::to_string(usuarios->getGrupo()) + " ];\n\t";
            if (usuarios->getAbajo() != nullptr) {
                dot += "n" + std::to_string(usuarios->getId()) + " -> n" + std::to_string(usuarios->getAbajo()->getId()) + " -> n" + std::to_string(usuarios->getId()) + ";\n\t";
            }
            usuarios = usuarios->getAbajo();
        }
        if (departamento->getSiguiente() != nullptr) {
            dot += "n" + std::to_string(departamento->getId()) + " -> n" + std::to_string(departamento->getSiguiente()->getId()) + " -> n" + std::to_string(departamento->getId()) + ";\n\t";
        }
        ranks += "n" + std::to_string(departamento->getId()) + "; ";
        departamento = departamento->getSiguiente();
    }
    ranks += "}\n\t";
    NodoMatriz *empresa = this->matrizDispersa->getCabeceraVertical();
    dot += "n0 -> n" + std::to_string(empresa->getId()) + " -> n0 [color=transparent]\n\t";
    while (empresa != nullptr) {
        ranks += "{rank=same; ";
        dot += "n" + std::to_string(empresa->getId()) + " [label=\"" + empresa->getNombreCabecera() + "\" group=" + std::to_string(empresa->getGrupo()) + " ];\n\t";
        ranks += "n" + std::to_string(empresa->getId()) + "; ";
        usuarios = empresa->getSiguiente();
        dot += "n" + std::to_string(empresa->getId()) + " -> n" + std::to_string(usuarios->getId()) + " -> n" + std::to_string(empresa->getId()) + ";\n\t";
        while (usuarios != nullptr) {
            dot += "n" + std::to_string(usuarios->getId()) + " [label=\"" + usuarios->getUsuario()->getUsername() + "\" group=" + std::to_string(usuarios->getGrupo()) + " ];\n\t";
            if (usuarios->getSiguiente() != nullptr) {
                dot += "n" + std::to_string(usuarios->getId()) + " -> n" + std::to_string(usuarios->getSiguiente()->getId()) + " -> n" + std::to_string(usuarios->getId()) + ";\n\t";
            }
            ranks += "n" + std::to_string(usuarios->getId()) + "; ";
            usuarios = usuarios->getSiguiente();
        }
        if (empresa->getAbajo() != nullptr) {
            dot += "n" + std::to_string(empresa->getId()) + " -> n" + std::to_string(empresa->getAbajo()->getId()) + " -> n" + std::to_string(empresa->getId()) + ";\n\t";
        }
        ranks += "}\n\t";
        empresa = empresa->getAbajo();
    }
    dot += ranks;
    dot += "\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteMatrizDispersa.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteMatrizDispersa.txt -o ../Graficas/ReporteMatrizDispersa.png");
}


