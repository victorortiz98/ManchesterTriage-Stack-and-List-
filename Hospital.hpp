//
// Created by Víctor Ortiz on 14/06/2021.
//

#ifndef TEST_HOSPITAL_HPP
#define TEST_HOSPITAL_HPP

#include "Pila.hpp"
#include <iostream>
#include <list>

class Hospital
{
public:
    Hospital();
    ~Hospital();
    void verificarDni(Pila &pilaPacientes, Pila &pilaPacientesTemp);
    void mostrarTodos(Pila &pilaPacientes, Pila &pilaPacientesTemp);
    void verificarId();
    void mostrarEmergencias();
    void verificarListasVacio ();
    void altaPacientes (Pila &pilaPacientes, Pila &pilaPacientesTemp);
    void bajaPacientes( Pila &pilaPacientes, Pila &pilaPacientesTemp );
    void reasignacionListaEmergencia();
    void vaciarListas();
    void consultarTiempos();
    std::string inputDni();
    void menuOpcion3(Pila &pilaPacientes, Pila &pilaPacientesTemp);
private:

};

#endif //TEST_HOSPITAL_HPP
