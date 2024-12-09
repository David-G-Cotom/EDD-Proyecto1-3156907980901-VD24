//
// Created by Carlos Cotom on 9/12/2024.
//

#include "../../includes/ListaCircularDoblementeEnlazada/ReporteLista.h"

#include <fstream>

ReporteLista::ReporteLista(ListaTransacciones *listaTransacciones) {
    this->listaTransacciones = listaTransacciones;
}

void ReporteLista::reporteActivosRentadosUsuario(std::string usuairo) {
    std::string dot = "digraph{\nrankdir=LR;\n node[shape = box];\n";
    dot = contenidoReporteActivosRentadosUsuario(dot, usuairo);
    dot += "}";

    std::ofstream file;
    file.open("../Graficas/ActivosRentados.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/ActivosRentados.txt -o ../Graficas/ActivosRentados.png");
}

std::string ReporteLista::contenidoReporteActivosRentadosUsuario(std::string dot, std::string usuario) {
    int contador = 0;
    if (!this->listaTransacciones->isVacia()) {
        NodoLista *aux = this->listaTransacciones->getInicio();
        do {
            if ((aux->getTransaccion()->getUsuario() == usuario) && (aux->getTransaccion()->getDias() != 0)) {
                contador++;
                dot += "activo" + std::to_string(contador) + "[label = <" + aux->getTransaccion()->getActivo()->getId() + "<br/>" + aux->getTransaccion()->getActivo()->getNombre() + ">]\n";
            }
            aux = aux->getSiguiente();
        } while (aux != this->listaTransacciones->getInicio());
        int contador2 = 0;
        do {
            if (aux->getTransaccion()->getUsuario() == usuario
                && aux->getTransaccion()->getDias() != 0
                && contador2 != contador-1) {
                contador2++;
                dot += "activo" + std::to_string(contador2) + "->activo" + std::to_string(contador2+1) + "\n";
            }
            aux = aux->getSiguiente();
        } while (aux != this->listaTransacciones->getInicio());
        dot += usuario + "\n";
    } else {
        dot += "vacia;\n" + usuario + "\n";
    }
    return dot;
}

void ReporteLista::reporteTransacciones() {
    std::string dot = "digraph{\nrankdir=LR;\n node[shape = box, color = red];\n";
    NodoLista *aux;
    if (this->listaTransacciones->getOrdenListaAscendente()) {
        aux = this->listaTransacciones->getInicio();
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n";
            dot += aux->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
            dot += aux->getTransaccion()->getActivo()->getNombre() + "\n" + aux->getTransaccion()->getUsuario() + "\"->\n";
            aux = aux->getSiguiente();
        } while (aux != this->listaTransacciones->getInicio());
        if (this->listaTransacciones->getInicio() != this->listaTransacciones->getFin()) {
            dot += "\"" + this->listaTransacciones->getInicio()->getTransaccion()->getId() + "\n";
            dot += this->listaTransacciones->getInicio()->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
            dot += this->listaTransacciones->getInicio()->getTransaccion()->getActivo()->getNombre() + "\n" + this->listaTransacciones->getInicio()->getTransaccion()->getUsuario() + "\"->\n";
        }
        aux = this->listaTransacciones->getFin();
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n";
            dot += aux->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
            dot += aux->getTransaccion()->getActivo()->getNombre() + "\n" + aux->getTransaccion()->getUsuario() + "\"->\n";
            aux = aux->getAnterior();
        } while (aux->getAnterior() != this->listaTransacciones->getFin());
    } else {
        aux = this->listaTransacciones->getFin();
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n";
            dot += aux->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
            dot += aux->getTransaccion()->getActivo()->getNombre() + "\n" + aux->getTransaccion()->getUsuario() + "\"->\n";
            aux = aux->getAnterior();
        } while (aux != this->listaTransacciones->getFin());
        if (this->listaTransacciones->getInicio() != this->listaTransacciones->getFin()) {
            dot += "\"" + this->listaTransacciones->getFin()->getTransaccion()->getId() + "\n";
            dot += this->listaTransacciones->getFin()->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
            dot += this->listaTransacciones->getFin()->getTransaccion()->getActivo()->getNombre() + "\n" + this->listaTransacciones->getInicio()->getTransaccion()->getUsuario() + "\"->\n";
        }
        aux = this->listaTransacciones->getInicio();
        do {
            dot += "\"" + aux->getTransaccion()->getId() + "\n";
            dot += aux->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
            dot += aux->getTransaccion()->getActivo()->getNombre() + "\n" + aux->getTransaccion()->getUsuario() + "\"->\n";
            aux = aux->getSiguiente();
        } while (aux->getSiguiente() != this->listaTransacciones->getInicio());
    }
    dot += "\"" + aux->getTransaccion()->getId() + "\n";
    dot += aux->getTransaccion()->getDias()!=0 ? "RENTADO\n" : "DEVUELTO\n";
    dot += aux->getTransaccion()->getActivo()->getNombre() + "\n" + aux->getTransaccion()->getUsuario() + "\"";
    dot += ";\n}";
    std::ofstream file;
    file.open("../Graficas/ReporteTransacciones.txt");
    if (file.is_open()) {
        file << dot;
        file.close();
    }
    system("dot -Tpng ../Graficas/ReporteTransacciones.txt -o ../Graficas/ReporteTransacciones.png");
}




