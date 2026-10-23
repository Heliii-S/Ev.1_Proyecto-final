#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "carta.h"

class Queue{
    private:
        Carta* data;
        int head;
        int tail;
        int capacidad;
        int counter;
    public:
        Queue(int cap);
        ~Queue();
        void enqueue(Carta carta);
        void dequeue();
        Carta front();
        bool empty();
        bool full();
        void clear();
};

Queue::Queue(int cap)
{
    capacidad = cap;
    data = new Carta[capacidad];
    head = 0;
    tail = 0;
    counter = 0;
}

Queue::~Queue()
{
    delete[] data;
}

bool Queue::empty()
{
    return counter == 0;
}

bool Queue::full()
{
    return counter == capacidad;
}

void Queue::enqueue(Carta carta)
{
    if (full()==false)
    {
        data[tail] = carta;
        tail++;
        if(tail == capacidad){
            tail = 0;
        }
        counter++;
    }
    else
    {
        std::cout << "La cola esta llena" << std::endl;
    }
}

Carta Queue::front()
{
    if (empty()==false)
    {
        return data[head];
    }

    std::cout << "La cola esta vacia" << std::endl;
    return Carta();
}

void Queue::dequeue()
{
    if (empty()==false)
    {
        head++;
        if (head == capacidad){
            head = 0;
        }
        counter--;
    }
}

void Queue::clear()
{
    head = 0;
    tail = 0;
    counter = 0;
}

#endif
