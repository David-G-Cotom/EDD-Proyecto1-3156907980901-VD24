cmake_minimum_required(VERSION 3.22)
project(_EDD_Proyecto1_3156907980901)

set(CMAKE_CXX_STANDARD 23)

add_executable(_EDD_Proyecto1_3156907980901 main.cpp
        includes/MatrizDispersa/NodoMatriz.h
        src/MatrizDispersa/NodoMatriz.cpp
        includes/MatrizDispersa/MatrizDispersa.h
        src/MatrizDispersa/MatrizDispersa.cpp
        includes/models/Activo.h
        src/models/Activo.cpp
        includes/models/Usuario.h
        src/models/Usuario.cpp
        includes/utils/Menus.h
        src/utils/Menus.cpp
        includes/utils/Utils.h
        src/utils/Utils.cpp
        includes/ListaCircularDoblementeEnlazada/ListaTransacciones.h
        src/ListaCircularDoblementeEnlazada/ListaTransacciones.cpp
        includes/ListaCircularDoblementeEnlazada/NodoLista.h
        src/ListaCircularDoblementeEnlazada/NodoLista.cpp
        includes/models/Transaccion.h
        src/models/Transaccion.cpp)
