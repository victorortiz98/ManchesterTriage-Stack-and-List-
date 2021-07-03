//
// Created by Víctor Ortiz on 14/06/2021.
//
#include "Hospital.hpp"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <list>

Hospital::Hospital() {
}

Pila *pila = new Pila();
list<string> ListaR;
list<string> ListaN;
list<string> ListaV;
list<string> ListaA;
list<string> ListaTemp;

std::string Hospital::inputDni() {
    std::string dniCliente;
    std::cout << "Introduce el DNI del paciente a dar de alta:" << endl;
    std::cin >> dniCliente;
    return dniCliente;
}

//CASE0:
void Hospital::altaPacientes(Pila &pilaPacientes, Pila &pilaPacientesTemp) {

    char lista = 'S';
    while (!pilaPacientes.esVacia() && lista != 'X') {
        string valorFecha = "";
        SYSTEMTIME fecha;
        GetSystemTime(&fecha);
        int datoId = pilaPacientes.devolverId();
        std::string datoDni = (std::string)(pilaPacientes.devolverDni()).c_str();
        std::string datoNombre = (std::string)(pilaPacientes.devolverNombre()).c_str();
        std::string datoAp1 = (std::string)(pilaPacientes.devolverApellido1()).c_str();
        std::string datoAp2 = (std::string)(pilaPacientes.devolverApellido2()).c_str();
        int datoEdad = pilaPacientes.devolverEdad();
        char datoSexo = pilaPacientes.devolverSexo();
        std::cout << "ID: " << datoId << endl;
        std::cout << "DNI: " << datoDni << endl;
        std::cout << "Nombre: " << datoNombre << endl;
        std::cout << "Primer apellido: " << datoAp1 << endl;
        std::cout << "Segundo apellido: " << datoAp2 << endl;
        std::cout << "Edad: " << datoEdad << endl;
        std::cout << "Sexo: " << datoSexo << endl;
        do {
            std::cout << "Introduce una lista de emergencias(A/N/V/R). Pulsa X (mayúscula) para terminar con el proceso de alta:" << endl;
            std::cin >> lista;
            if (lista == 'A') {
                pilaPacientes.mostrar(false);
                valorFecha =
                        to_string(fecha.wYear) + "/" + to_string(fecha.wMonth) + "/" + to_string(fecha.wDay) + " " +
                        to_string(fecha.wHour + 1) + ":" + to_string(fecha.wMinute) + ":" + to_string(fecha.wSecond);
                ListaA.push_back(to_string(datoId));
                ListaA.push_back(datoDni);
                ListaA.push_back(valorFecha);
            } else if (lista == 'V') {
                pilaPacientes.mostrar(false);
                valorFecha =
                        to_string(fecha.wYear) + "/" + to_string(fecha.wMonth) + "/" + to_string(fecha.wDay) + " " +
                        to_string(fecha.wHour + 1) + ":" + to_string(fecha.wMinute) + ":" + to_string(fecha.wSecond);
                ListaV.push_back(to_string(datoId));
                ListaV.push_back(datoDni);
                ListaV.push_back(valorFecha);
            } else if (lista == 'R') {
                pilaPacientes.mostrar(false);
                valorFecha =
                        to_string(fecha.wYear) + "/" + to_string(fecha.wMonth) + "/" + to_string(fecha.wDay) + " " +
                        to_string(fecha.wHour + 1) + ":" + to_string(fecha.wMinute) + ":" + to_string(fecha.wSecond);
                ListaR.push_back(to_string(datoId));
                ListaR.push_back(datoDni);
                ListaR.push_back(valorFecha);
            } else if (lista == 'N') {
                pilaPacientes.mostrar(false);
                valorFecha =
                        to_string(fecha.wYear) + "/" + to_string(fecha.wMonth) + "/" + to_string(fecha.wDay) + " " +
                        to_string(fecha.wHour + 1) + ":" + to_string(fecha.wMinute) + ":" + to_string(fecha.wSecond);
                ListaN.push_back(to_string(datoId));
                ListaN.push_back(datoDni);
                ListaN.push_back(valorFecha);
            } else if (lista != 'X') {
                std::cout << "La lista introducida es incorrecta" << endl;
            }
        } while (lista != 'A' && lista != 'V' && lista != 'N' && lista != 'R' && lista != 'X');
    }
    pilaPacientesTemp = pilaPacientes;


}

//CASE1:
void Hospital::bajaPacientes(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    std::string dni = inputDni();
    while (!pilaPacientesTemp.esVacia()) {
        pilaPacientesTemp.mostrar(false);
    }
    pilaPacientes.eliminarElemento(pilaPacientesTemp, pilaPacientes);
    int contar1;
    contar1 = 0;

    for (string valor : ListaR) {
        if (contar1 > 0) {
            contar1++;
        }
        if (valor == dni) {
            contar1++;
            ListaTemp.pop_back(); //Lee y elimina el elemento por detras
        }
        if (contar1 == 0) {
            ListaTemp.push_back(valor); //Introduce el elemento por el final
        }
        if (contar1 == 2) {
            contar1 = 0;
        }
    }
    ListaR = ListaTemp;
    ListaTemp.clear(); //Elimina todos los elementos
    contar1 = 0;
    for (string valor : ListaN) {
        if (contar1 > 0) {
            contar1++;
        }
        if (valor == dni) {
            contar1++;
            ListaTemp.pop_back();
        }
        if (contar1 == 0) {
            ListaTemp.push_back(valor);
        }
        if (contar1 == 2) {
            contar1 = 0;
        }
    }
    ListaN = ListaTemp;
    ListaTemp.clear();
    contar1 = 0;
    for (string valor : ListaV) {
        if (contar1 > 0) {
            contar1++;
        }
        if (valor == dni) {
            contar1++;
            ListaTemp.pop_back();
        }
        if (contar1 == 0) {
            ListaTemp.push_back(valor);
        }
        if (contar1 == 2) {
            contar1 = 0;
        }
    }
    ListaV = ListaTemp;
    ListaTemp.clear();
    contar1 = 0;
    for (string valor : ListaA) {
        if (contar1 > 0) {
            contar1++;
        }
        if (valor == dni) {
            contar1++;
            ListaTemp.pop_back();
        }
        if (contar1 == 0) {
            ListaTemp.push_back(valor);
        }
        if (contar1 == 2) {
            contar1 = 0;
        }
    }
    ListaA = ListaTemp;
    ListaTemp.clear();


}

//CASE2:
void Hospital::reasignacionListaEmergencia() {
    string valorFec = "";
    SYSTEMTIME fec;
    GetSystemTime(&fec);
    std::string dni = inputDni();
    char listaEmergencia;
    do {
        std::cout << "Introduce la lista de emergencia (R/N/V/A) en la que el paciente está asignado :" << endl;
        std::cin >> listaEmergencia;
        if (listaEmergencia != 'R' && listaEmergencia != 'N' && listaEmergencia != 'V' && listaEmergencia != 'A') {
            std::cout << "La lista introducida no es correcta" << endl;
        }
    } while (listaEmergencia != 'R' && listaEmergencia != 'N' && listaEmergencia != 'V' && listaEmergencia != 'A');
    char nuevaLista;
    do {
        std::cout << "Introduce la lista(R/N/V/A) en la que quieres reasignar al paciente:" << endl;
        std::cin >> nuevaLista;
        if (nuevaLista != 'R' && nuevaLista != 'N' && nuevaLista != 'V' && nuevaLista != 'A') {
            std::cout << "La lista introducida no es correcta" << endl;
        }
    } while (nuevaLista != 'R' && nuevaLista != 'N' && nuevaLista != 'V' && nuevaLista != 'A');
    valorFec = to_string(fec.wYear) + "/" + to_string(fec.wMonth) + "/" + to_string(fec.wDay) + " " +
               to_string(fec.wHour + 1) + ":" + to_string(fec.wMinute) + ":" + to_string(fec.wSecond);
    int contar = 0;
    bool localizado = false;
    int cont1 = 0;
    int cont2 = 0;
    bool localizado2 = false;
    if (listaEmergencia == 'R') {
        for (string valor : ListaR) {
            if (contar > 0) {
                contar++;
            }
            if (valor == dni) {
                contar++;
                ListaTemp.pop_back();
                localizado = true;
            }
            if (contar == 0) {
                ListaTemp.push_back(valor);
            }
            if (contar == 2) {
                contar = 0;
            }
        }
        for (string valor : ListaR) {
            cont1++;
            localizado2 = false;
            for (string valor2 : ListaTemp) {
                if (valor == valor2) {
                    localizado2 = true;
                }
            }
            if (!localizado2 && cont1 < 3) {
                cont2++;
                if (nuevaLista == 'R') {
                    ListaR.push_back(valor);
                    if (cont2 == 2) {
                        ListaR.push_back(valorFec);
                    }
                } else if (nuevaLista == 'N') {
                    ListaN.push_back(valor);
                    if (cont2 == 2) {
                        ListaN.push_back(valorFec);
                    }
                } else if (nuevaLista == 'V') {
                    ListaV.push_back(valor);
                    if (cont2 == 2) {
                        ListaV.push_back(valorFec);
                    }
                } else if (nuevaLista == 'A') {
                    ListaA.push_back(valor);
                    if (cont2 == 2) {
                        ListaA.push_back(valorFec);
                    }
                }
            }
            if (cont1 == 3) {
                cont1 = 0;
            }
        }
        ListaR = ListaTemp;
        ListaTemp.clear();
    } else if (listaEmergencia == 'N') {
        for (string valor : ListaN) {
            if (contar > 0) {
                contar++;
            }
            if (valor == dni) {
                contar++;
                ListaTemp.pop_back();
                localizado = true;
            }
            if (contar == 0) {
                ListaTemp.push_back(valor);
            }
            if (contar == 2) {
                contar = 0;
            }
        }
        for (string valor : ListaN) {
            cont1++;
            localizado2 = false;
            for (string valor2 : ListaTemp) {
                if (valor == valor2) {
                    localizado2 = true;
                }
            }
            if (!localizado2 && cont1 < 3) {
                cont2++;
                if (nuevaLista == 'R') {
                    ListaR.push_back(valor);
                    if (cont2 == 2) {
                        ListaR.push_back(valorFec);
                    }
                } else if (nuevaLista == 'N') {
                    ListaN.push_back(valor);
                    if (cont2 == 2) {
                        ListaN.push_back(valorFec);
                    }
                } else if (nuevaLista == 'V') {
                    ListaV.push_back(valor);
                    if (cont2 == 2) {
                        ListaV.push_back(valorFec);
                    }
                } else if (nuevaLista == 'A') {
                    ListaA.push_back(valor);
                    if (cont2 == 2) {
                        ListaA.push_back(valorFec);
                    }
                }
            }
            if (cont1 == 3) {
                cont1 = 0;
            }
        }
        ListaN = ListaTemp;
        ListaTemp.clear();
    } else if (listaEmergencia == 'A') {
        for (string valor : ListaA) {
            if (contar > 0) {
                contar++;
            }
            if (valor == dni) {
                contar++;
                ListaTemp.pop_back();
                localizado = true;
            }
            if (contar == 0) {
                ListaTemp.push_back(valor);
            }
            if (contar == 2) {
                contar = 0;
            }
        }
        for (string valor : ListaA) {
            cont1++;
            localizado2 = false;
            for (string valor2 : ListaTemp) {
                if (valor == valor2) {
                    localizado2 = true;
                }
            }
            if (!localizado2 && cont1 < 3) {
                cont2++;
                if (nuevaLista == 'R') {
                    ListaR.push_back(valor);
                    if (cont2 == 2) {
                        ListaR.push_back(valorFec);
                    }
                } else if (nuevaLista == 'N') {
                    ListaN.push_back(valor);
                    if (cont2 == 2) {
                        ListaN.push_back(valorFec);
                    }
                } else if (nuevaLista == 'V') {
                    ListaV.push_back(valor);
                    if (cont2 == 2) {
                        ListaV.push_back(valorFec);
                    }
                } else if (nuevaLista == 'A') {
                    ListaA.push_back(valor);
                    if (cont2 == 2) {
                        ListaA.push_back(valorFec);
                    }
                }
            }
            if (cont1 == 3) {
                cont1 = 0;
            }
        }
        ListaA = ListaTemp;
        ListaTemp.clear();
    } else if (listaEmergencia == 'V') {
        for (string valor : ListaV) {
            if (contar > 0) {
                contar++;
            }
            if (valor == dni) {
                contar++;
                ListaTemp.pop_back();
                localizado = true;
            }
            if (contar == 0) {
                ListaTemp.push_back(valor);
            }
            if (contar == 2) {
                contar = 0;
            }
        }
        for (string valor : ListaV) {
            cont1++;
            localizado2 = false;
            for (string valor2 : ListaTemp) {
                if (valor == valor2) {
                    localizado2 = true;
                }
            }
            if (!localizado2 && cont1 < 3) {
                cont2++;
                if (nuevaLista == 'R') {
                    ListaR.push_back(valor);
                    if (cont2 == 2) {
                        ListaR.push_back(valorFec);
                    }
                } else if (nuevaLista == 'N') {
                    ListaN.push_back(valor);
                    if (cont2 == 2) {
                        ListaN.push_back(valorFec);
                    }
                } else if (nuevaLista == 'V') {
                    ListaV.push_back(valor);
                    if (cont2 == 2) {
                        ListaV.push_back(valorFec);
                    }
                } else if (nuevaLista == 'A') {
                    ListaA.push_back(valor);
                    if (cont2 == 2) {
                        ListaA.push_back(valorFec);
                    }
                }
            }
            if (cont1 == 3) {
                cont1 = 0;
            }
        }
        ListaV = ListaTemp;
        ListaTemp.clear();
    }
    if (!localizado) {
        std::cout << "El DNI introducido no se ha encontrado en la lista" << endl;
    }
}

//CASE3:
void Hospital::menuOpcion3(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    int opc;
    bool comprobar = false;
    while (!comprobar) {
        comprobar = true;
        std::cout << "Selecciona la opción que quieres ejecutar:" << endl;
        std::cout << "1. Consulta de pacientes." << endl;
        std::cout << "2. Consulta de emergencias." << endl;
        std::cout << "3. Mostrar tiempos de emergencia superados." << endl;
        std::cin >> opc;
        if (opc == 1) {
            bool comprobar1 = false;
            int opcion1;
            Hospital *mostrar = new Hospital();
            while (!comprobar1) {
                comprobar1 = true;
                std::cout << "Selecciona el tipo de consulta que quieres realizar:" << endl;
                std::cout << "1. Mostrar paciente indicando su DNI" << endl;
                std::cout << "2. Mostrar todos los pacientes" << endl;
                std::cin >> opcion1;
                if (opcion1 < 1 || opcion1 > 2) {
                    comprobar1 = false;
                    std::cout << "La opción seleccionada no es válida" << endl;
                }
                if (opcion1 == 1) {
                    mostrar->verificarDni(pilaPacientes, pilaPacientesTemp);
                } else {
                    mostrar->mostrarTodos(pilaPacientes, pilaPacientesTemp);
                }
            }
        } else if (opc == 2) {
            bool comprobar2 = false;
            int opcion2;
            Hospital *mostrar = new Hospital();
            while (!comprobar2) {
                comprobar2 = true;
                std::cout << "Elige un tipo de consulta:" << endl;
                std::cout << "1. Mostrar emergencia indicando su ID" << endl;
                std::cout << "2. Mostrar todas las emergencias" << endl;
                std::cin >> opcion2;
                if (opcion2 < 1 || opcion2 > 2) {
                    comprobar2 = false;
                    std::cout << "La opción introducida es correcta" << endl;
                }
                if (opcion2 == 1) {
                    mostrar->verificarListasVacio();

                } else {
                    mostrar->mostrarEmergencias();

                }
            }
        } else if (opc == 3) {
            Hospital *mostrar = new Hospital();
            mostrar->consultarTiempos();

        } else {
            std::cout << "La opcion introducida es incorrecta" << endl;
            comprobar = false;
        }
    }
}

//CASE3.1.1
void Hospital::verificarDni(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    pilaPacientesTemp = pilaPacientes;
    string dni;
    std::cout << "Introduce el DNI que desee verificar: " << endl;
    std::cin >> dni;
    pilaPacientes.buscarDni(pilaPacientes, dni);
    pilaPacientes = pilaPacientesTemp;
}

//CASE3.1.2
void Hospital::mostrarTodos(Pila &pilaPacientes, Pila &pilaPacientesTemp) {
    pilaPacientesTemp = pilaPacientes;
    while (!pilaPacientes.esVacia()) {
        pilaPacientes.mostrar(true);
    }
    pilaPacientes = pilaPacientesTemp;
}

//CASE 3.2.1
void Hospital::verificarListasVacio() {
    int numElementos = 0;
    for (string valor : ListaR) {
        if (valor != "") {
            numElementos++;
        }
    }
    for (string valor : ListaA) {
        if (valor != "") {
            numElementos++;
        }
    }
    for (string valor : ListaV) {
        if (valor != "") {
            numElementos++;
        }
    }
    for (string valor : ListaN) {
        if (valor != "") {
            numElementos++;
        }
    }
    if (numElementos == 0) {
        std::cout << "Las listas de emergencia estan vacias" << endl;
    } else {
        verificarId();
    }

}

void Hospital::verificarId() {
    int id;
    bool encontrado = false;
    int contador = 0;
    while (!encontrado) {
        std::cout << "Introduce el numero ID del paciente:" << endl;
        std::cin >> id;
        for (string valor : ListaR) {
            if (valor == to_string(id)) {
                encontrado = true;
            }
            if (encontrado) {
                contador++;
            }
            if (contador == 2) {
                std::cout << valor << '\n';
                std::cout << "El paciente indicado pertenece a la lista de emergencias R" << endl;
            }
        }
        for (string valor : ListaA) {
            if (valor == to_string(id)) {
                encontrado = true;
            }
            if (encontrado) {
                contador++;
            }
            if (contador == 2) {
                std::cout << valor << '\n';
                std::cout << "El paciente indicado pertenece a la lista de emergencias A" << endl;
            }
        }
        for (string valor : ListaV) {
            if (valor == to_string(id)) {
                encontrado = true;
            }
            if (encontrado) {
                contador++;
            }
            if (contador == 2) {
                std::cout << valor << '\n';
                std::cout << "El paciente indicado pertenece a la lista de emergencias V" << endl;
            }
        }
        for (string valor : ListaN) {
            if (valor == to_string(id)) {
                encontrado = true;
            }
            if (encontrado) {
                contador++;
            }
            if (contador == 2) {
                std::cout << valor << '\n';
                std::cout << "El paciente indicado pertenece a la lista de emergencias N" << endl;
            }
        }
        if (!encontrado) {
            std::cout << "El ID indicado no pertenece a ningún paciente. Verifique que el ID es correcto" << endl;
        }
    }
}


//CASE 3.2.2
void Hospital::mostrarEmergencias() {
    int contador = 0;
    std::cout << "Lista R:" << endl;
    for (string valor : ListaR) {
        contador++;
        std::cout << valor << '\n';
        if (contador % 3 == 0) {
            std::cout << "-----------" << endl;
        }
    }
    std::cout << "Lista N:" << endl;
    for (string valor : ListaN) {
        contador++;
        std::cout << valor << '\n';
        if (contador % 3 == 0) {
            std::cout << "-----------" << endl;
        }
    }
    std::cout << "Lista V:" << endl;
    for (string valor : ListaV) {
        contador++;
        std::cout << valor << '\n';
        if (contador % 3 == 0) {
            std::cout << "-----------" << endl;
        }
    }
    std::cout << "Lista A:" << endl;
    for (string valor : ListaA) {
        contador++;
        std::cout << valor << '\n';
        if (contador % 3 == 0) {
            std::cout << "-----------" << endl;
        }
    }
}

//CASE 3.3
void Hospital::consultarTiempos() {
    string codi;
    string dn;
    string fec;
    int contPac;
    contPac = 0;
    string valorHora;
    string valorMinutos;
    string valorSegundos;
    string caracter;
    int numVariables = 0;
    int segTrans = 0;
    int minTrans = 0;
    int horTrans = 0;
    SYSTEMTIME fecha1;
    GetSystemTime(&fecha1);
    int horaActual = fecha1.wHour + 1;
    int minutoActual = fecha1.wMinute;
    int segundoActual = fecha1.wSecond;
    std::cout << "Lista R:" << endl;
    for (string valor : ListaR) {
        contPac++;
        valorMinutos = "";
        valorSegundos = "";
        valorHora = "";
        if (contPac == 1) {
            codi = valor;
        } else if (contPac == 2) {
            dn = valor;
        } else if (contPac == 3) {
            fec = valor;
            numVariables = 0;
            contPac = 0;
            for (int i = 0; i < valor.size(); i++) {
                caracter = valor.substr(i, 1);
                if (caracter == "/" || caracter == ":" || caracter == " ") {
                    numVariables++;
                } else if (numVariables == 3) {
                    valorHora = valorHora + caracter;
                } else if (numVariables == 4) {
                    valorMinutos = valorMinutos + caracter;
                } else if (numVariables == 5) {
                    valorSegundos = valorSegundos + caracter;
                }
            }
            segTrans = segundoActual - atoi(valorSegundos.c_str());
            minTrans = minutoActual - atoi(valorMinutos.c_str());
            horTrans = horaActual - atoi(valorHora.c_str());
            if (segTrans < 0) {
                segTrans = segTrans + 60;
                minTrans = minTrans - 1;
            }
            if (minTrans < 0) {
                minTrans = minTrans + 60;
                horTrans = horTrans - 1;
            }
            if (segTrans != 0 || minTrans != 0 || horTrans != 0) {
                std::cout << codi << endl;
                std::cout << dn << endl;
                std::cout << fec << endl;
                std::cout << "Tiempo transcurrido: " << horTrans << ":" << minTrans << ":" << segTrans << endl;
            }
        }
    }

    std::cout << "Lista N:" << endl;
    for (string valor : ListaN) {
        contPac++;
        valorMinutos = "";
        valorSegundos = "";
        valorHora = "";
        if (contPac == 1) {
            codi = valor;
        } else if (contPac == 2) {
            dn = valor;
        } else if (contPac == 3) {
            fec = valor;
            numVariables = 0;
            contPac = 0;
            for (int i = 0; i < valor.size(); i++) {
                caracter = valor.substr(i, 1);
                if (caracter == "/" || caracter == ":" || caracter == " ") {
                    numVariables++;
                } else if (numVariables == 3) {
                    valorHora = valorHora + caracter;
                } else if (numVariables == 4) {
                    valorMinutos = valorMinutos + caracter;
                } else if (numVariables == 5) {
                    valorSegundos = valorSegundos + caracter;
                }
            }
            segTrans = segundoActual - atoi(valorSegundos.c_str());
            minTrans = minutoActual - atoi(valorMinutos.c_str());
            horTrans = horaActual - atoi(valorHora.c_str());
            if (segTrans < 0) {
                segTrans = segTrans + 60;
                minTrans = minTrans - 1;
            }
            if (minTrans < 0) {
                minTrans = minTrans + 60;
                horTrans = horTrans - 1;
            }
            if (minTrans > 15 || (minTrans == 15 && segTrans > 0)) {
                std::cout << codi << endl;
                std::cout << dn << endl;
                std::cout << fec << endl;
                std::cout << "Tiempo transcurrido: " << horTrans << ":" << minTrans << ":" << segTrans << endl;
            }
        }
    }

    std::cout << "Lista A:" << endl;
    for (string valor : ListaA) {
        contPac++;
        valorMinutos = "";
        valorSegundos = "";
        valorHora = "";
        if (contPac == 1) {
            codi = valor;
        } else if (contPac == 2) {
            dn = valor;
        } else if (contPac == 3) {
            fec = valor;
            numVariables = 0;
            contPac = 0;
            for (int i = 0; i < valor.size(); i++) {
                caracter = valor.substr(i, 1);
                if (caracter == "/" || caracter == ":" || caracter == " ") {
                    numVariables++;
                } else if (numVariables == 3) {
                    valorHora = valorHora + caracter;
                } else if (numVariables == 4) {
                    valorMinutos = valorMinutos + caracter;
                } else if (numVariables == 5) {
                    valorSegundos = valorSegundos + caracter;
                }
            }
            segTrans = segundoActual - atoi(valorSegundos.c_str());
            minTrans = minutoActual - atoi(valorMinutos.c_str());
            horTrans = horaActual - atoi(valorHora.c_str());
            if (segTrans < 0) {
                segTrans = segTrans + 60;
                minTrans = minTrans - 1;
            }
            if (minTrans < 0) {
                minTrans = minTrans + 60;
                horTrans = horTrans - 1;
            }
            if (horTrans > 1 || (horTrans == 1 && (minTrans > 0 || segTrans > 0))) {
                std::cout << codi << endl;
                std::cout << dn << endl;
                std::cout << fec << endl;
                std::cout << "Tiempo transcurrido: " << horTrans << ":" << minTrans << ":" << segTrans << endl;
            }
        }
    }

    std::cout << "Lista V:" << endl;
    for (string valor : ListaV) {
        contPac++;
        valorMinutos = "";
        valorSegundos = "";
        valorHora = "";
        if (contPac == 1) {
            codi = valor;
        } else if (contPac == 2) {
            dn = valor;
        } else if (contPac == 3) {
            fec = valor;
            numVariables = 0;
            contPac = 0;
            for (int i = 0; i < valor.size(); i++) {
                caracter = valor.substr(i, 1);
                if (caracter == "/" || caracter == ":" || caracter == " ") {
                    numVariables++;
                } else if (numVariables == 3) {
                    valorHora = valorHora + caracter;
                } else if (numVariables == 4) {
                    valorMinutos = valorMinutos + caracter;
                } else if (numVariables == 5) {
                    valorSegundos = valorSegundos + caracter;
                }
            }
            segTrans = segundoActual - atoi(valorSegundos.c_str());
            minTrans = minutoActual - atoi(valorMinutos.c_str());
            horTrans = horaActual - atoi(valorHora.c_str());
            if (segTrans < 0) {
                segTrans = segTrans + 60;
                minTrans = minTrans - 1;
            }
            if (minTrans < 0) {
                minTrans = minTrans + 60;
                horTrans = horTrans - 1;
            }
            if (horTrans > 1) {
                std::cout << codi << endl;
                std::cout << dn << endl;
                std::cout << fec << endl;
                std::cout << "Tiempo transcurrido: " << horTrans << ":" << minTrans << ":" << segTrans << endl;
            }
        }
    }

}


//CASE 4
void Hospital::vaciarListas() {
    int cont;
    cont = 0;
    for (string valor : ListaN) {
        cont++;
    }
    for (int i = 0; i < cont; i++) {
        ListaN.pop_back();
    }
    cont = 0;
    for (string valor : ListaR) {
        cont++;
    }
    for (int i = 0; i < cont; i++) {
        ListaR.pop_back();

    }
    cont = 0;
    for (string valor : ListaA) {
        cont++;
    }
    for (int i = 0; i < cont; i++) {
        ListaA.pop_back();
    }
    cont = 0;
    for (string valor : ListaV) {
        cont++;
    }
    for (int i = 0; i < cont; i++) {
        ListaV.pop_back();
    }
}

Hospital::~Hospital() {
}
