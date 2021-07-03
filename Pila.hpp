//
// Created by Víctor Ortiz on 14/06/2021.
//

#ifndef TEST_PILA_HPP
#define TEST_PILA_HPP

#include "NodoPila.hpp"

class Pila
{
private:
    pnodo cima;
public:
    Pila();
    ~Pila();
    bool esVacia();
    void push(Pacientes* v);
    void pop();
    int mostrar(bool escribir);
    void buscarDni(Pila &pilaPacientes, string dni);
    int devolverId( );
    string devolverDni( );
    string devolverNombre( );
    string devolverApellido1();
    string devolverApellido2();
    int devolverEdad();
    char devolverSexo();
    void eliminarElemento(Pila &pilaPacientesTemp, Pila &pilaPacientes );

};

#endif //TEST_PILA_HPP
