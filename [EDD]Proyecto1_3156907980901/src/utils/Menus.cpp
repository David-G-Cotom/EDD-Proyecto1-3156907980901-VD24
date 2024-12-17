//
// Created by Carlos Cotom on 8/12/2024.
//

#include "../../includes/utils/Menus.h"
#include "../../includes/ListaCircularDoblementeEnlazada/ListaTransacciones.h"
#include "../../includes/ListaCircularDoblementeEnlazada/ReporteLista.h"
#include "../../includes/MatrizDispersa/MatrizDispersa.h"
#include "../../includes/MatrizDispersa/ReporteMatriz.h"
#include "../../includes/utils/Utils.h"

const std::string USERNAME_ADMIN = "admin";
const std::string PASSWORD_ADMIN = "admin";

MatrizDispersa *matrizDispersa = new MatrizDispersa();
ReporteMatriz *reporteMatriz = new ReporteMatriz(matrizDispersa);

ListaTransacciones *listaTransacciones = new ListaTransacciones();
ReporteLista *reporteLista = new ReporteLista(listaTransacciones);

void Menus::cargarDatos() {
    std::cout << "RECUPERANDO DATOS..." << std::endl;

    auto *usuario1 = new Usuario("Elian Estrada", "elian_estrada", "1234");
    matrizDispersa->insretarUsuario(usuario1, "guatemala", "igss");
    usuario1->getArbol()->insertar(new Activo("madera", "madera para albañil", 20));
    usuario1->getArbol()->insertar(new Activo("martillos", "martillos para madera", 10));
    usuario1->getArbol()->insertar(new Activo("caladora", "caladora para cortar maderas prefabricadas", 15));
    usuario1->getArbol()->insertar(new Activo("barreno", "barreno para concreto", 5));

    matrizDispersa->insretarUsuario(new Usuario("Juan Perez", "juanito", "4567"), "jutiapa", "max");
    matrizDispersa->insretarUsuario(new Usuario("Pedro Rodriguez", "pedrito", "48956"), "jalapa", "usac");

    auto *usuario4 = new Usuario("Maria Fernanda", "mafer", "54312");
    matrizDispersa->insretarUsuario(usuario4, "peten", "cinepolis");
    usuario4->getArbol()->insertar(new Activo("audifonos", "audifonos para grabaciones de estudio", 10));
    usuario4->getArbol()->insertar(new Activo("microfonos", "microfonos de todo tipo", 8));
    usuario4->getArbol()->insertar(new Activo("pedestales", "pedestales para microfonos grandes y pequeños", 12));
    usuario4->getArbol()->insertar(new Activo("atriles", "atriles para colocar ojas con gancho", 14));

    matrizDispersa->insretarUsuario(new Usuario("Juan Manuel", "juanma", "32897"), "guatemala", "usac");

    auto *usuario6 = new Usuario("Carlos Perez", "casimiro", "721896");
    matrizDispersa->insretarUsuario(usuario6, "guatemala", "max");
    usuario6->getArbol()->insertar(new Activo("balanza", "balanza con maximo de 25kg", 15));
    usuario6->getArbol()->insertar(new Activo("canastas", "canastas para frutas y verduras", 45));
    usuario6->getArbol()->insertar(new Activo("linternas", "linternas para alumbrar cuartos oscuros", 10));
    usuario6->getArbol()->insertar(new Activo("cargadores", "cargadores de telefonos tipo c", 5));
    usuario6->getArbol()->insertar(new Activo("cables", "cables de todo tipo", 10));
    usuario6->getArbol()->insertar(new Activo("lazos", "lazos para tender ropa", 20));

    auto *usuario7 = new Usuario("Fernando Mendez", "fuego03", "891346");
    matrizDispersa->insretarUsuario(usuario7, "jutiapa", "cinepolis");
    usuario7->getArbol()->insertar(new Activo("termos", "pequeños termos para bebidas calientes", 10));
    usuario7->getArbol()->insertar(new Activo("maletas", "maletas desde pequeñas a grandes", 15));
    usuario7->getArbol()->insertar(new Activo("peliculas", "todo tipo de peliculas de accion", 5));

    matrizDispersa->insretarUsuario(new Usuario("Alejandra Guzman", "azurdia", "780145"), "jutiapa", "usac");

    auto *usuario9 = new Usuario("Iraldo Martinez", "incrediboy", "201598");
    matrizDispersa->insretarUsuario(usuario9, "jutiapa", "max");
    usuario9->getArbol()->insertar(new Activo("casest", "casets con musica de todo tipo", 5));
    usuario9->getArbol()->insertar(new Activo("pantallas", "pantallas para proyección", 10));
    usuario9->getArbol()->insertar(new Activo("cañonera", "cañonera para proyeccion", 10));
    usuario9->getArbol()->insertar(new Activo("toldo", "toldo para eventos al exterior", 5));

    matrizDispersa->insretarUsuario(new Usuario("Antonio Lopez", "alcachofa", "20435"), "jalapa", "usac");
}

void Menus::menuPrincipal() {
    int opcionElegida;
    do {
        std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Bienvenido a \"Renta de Activos\" %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%%          Menu Principal           %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%%          1.Ingresar               %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << ">> %%%%%%%%%%%%%%%%%%%%          2.Salir                  %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        Utils::verificarEntradaNumerica(opcionElegida, ">> Opcion: ");
        switch (opcionElegida) {
            case 1:
                login();
                break;
            case 2:
                std::cout << ">> Saliendo..." << std::endl;
                break;
            default:
                std::cout << ">> Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
        }
    } while (opcionElegida != 2);
}

void Menus::login() {
    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Login %%%%%%%%%%%%%%%%%%%%" <<std::endl;

    std::string username;
    std::string password;
    std::cout << ">> ... Ingrese su Usuario ..." <<std::endl;
    std::getline(std::cin, username);
    std::cout << ">> ... Ingrese su Password ..." <<std::endl;
    std::getline(std::cin, password);

    if (Utils::isEquals(username, USERNAME_ADMIN) && Utils::isEquals(password, PASSWORD_ADMIN)) {
        menuAdministrador();
    } else {
        std::string departamento;
        std::string empresa;
        std::cout << ">> ... Ingrese su Departamento ..." <<std::endl;
        std::getline(std::cin, departamento);
        std::cout << ">> ... Ingrese su Empresa ..." <<std::endl;
        std::getline(std::cin, empresa);

        NodoMatriz *aux = matrizDispersa->existeNodoInterseccion(departamento, empresa);
        if (aux == nullptr) {
            std::cout << ">> Error!!!. El Usuario Ingresado NO esta Registrado" << std::endl;
        } else {
            do {
                if (Utils::isEquals(aux->getUsuario()->getUsername(), username) && Utils::isEquals(aux->getUsuario()->getPassword(), password)) {
                    NodoMatriz *usuarioLogeado = aux;
                    menuUsuario(usuarioLogeado);
                    return;
                }
                aux = aux->getAtras();
            } while (aux != nullptr);
            std::cout << ">> Error!!!. El Usuario Ingresado NO esta Registrado" << std::endl;
        }
    }
}

void Menus::menuAdministrador() {
    int opcionElegida;
    do {
        std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Menu Administrador %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << ">> %% 1. Registrar Usuario" <<std::endl;
        std::cout << ">> %% 2. Reporte Matriz Dispersa" <<std::endl;
        std::cout << ">> %% 3. Reporte Activos Disponibles de un Departamento" <<std::endl;
        std::cout << ">> %% 4. Reporte Activos Disponibles de una Empresa" <<std::endl;
        std::cout << ">> %% 5. Reporte Transacciones" <<std::endl;
        std::cout << ">> %% 6. Reporte Activos de un Usuario" <<std::endl;
        std::cout << ">> %% 7. Activos Rentados por un Usuario" <<std::endl;
        std::cout << ">> %% 8. Ordenar Transacciones" <<std::endl;
        std::cout << ">> %% 9. Salir" <<std::endl;
        Utils::verificarEntradaNumerica(opcionElegida, ">> Opcion: ");
        switch (opcionElegida) {
            case 1: {
                registroUsuario();
                break;
            }
            case 2: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Reporte Matriz Dispersa %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                reporteMatriz->reporteMatrizDispersa();
                std::cout << ">> Reporte Generado!!!" << std::endl;
                break;
            }
            case 3: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Activos de un Departamento %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << ">> Ingrese el Departamento: " <<std::endl;
                std::string departamento;
                std::cin >> departamento;
                reporteMatriz->reporteActivosDepartamento(departamento);
                std::cout << ">> Reporte Generado!!!" << std::endl;
                break;
            }
            case 4: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Activos de una Empresa %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << ">> Ingrese la Empresa: " <<std::endl;
                std::string empresa;
                std::cin >> empresa;
                reporteMatriz->reporteActivosEmpresa(empresa);
                std::cout << ">> Reporte Generado!!!" << std::endl;
                break;
            }
            case 5: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Reporte Transacciones %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                reporteLista->reporteTransacciones();
                std::cout << ">> Reporte Generado!!!" <<std::endl;
                break;
            }
            case 6: {
                reporteActivosUsuario();
                break;
            }
            case 7: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Activos Rentados por Usuario %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << ">> ... Ingresar UserName del Usuario...:" <<std::endl;
                std::string userName;
                std::cin >> userName;
                reporteLista->reporteActivosRentadosUsuario(userName);
                std::cout << ">> Reportee Generado!!!" <<std::endl;
                break;
            }
            case 8: {
                int opcion;
                do {
                    std::cout << ">> \n%%%%%%%%%%%%%%%%%%%% Ordenar Transacciones %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                    std::cout << ">> %% 1. Ordenar Ascendentemente" <<std::endl;
                    std::cout << ">> %% 2. Ordenar Descendentemente" <<std::endl;
                    std::cout << ">> %% 3. Cancelar" <<std::endl;
                    Utils::verificarEntradaNumerica(opcion, ">> Opcion: ");
                    switch (opcion) {
                        case 1: {
                            listaTransacciones->setOrdenListaAscendente(true);
                            std::cout << ">> Orden Ascendente Establecido!!!" <<std::endl;
                            break;
                        }
                        case 2: {
                            listaTransacciones->setOrdenListaAscendente(false);
                            std::cout << ">> Orden Descendente Establecido!!!" <<std::endl;
                            break;
                        }
                        case 3: {
                            std::cout << ">> Ordenamiento Cancelado" <<std::endl;
                            break;
                        }
                        default: {
                            std::cout << ">> Opcion ingresada invalida. Intente otra vez" << std::endl;
                            break;
                        }
                    }
                } while (opcion != 3);
                break;
            }
            case 9: {
                std::cout << ">> Saliendo..." << std::endl;
                break;
            }
            default: {
                std::cout << ">> Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
            }
        }
    } while (opcionElegida != 9);
}

void Menus::registroUsuario() {
    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Registro Usuario %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    std::cout << ">> ... Ingresar UserName Usuario...:" <<std::endl;
    std::string userName;
    std::getline(std::cin, userName);

    std::cout << ">> ... Ingresar Password...:" <<std::endl;
    std::string password;
    std::getline(std::cin, password);

    std::cout << ">> ... Ingresar Departamento...:" <<std::endl;
    std::string departamento;
    std::getline(std::cin, departamento);

    std::cout << ">> ... Ingresar Empresa...:" <<std::endl;
    std::string empresa;
    std::getline(std::cin, empresa);

    std::cout << ">> ... Ingresar Nombre Completo...:" <<std::endl;
    std::string nombreCompleto;
    std::getline(std::cin, nombreCompleto);

    matrizDispersa->insretarUsuario(new Usuario(nombreCompleto, userName, password), departamento, empresa);
}

void Menus::reporteActivosUsuario() {
    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Activos de Usuario %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    std::cout << ">> ... Ingresar UserName del Usuario...:" <<std::endl;
    std::string userName;
    std::getline(std::cin, userName);

    std::cout << ">> ... Ingresar el Departamento...:" <<std::endl;
    std::string departamento;
    std::getline(std::cin, departamento);

    std::cout << ">> ... Ingresar la Empresa...:" <<std::endl;
    std::string empresa;
    std::getline(std::cin, empresa);

    NodoMatriz *aux = matrizDispersa->existeNodoInterseccion(departamento, empresa);
    if (aux != nullptr) {
        do {
            if (Utils::isEquals(aux->getUsuario()->getUsername(), userName)) {
                aux->getUsuario()->getReporteArbol()->reporteActivosUsuario(aux->getUsuario()->getArbol()->getRaiz(), userName);
                break;
            }
            aux = aux->getAtras();
        } while (aux != nullptr);

        if (aux == nullptr) std::cout << ">> No se Encontro al Usuario con las Credenciales Ingresadas" << std::endl;

    } else {
        std::cout << ">> No se Encontro al Usuario con las Credenciales Ingresadas" << std::endl;
    }
}

void Menus::menuUsuario(NodoMatriz *usuarioLogeado) {
    int opcionElegida;
    do {
        std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Menu de Usuario: " <<usuarioLogeado->getUsuario()->getNombre() <<" %%%%%%%%%%%%%%%%%%%%" <<std::endl;
        std::cout << ">> %% 1. Agregar Activo" <<std::endl;
        std::cout << ">> %% 2. Eliminar Activo" <<std::endl;
        std::cout << ">> %% 3. Modificar Activo" <<std::endl;
        std::cout << ">> %% 4. Rentar Activo" <<std::endl;
        std::cout << ">> %% 5. Activos Rentados" <<std::endl;
        std::cout << ">> %% 6. Mis Activos Rentados" <<std::endl;
        std::cout << ">> %% 7. Cerrar Sesion" <<std::endl;
        Utils::verificarEntradaNumerica(opcionElegida, ">> Opcion: ");
        switch (opcionElegida) {
            case 1: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Agregar Activo %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                std::cout << ">> ...Ingrese Nombre...: " <<std::endl;
                std::string nombre;
                std::getline(std::cin, nombre);

                std::cout << ">> ...Ingrese Descripcion...: " <<std::endl;
                std::string descripcion;
                std::getline(std::cin, descripcion);

                int dias;
                Utils::verificarEntradaNumerica(dias, ">> ...Ingrese los dias Disponibles para Rentar...: ");

                usuarioLogeado->getUsuario()->getArbol()->insertar(new Activo(nombre, descripcion, dias));
                break;
            }
            case 2: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Eliminar Activo %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                if (!usuarioLogeado->getUsuario()->getArbol()->mostrarActivos(true)) {
                    std::cout << ">> No hay Activos por Mostrar..." <<std::endl;
                    break;
                }
                std::cout << ">> ...Ingresar ID de Activo a Eliminar...";
                std::string idActivo;
                std::getline(std::cin, idActivo);
                usuarioLogeado->getUsuario()->getArbol()->eliminar(idActivo);
                break;
            }
            case 3: {
                modificarActivo(usuarioLogeado);
                break;
            }
            case 4: {
                rentaActivo(usuarioLogeado);
                break;
            }
            case 5: {
                activosRentados(usuarioLogeado);
                break;
            }
            case 6: {
                std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Mis Activos Rentados %%%%%%%%%%%%%%%%%%%%" <<std::endl;
                if (!usuarioLogeado->getUsuario()->getArbol()->mostrarActivos(false)) {
                    std::cout << ">> No hay Activos por Mostrar..." << std::endl;
                    break;
                }
                regresarMenu();
                break;
            }
            case 7: {
                usuarioLogeado = nullptr;
                std::cout << ">> Saliendo..." << std::endl;
                break;
            }
            default: {
                std::cout << ">> Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
            }
        }
    } while (opcionElegida != 7);
}

void Menus::modificarActivo(NodoMatriz *usuarioLogeado) {
    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Modificar Activo %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    if (!usuarioLogeado->getUsuario()->getArbol()->mostrarActivos(true)) {
        std::cout << ">> No hay Activos por Mostrar..." <<std::endl;
        return;
    }
    std::cout << ">> ...Ingresar ID de Activo a Modificar...: ";
    std::string idActivo;
    std::getline(std::cin, idActivo);

    std::cout << ">> ...Ingresar Descripcion Nueva...: ";
    std::string nuevaDescripcion;
    std::getline(std::cin, nuevaDescripcion);

    usuarioLogeado->getUsuario()->getArbol()->modificarActivo(idActivo, nuevaDescripcion);
    regresarMenu();
}

void Menus::rentaActivo(NodoMatriz *usuarioLogeado) {
    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Catalogo Activos %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    matrizDispersa->catalogoActivos(usuarioLogeado->getUsuario(), true, "");
    int opcionElegida;
    do {
        std::cout << ">> %% 1. Rentar Activo" <<std::endl;
        std::cout << ">> %% 2. Regresar a Menu" <<std::endl;
        Utils::verificarEntradaNumerica(opcionElegida, ">> ...Ingresar Opcion...: ");
        switch (opcionElegida) {
            case 1: {
                std::cout << ">> Ingresar ID de Activo a Rentar...";
                std::string idActivo;
                std::cin >> idActivo;
                NodoArbol *activoRentado = matrizDispersa->catalogoActivos(usuarioLogeado->getUsuario(), false, idActivo);
                if (activoRentado != nullptr) {
                    std::cout << ">> Activo a Rentar:" <<std::endl;
                    std::cout << ">> ID = " << idActivo << "; Nombre = " << activoRentado->getActivo()->getNombre() << "; Descripcion = " << activoRentado->getActivo()->getDescripcion() << std::endl;
                    int dias;
                    Utils::verificarEntradaNumerica(dias, ">> Ingrese los Dias por Rentar: ");
                    time_t t = time(nullptr);
                    tm *tiempoLocal = localtime(&t);
                    std::string fechaActual = std::to_string(tiempoLocal->tm_mday) + "-" + std::to_string(tiempoLocal->tm_mon + 1) + "-" + std::to_string(tiempoLocal->tm_year + 1900);
                    activoRentado->getActivo()->setDisponibilidad(false);
                    NodoMatriz *nodoDepartamento = matrizDispersa->buscarCabeceraHorizontal(usuarioLogeado);
                    NodoMatriz *nodoEmpresa = matrizDispersa->buscarCabeceraVertical(usuarioLogeado);
                    listaTransacciones->insertarTransaccion(new Transaccion(activoRentado->getActivo(), usuarioLogeado->getUsuario()->getNombre(), nodoDepartamento->getNombreCabecera(), nodoEmpresa->getNombreCabecera(), fechaActual, dias));
                    std::cout << ">> Activo Rentado Exitosamente" << std::endl;
                } else {
                    std::cout << ">> El Activo no Existe..." << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << ">> Regresando..." << std::endl;
                break;
            }
            default: {
                std::cout << ">> Opcion ingresada invalida. Intente otra vez" << std::endl;
                break;
            }
        }
    } while (opcionElegida != 1 && opcionElegida != 2);
}

void Menus::activosRentados(NodoMatriz *usuarioLogeado) {
    std::cout << "\n>> %%%%%%%%%%%%%%%%%%%% Activos Rentados %%%%%%%%%%%%%%%%%%%%" <<std::endl;
    if (listaTransacciones->recorrerListaTransaccion(usuarioLogeado->getUsuario()->getNombre())) {
        int opcionElegida;
        do {
            std::cout << ">> %% 1. Registrar Devolucion" << std::endl;
            std::cout << ">> %% 2. Regresar a Menu" << std::endl;
            Utils::verificarEntradaNumerica(opcionElegida, ">> ...Ingresar Opcion...: ");
            switch (opcionElegida) {
                case 1: {
                    std::cout << ">> Ingresar ID de Activo a Devolver...";
                    std::string idActivo;
                    std::cin >> idActivo;
                    NodoArbol *activoRentado = matrizDispersa->catalogoActivos(usuarioLogeado->getUsuario(), false, idActivo);
                    if (activoRentado != nullptr) {
                        std::cout << ">> Activo Devuelto:" <<std::endl;
                        std::cout << ">> ID = " << idActivo << "; Nombre = " << activoRentado->getActivo()->getNombre() << "; Descripcion = " << activoRentado->getActivo()->getDescripcion() << std::endl;
                        time_t t = time(nullptr);
                        tm *tiempoLocal = localtime(&t);
                        std::string fechaActual = std::to_string(tiempoLocal->tm_mday) + "-" + std::to_string(tiempoLocal->tm_mon + 1) + "-" + std::to_string(tiempoLocal->tm_year + 1900);
                        activoRentado->getActivo()->setDisponibilidad(true);
                        NodoMatriz *nodoDepartamento = matrizDispersa->buscarCabeceraHorizontal(usuarioLogeado);
                        NodoMatriz *nodoEmpresa = matrizDispersa->buscarCabeceraVertical(usuarioLogeado);
                        listaTransacciones->insertarTransaccion(new Transaccion(activoRentado->getActivo(), usuarioLogeado->getUsuario()->getNombre(), nodoDepartamento->getNombreCabecera(), nodoEmpresa->getNombreCabecera(), fechaActual, 0));
                        std::cout << ">> Activo Devuelto Exitosamente" << std::endl;
                    } else {
                        std::cout << ">> El Activo no Existe..." << std::endl;
                    }
                    break;
                }
                case 2: {
                    std::cout << ">> Regresando..." << std::endl;
                    break;
                }
                default: {
                    std::cout << ">> Opcion ingresada invalida. Intente otra vez" << std::endl;
                    break;
                }
            }
        } while (opcionElegida != 1 && opcionElegida != 2);
    } else {
        std::cout << ">> No Tienes Activos Rentados!!!" << std::endl;
    }
}

void Menus::regresarMenu() {
    int valorSalida;
    do {
        Utils::verificarEntradaNumerica(valorSalida, ">> ...Ingresar 1 para Regresar al Menu...: ");
    } while (valorSalida != 1);
    std::cout << ">> Regresando..." << std::endl;
}


