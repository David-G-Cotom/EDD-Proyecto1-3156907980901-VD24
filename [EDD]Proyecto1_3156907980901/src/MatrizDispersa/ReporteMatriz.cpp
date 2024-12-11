//
// Created by Carlos Cotom on 10/12/2024.
//

#include "../../includes/MatrizDispersa/ReporteMatriz.h"

#include <fstream>

ReporteMatriz::ReporteMatriz(MatrizDispersa *matrizDispersa) {
    this->matrizDispersa = matrizDispersa;
}

void ReporteMatriz::reporteActivosEmpresa(std::string empresa) {
    std::string dot = "digraph{\nrankdir = TB;node[shape = box, color = red]\n" + empresa + "\n";
    NodoMatriz *nodoEmpresa = this->matrizDispersa->existeEmpresa(empresa);
    NodoMatriz *aux = nodoEmpresa->getSiguiente();
    NodoMatriz *aux2;
    while (aux != nullptr) {
        aux2 = aux;
        while (aux2 != nullptr) {
            dot += "node[shape = box];\n" + aux2->getUsuario()->getUsername() + ";\n node[shape = circle];\n";

            //RECOGER LOS ACTIVOS

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
    std::string dot = "digraph{\nrankdir = TB\nnode[shape = box, color = red]\n" + departamento + "\n";
    NodoMatriz *nodoDepartemento = this->matrizDispersa->existeDepartamento(departamento);
    NodoMatriz *aux = nodoDepartemento->getAbajo();
    NodoMatriz *aux2;
    while (aux != nullptr) {
        aux2 = aux;
        while (aux2 != nullptr) {
            dot += "node[shape = box];\n" + aux2->getUsuario()->getUsername() + ";\n node[shape = circle];\n";

            //RECOGER LOS ACTIVOS

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

    /*NodoMatriz *auxEmpresas = this->matrizDispersa->getCabeceraVertical();
    NodoMatriz *aux = nullptr;
    std::string dot = "digraph G{\n{node[shape = box, group = a];\n";
    while (auxEmpresas != nullptr) {
        dot += "\"" + auxEmpresas->getNombreCabecera() + "\"->";
        aux = auxEmpresas;
        auxEmpresas = auxEmpresas->getAbajo();
    }
    auxEmpresas = aux->getArriba();
    while (auxEmpresas != nullptr) {
        if (auxEmpresas != this->matrizDispersa->getCabeceraVertical()) {
            dot += "\"" + auxEmpresas->getNombreCabecera() + "\"->";
        } else {
            dot += "\"" + auxEmpresas->getNombreCabecera() + "\"\n}";
            break;
        }
        auxEmpresas = auxEmpresas->getArriba();
    }
    dot += "\n{\nrank=same;\nnode[shape = box, group = true];\n";

    NodoMatriz *auxDepartamentos = this->matrizDispersa->getCabeceraHorizontal();
    aux = nullptr;
    while (auxDepartamentos != nullptr) {
        dot += "\"" + auxDepartamentos->getNombreCabecera() + "\"->";
        aux = auxDepartamentos;
        auxDepartamentos = auxDepartamentos->getSiguiente();
    }
    auxDepartamentos = aux->getPrevio();
    while (auxDepartamentos != nullptr) {
        if (auxDepartamentos != this->matrizDispersa->getCabeceraHorizontal()) {
            dot += "\"" + auxDepartamentos->getNombreCabecera() + "\"->";
        } else {
            dot += "\"" + auxDepartamentos->getNombreCabecera() + "\"\n}";
            break;
        }
        auxDepartamentos = auxDepartamentos->getPrevio();
    }
    dot += "\nnode[shape = box, group = true];\n";

    NodoMatriz *auxEmpresas2 = this->matrizDispersa->getCabeceraVertical();
    auxEmpresas = auxEmpresas2;
    while (auxEmpresas != nullptr) {
        if (auxEmpresas != nullptr) {
            dot += "{rank=msame;";
        } else {
            dot += "{rank=max;";
        }
        while (auxEmpresas != nullptr) {
            if (auxEmpresas->getUsuario() != nullptr) {
                dot += "\"" + auxEmpresas->getUsuario()->getUsername() + "\"->";
            } else {
                dot += "\"" + auxEmpresas->getNombreCabecera() + "\"->";
            }
            aux = auxEmpresas;
            auxEmpresas = auxEmpresas->getSiguiente();
        }
        auxEmpresas = aux->getPrevio();
        while (auxEmpresas != nullptr) {
            if (auxEmpresas != auxEmpresas2) {
                if (auxEmpresas->getUsuario() != nullptr) {
                    dot += "\"" + auxEmpresas->getUsuario()->getUsername() + "\"->";
                } else {
                    dot += "\"" + auxEmpresas->getNombreCabecera() + "\"->";
                }
            } else {
                dot += "\"" + auxEmpresas->getNombreCabecera() + "\"}\n";
                break;
            }
            auxEmpresas = auxEmpresas->getPrevio();
        }
        auxEmpresas = auxEmpresas->getAbajo();
        auxEmpresas2 = auxEmpresas2->getAbajo();
    }

    NodoMatriz *auxDepartamentos2 = this->matrizDispersa->getCabeceraHorizontal();
    auxDepartamentos = auxDepartamentos2;
    while (auxDepartamentos != nullptr) {
        while (auxDepartamentos != nullptr) {
            if (auxDepartamentos->getUsuario() != nullptr) {
                dot += "\"" + auxDepartamentos->getUsuario()->getUsername() + "\"->";
            } else {
                dot += "\"" + auxDepartamentos->getNombreCabecera() + "\"->";
            }
            aux = auxDepartamentos;
            auxDepartamentos = auxDepartamentos->getAbajo();
        }
        auxDepartamentos = aux->getArriba();
        while (auxDepartamentos != nullptr) {
            if (auxDepartamentos != auxDepartamentos2) {
                if (auxDepartamentos->getUsuario() != nullptr) {
                    dot += "\"" + auxDepartamentos->getUsuario()->getUsername() + "\"->";
                } else {
                    dot += "\"" + auxDepartamentos->getNombreCabecera() + "\"->";
                }
            } else {
                dot += "\"" + auxDepartamentos->getNombreCabecera() + "\"\n";
                break;
            }
            auxDepartamentos = auxDepartamentos->getArriba();
        }
        auxDepartamentos = auxDepartamentos->getSiguiente();
        auxDepartamentos2 = auxDepartamentos2->getSiguiente();
    }
    dot += "\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteMatrizDispersa.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteMatrizDispersa.txt -o ../Graficas/ReporteMatrizDispersa.png");*/
}




