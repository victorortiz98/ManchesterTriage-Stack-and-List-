//
// Created by Víctor Ortiz on 14/06/2021.
//

#ifndef TEST_NODOPILA_HPP
#define TEST_NODOPILA_HPP

#include <iostream>
#include "Pacientes.hpp"
using namespace std;

class NodoPila
{
private:
        Pacientes* valor;
        NodoPila *siguiente;
    friend class Pila;
public:
    NodoPila();
    NodoPila(Pacientes* valor, NodoPila *sig = NULL);
    ~NodoPila();

};
typedef NodoPila *pnodo;

#endif //TEST_NODOPILA_HPP
