#ifndef NODO_H_
#define NODO_H_

#include "carta.h"

class Nodo
{
private:
    Carta data;
    Nodo* sig;

public:
    Nodo(Carta carta);
    Carta getDato();
    Nodo* getSiguiente();
    void setSiguiente(Nodo* siguiente);
};


Nodo::Nodo(Carta carta)
{
    data = carta;
    sig = NULL;
}

Carta Nodo::getDato()
{
    return data;
}

Nodo* Nodo::getSiguiente()
{
    return sig;
}

void Nodo::setSiguiente(Nodo* siguiente)
{
    sig = siguiente;
}

#endif