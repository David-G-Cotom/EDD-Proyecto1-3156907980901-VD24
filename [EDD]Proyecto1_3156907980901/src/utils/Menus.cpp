//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/utils/Menus.h"

#include "../../includes/ListaCircularDoblementeEnlazada/ListaTransacciones.h"
#include "../../includes/ListaCircularDoblementeEnlazada/ReporteLista.h"
#include "../../includes/MatrizDispersa/MatrizDispersa.h"

const std::string USERNAME_ADMIN = "admin";
const std::string PASSWORD_ADMIN = "admin";

MatrizDispersa *matrizDispersa = new MatrizDispersa();

ListaTransacciones *listaTransacciones = new ListaTransacciones();
ReporteLista *reporteLista = new ReporteLista(listaTransacciones);

void Menus::menuPrincipal() {
    char opcionElegida;
    do {
        std::cout << "%%%%%%%%%%%%%%%%%%%% Bienvenido a \"Renta de Activos\" %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << "%%%%%%%%%%%%%%%%%%%%          Menu Principal           %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << "%%%%%%%%%%%%%%%%%%%%          1.Ingresar               %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << "%%%%%%%%%%%%%%%%%%%%          2.Salir                  %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcionElegida;
        switch (opcionElegida) {
            case '1':
                login();
                break;
            case '2':
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
        }
    } while (opcionElegida != '2');
}

void Menus::login() {
    std::cout << "%%%%%%%%%%%%%%%%%%%% Login %%%%%%%%%%%%%%%%%%%%" <<std::endl;

    std::string username;
    std::string password;
    std::cout << "... Ingrese su Usuario ..." <<std::endl;
    std::cin >> username;
    std::cout << "... Ingrese su Password ..." <<std::endl;
    std::cin >> password;

    if (username == "admin" && password == "admin") {
        menuAdministrador();
    } else {
        std::string departamento;
        std::string empresa;
        std::cout << "... Ingrese su Departamento ..." <<std::endl;
        std::cin >> departamento;
        std::cout << "... Ingrese su Empresa ..." <<std::endl;
        std::cin >> empresa;

        NodoMatriz *aux = matrizDispersa->existeNodoInterseccion(departamento, empresa);
        if (aux == nullptr) {
            std::cout << "Error!!!. El Usuario Ingresado NO esta Registrado" << std::endl;
        } else {
            do {
                if (aux->getUsuario()->getUsername() == username && aux->getUsuario()->getPassword() == password) {
                    NodoMatriz *usuarioLogeado = aux;
                    menuUsuario(usuarioLogeado);
                    return;
                }
                aux = aux->getAtras();
            } while (aux != nullptr);
            std::cout << "Error!!!. El Usuario Ingresado NO esta Registrado" << std::endl;
        }
    }
}

void Menus::menuAdministrador() {
    char opcionElegida;
    do {
        std::cout << "%%%%%%%%%%%%%%%%%%%% Menu Administrador %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << "%% 1. Registrar Usuario" <<std::endl;
        std::cout << "%% 2. Reporte Matriz Dispersa" <<std::endl;
        std::cout << "%% 3. Reporte Activos Disponibles de un Departamento" <<std::endl;
        std::cout << "%% 4. Reporte Activos Disponibles de una Empresa" <<std::endl;
        std::cout << "%% 5. Reporte Transacciones" <<std::endl;
        std::cout << "%% 6. Reporte Activos de un Usuario" <<std::endl;
        std::cout << "%% 7. Activos Rentados por un Usuario" <<std::endl;
        std::cout << "%% 8. Ordenar Transacciones" <<std::endl;
        std::cout << "%% 9. Salir" <<std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcionElegida;

        switch (opcionElegida) {
            case '1': {
                registroUsuario();
                break;
            }
            case '2': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Reporte Matriz Dispersa %%%%%%%%%%%%%%%%%%%%" <<std::endl;

                //Crear el Reporte

                break;
            }
            case '3': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Activos de un Departamento %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << "Ingrese el Departamento: " <<std::endl;
                std::string departamento;
                std::cin >> departamento;

                //Crear Reporte

                break;
            }
            case '4': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Activos de una Empresa %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << "Ingrese la Empresa: " <<std::endl;
                std::string empresa;
                std::cin >> empresa;

                //Crear Reporte

                break;
            }
            case '5': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Reporte Transacciones %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                reporteLista->reporteTransacciones();
                std::cout << "Reporte Generado!!!" <<std::endl;
                break;
            }
            case '6': {
                reporteActivosUsuario();
                break;
            }
            case '7': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Activos Rentados por Usuario %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << "... Ingresar UserName del Usuario...:" <<std::endl;
                std::string userName;
                std::cin >> userName;
                reporteLista->reporteActivosRentadosUsuario(userName);
                std::cout << "Reportee Generado!!!" <<std::endl;
                break;
            }
            case '8': {
                char opcion;
                do {
                    std::cout << "%%%%%%%%%%%%%%%%%%%% Ordenar Transacciones %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                    std::cout << "%% 1. Ordenar Ascendentemente" <<std::endl;
                    std::cout << "%% 2. Ordenar Descendentemente" <<std::endl;
                    std::cout << "%% 3. Cancelar" <<std::endl;
                    std::cout << "Opcion: ";
                    std::cin >> opcion;
                    switch (opcion) {
                        case '1': {
                            listaTransacciones->setOrdenListaAscendente(true);
                            std::cout << "Orden Ascendente Establecido!!!" <<std::endl;
                        }
                        case '2': {
                            listaTransacciones->setOrdenListaAscendente(false);
                            std::cout << "Orden Descendente Establecido!!!" <<std::endl;
                        }
                        case '3': {
                            std::cout << "Ordenamiento Cancelado" <<std::endl;
                        }
                        default: {
                            std::cout << "Opcion ingresada invalida. Intente otra vez" << std::endl;
                            break;
                        }
                    }
                } while (opcion != '3');
                break;
            }
            case '9': {
                std::cout << "Saliendo..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
            }
        }
    } while (opcionElegida != '9');
}

void Menus::registroUsuario() {
    std::cout << "%%%%%%%%%%%%%%%%%%%% Registro Usuario %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    std::cout << "... Ingresar UserName Usuario...:" <<std::endl;
    std::string userName;
    std::cin >> userName;

    std::cout << "... Ingresar Password...:" <<std::endl;
    std::string password;
    std::cin >> password;

    std::cout << "... Ingresar Departamento...:" <<std::endl;
    std::string departamento;
    std::cin >> departamento;

    std::cout << "... Ingresar Empresa...:" <<std::endl;
    std::string empresa;
    std::cin >> empresa;

    matrizDispersa->insretarUsuario(new Usuario("", userName, password), departamento, empresa);
}

void Menus::reporteActivosUsuario() {
    std::cout << "%%%%%%%%%%%%%%%%%%%% Activos de Usuario %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    std::cout << "... Ingresar UserName del Usuario...:" <<std::endl;
    std::string userName;
    std::cin >> userName;

    std::cout << "... Ingresar el Departamento...:" <<std::endl;
    std::string departamento;
    std::cin >> departamento;

    std::cout << "... Ingresar la Empresa...:" <<std::endl;
    std::string empresa;
    std::cin >> empresa;

    NodoMatriz *aux = matrizDispersa->existeNodoInterseccion(departamento, empresa);
    if (aux != nullptr) {
        do {
            if (aux->getUsuario()->getUsername() == userName) {

                //Recibir los Activos  por AVL

                break;
            }
            aux = aux->getAtras();
        } while (aux != nullptr);

        if (aux == nullptr) std::cout << "No se Encontro al Usuario con las Credenciales Ingresadas" << std::endl;

    } else {
        std::cout << "No se Encontro al Usuario con las Credenciales Ingresadas" << std::endl;
    }
}

void Menus::menuUsuario(NodoMatriz *usuarioLogeado) {
    char opcionElegida;
    do {
        std::cout << "%%%%%%%%%%%%%%%%%%%% Menu de Usuario: " <<usuarioLogeado->getUsuario()->getNombre() <<" %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << "%% 1. Agregar Activo" <<std::endl;
        std::cout << "%% 2. Eliminar Activo" <<std::endl;
        std::cout << "%% 3. Modificar Activo" <<std::endl;
        std::cout << "%% 4. Rentar Activo" <<std::endl;
        std::cout << "%% 5. Activos Rentados" <<std::endl;
        std::cout << "%% 6. Mis Activos Rentados" <<std::endl;
        std::cout << "%% 7. Cerrar Sesion" <<std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcionElegida;

        switch (opcionElegida) {
            case '1': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Agregar Activo %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << "...Ingrese Nombre...: " <<std::endl;
                std::string nombre;
                std::cin >> nombre;

                std::cout << "...Ingrese Descripcion...: " <<std::endl;
                std::string descripcion;
                std::cin >> descripcion;

                //Insertar el Activo en el AVL del Usuario

                break;
            }
            case '2': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Eliminar Activo %%%%%%%%%%%%%%%%%%%%" <<std::endl;

                //Verificar si el Usuario tiene Activos

                std::cout << "...Ingresar ID de Activo a Eliminar...";
                std::string idActivo;
                std::cin >> idActivo;

                //Eliminar el Activo

                std::cout << "Activo Eliminado Exitosamente!!!";
                break;
            }
            case '3': {
                modificarActivo();
                break;
            }
            case '4': {
                rentaActivo(usuarioLogeado);
                break;
            }
            case '5': {
                activosRentados(usuarioLogeado);
                break;
            }
            case '6': {
                std::cout << "%%%%%%%%%%%%%%%%%%%% Mis Activos Rentados %%%%%%%%%%%%%%%%%%%%" <<std::endl;

                //Verificar si el Usuario tiene Activos Rentados

                char valorSalida;
                do {
                    std::cout << "...Ingresar 1 para Regresar al Menu...";
                    std::cin >> valorSalida;
                } while (valorSalida != '1');
                break;
            }
            case '7': {
                usuarioLogeado = nullptr;
                std::cout << "Saliendo..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
            }
        }
    } while (opcionElegida != '7');
}

void Menus::modificarActivo() {
    std::cout << "%%%%%%%%%%%%%%%%%%%% Modificar Activo %%%%%%%%%%%%%%%%%%%%" <<std::endl;

    //Verificar si el Usuario tiene Activos

    std::cout << "...Ingresar ID de Activo a Modificar...";
    std::string idActivo;
    std::cin >> idActivo;

    std::cout << "...Ingresar Descripcion Nueva...";
    std::string nuevaDescripcion;
    std::cin >> nuevaDescripcion;

    //Realizar la Modificacion Siempre Verificando que el ID del Activo "Seleccionado sea Valido"
}

void Menus::rentaActivo(NodoMatriz *usuarioLogeado) {
    std::cout << "%%%%%%%%%%%%%%%%%%%% Catalogo Activos %%%%%%%%%%%%%%%%%%%%" <<std::endl;

    //Mostrar los Activos que se Pueden Rentar

    std::cout << "%% 1. Rentar Activo" <<std::endl;
    std::cout << "%% 2. Regresar a Menu" <<std::endl;
    bool opcionValida = false;
    do {
        char opcionElegida;
        std::cout << "...Ingresar Opcion...: ";
        std::cin >> opcionElegida;

        switch (opcionElegida) {
            case '1': {
                std::cout << "Ingresar ID de Activo a Rentar...";
                std::string idActivo;
                std::cin >> idActivo;

                //Rentar Activo Verificando la Validez del ID

                opcionValida = true;
                break;
            }
            case '2': {
                opcionValida = true;
                break;
            }
            default: {
                std::cout << "Opcion ingresada invalida. Intente otra vez" << std::endl;
                opcionValida = false;
            }
        }
    } while (!opcionValida);
}

void Menus::activosRentados(NodoMatriz *usuarioLogeado) {
    std::cout << "%%%%%%%%%%%%%%%%%%%% Activos Rentados %%%%%%%%%%%%%%%%%%%%" <<std::endl;

    //Mostrar los Activos que estan Rentados

    std::cout << "%% 1. Registrar Devolucion" <<std::endl;
    std::cout << "%% 2. Regresar a Menu" <<std::endl;
    bool opcionValida = false;
    do {
        char opcionElegida;
        std::cout << "...Ingresar Opcion...: ";
        std::cin >> opcionElegida;

        switch (opcionElegida) {
            case '1': {
                std::cout << "Ingresar ID de Activo a Devolver...";
                std::string idActivo;
                std::cin >> idActivo;

                //Devolver Activo Verificando la Validez del ID

                opcionValida = true;
                break;
            }
            case '2': {
                opcionValida = true;
                break;
            }
            default: {
                std::cout << "Opcion ingresada invalida. Intente otra vez" << std::endl;
                opcionValida = false;
            }
        }
    } while (!opcionValida);
}


