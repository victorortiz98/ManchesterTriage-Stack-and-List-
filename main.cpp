
#include <stdio.h>
#include <cstdlib>
#include "Pila.hpp"
#include <string>
#include "hospital.hpp"
#include <vector>
#include <list>
#include <windows.h>
#include <time.h>

int main(int argc, char **argv)
{
    Pacientes* pac1 = new Pacientes(1, "99999991A", "Silvia", "Martos", "Esteve", 45,'H');
    Pacientes* pac2 = new Pacientes(2, "99999992B", "Mario", "Ruíz", "Sánchez", 28,'V');
    Pacientes* pac3 = new Pacientes(3, "99999993C", "María", "Setién", "Buendía", 60,'H');
    Pacientes* pac4 = new Pacientes(4, "99999994D", "Luis", "Domínguez", "Gracia", 4,'V');
    Pacientes* pac5 = new Pacientes(5, "99999995E", "Eva", "Navarro", "Hueste", 23,'H');
    Pacientes* pac6 = new Pacientes(6, "99999996F", "José", "Márquez", "Méndez", 15,'V');
    Pacientes* pac7 = new Pacientes(7, "99999997G", "Lucía", "Vindel", "Higuera", 80,'H');
    Pacientes* pac8 = new Pacientes(8, "99999998H", "Víctor", "Méndez", "Gimeno", 67,'V');
    Pacientes* pac9 = new Pacientes(9, "99999999J", "Elena", "Espinosa", "Moreno", 2,'H');
    Pacientes* pac10 = new Pacientes(10, "10000000K", "Manuel", "García", "Pérez", 87,'V');
    Pila pilaPacientes;
    Pila* pPilaPacientes = &pilaPacientes;
    Pila pilaPacientesTemp;
    Pila* pPilaPacientesTemp = &pilaPacientesTemp;
    pilaPacientes.push (pac1);
    pilaPacientes.push(pac2);
    pilaPacientes.push (pac3);
    pilaPacientes.push(pac4);
    pilaPacientes.push (pac5);
    pilaPacientes.push(pac6);
    pilaPacientes.push (pac7);
    pilaPacientes.push(pac8);
    pilaPacientes.push (pac9);
    pilaPacientes.push(pac10);
    int opcion;
    std:: string dni;
    while(opcion!=5){
        Hospital* mostrar=new Hospital();

        std::cout << "------------------- TRIAJE DE MANCHESTER  --------------------------"<< endl;
        std::cout << "|    Bienvenidos al sistema informático de gestión de emergencias  |     "<< endl;
        std::cout << "---------------------------------------------------------------------"<< endl;
        std::cout << "                                                                 "<< endl;
        std::cout << "Introduce el número de la opción que desee ejecutar:" << endl;
        std::cout << "0. Dar de alta de paciente en una lista emergencia" << endl;
        std::cout << "1. Baja de paciente en una lista de emergencia." << endl;
        std::cout << "2. Modificación o reasignación de paciente a tipo emergencia." << endl;
        std::cout << "3. Consultas de pacientes/emergencias." << endl;
        std::cout << "4. Reiniciar programa." << endl;
        std::cout << "5. Salir del programa." << endl;
        std::cout << "                                                                 "<< endl;
        std::cout << "------------------------------------------------------------"<< endl;
        std::cin >> opcion;
        switch(opcion){
            case 0:
                mostrar->altaPacientes(pilaPacientes, pilaPacientesTemp);
                break;
            case 1:

                if (pilaPacientes.esVacia()){
                    cout<<"La pila de pacientes está vacía. Para continuar reinicie el programa (opcion 4) o pulse 5 para salir del programa:" << endl;
                    break;
                }


                mostrar->bajaPacientes(pilaPacientes, pilaPacientesTemp);
                break;
            case 2:

                mostrar->reasignacionListaEmergencia();
                break;
            case 3:
                mostrar->menuOpcion3(pilaPacientes, pilaPacientesTemp);
                break;
            case 4:
                while(!pilaPacientes.esVacia()){
                    pilaPacientes.mostrar(false);
                }
                pilaPacientes.push(pac1);
                pilaPacientes.push(pac2);
                pilaPacientes.push(pac3);
                pilaPacientes.push(pac4);
                pilaPacientes.push(pac5);
                pilaPacientes.push(pac6);
                pilaPacientes.push(pac7);
                pilaPacientes.push(pac8);
                pilaPacientes.push(pac9);
                pilaPacientes.push(pac10);
                mostrar->vaciarListas();
                system("cls");
                std::cout << "Se ha reiniciado el programa. Espere..." << endl;
                break;
            case 5:
                std::cout << "Saliendo del programa. Gracias por utilizar nuestros servicios." << endl;
                break;
        }
    }
    return 0;
}