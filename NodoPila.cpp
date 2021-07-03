//
// Created by Víctor Ortiz on 14/06/2021.
//

#include "NodoPila.hpp"

NodoPila::NodoPila()
{
    valor=0;
    siguiente=NULL;
}
NodoPila::NodoPila(Pacientes* pct, NodoPila *sig)
{
    valor = pct;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}