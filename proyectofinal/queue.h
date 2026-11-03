#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "nodo.h"

class Queue{
    private:
        Nodo* primero;
        Nodo* ultimo;
        int counter;
    public:
        Queue();
        ~Queue();
        void enqueue(Carta carta);
        void dequeue();
        Carta front();
        bool empty();
        void clear();
};


Queue::Queue()
{
    primero = NULL;
    ultimo = NULL;
    counter = 0;
}

Queue::~Queue()
{
    clear();
}

bool Queue::empty()
{
    return counter == 0;
}

void Queue::enqueue(Carta carta)
{
    Nodo* nuevo = new Nodo(carta);
    if (empty()){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
    counter++;
}

Carta Queue::front()
{
    if (empty())
    {
        std::cout << "La cola está vacía" << std::endl;
        return Carta();
    }

    return primero->getDato();
}

void Queue::dequeue()
{
    if (empty()){
        std::cout<< "La cola está vacía" << std::endl;
    }
    else{
        Nodo* auxiliar = primero;
        primero = primero->getSiguiente();
        delete auxiliar;
        counter--;
        if (primero == NULL){
            ultimo = NULL;
        }

    }
}

void Queue::clear()
{
    while (empty()==false){
        dequeue();
    }
}

#endif