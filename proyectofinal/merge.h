/*
 * merge.h
 *
 *  Creado en: 18/09/2026
 *  Autora: Tessa Heli Serrato Martínez
 */
#ifndef MERGE_H_
#define MERGE_H_
#include <vector>
#include "carta.h"

class Merge
{
    private:
        void merge(std::vector<Carta>& cartas, int inicio, int mitad, int fin, int criterio);
    public:
        void mergeDividir(std::vector<Carta>& cartas, int inicio, int fin, int criterio);
};


void Merge::mergeDividir(std::vector<Carta>& cartas, int inicio, int fin, int criterio)
{
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        mergeDividir(cartas, inicio, mitad, criterio);
        mergeDividir(cartas, mitad + 1, fin, criterio);
        merge(cartas, inicio, mitad, fin, criterio);
    }
}

void Merge::merge(std::vector<Carta>& cartas, int inicio, int mitad, int fin, int criterio)
{
    int posicion_izquierda = inicio;
    int posicion_derecha = mitad + 1;

    std::vector<Carta> temporal;
    
    while (posicion_izquierda <= mitad && posicion_derecha <= fin)
    {
        if(criterio == 1){
            if (cartas[posicion_izquierda].getPoder() >= cartas[posicion_derecha].getPoder())
            {
                temporal.push_back(cartas[posicion_izquierda]);
                posicion_izquierda++;
            }
            else
            {
                temporal.push_back(cartas[posicion_derecha]);
                posicion_derecha++;
            }
        }
        else if(criterio == 2){
            if (cartas[posicion_izquierda].getCosto() <= cartas[posicion_derecha].getCosto())
            {
                temporal.push_back(cartas[posicion_izquierda]);
                posicion_izquierda++;
            }
            else
            {
                temporal.push_back(cartas[posicion_derecha]);
                posicion_derecha++;
            }
        }
        else{
            if (cartas[posicion_izquierda].getTasaVictoria() >= cartas[posicion_derecha].getTasaVictoria())
            {
                temporal.push_back(cartas[posicion_izquierda]);
                posicion_izquierda++;
            }
            else
            {
                temporal.push_back(cartas[posicion_derecha]);
                posicion_derecha++;
            }
        }
    }

    while (posicion_izquierda <= mitad)
    {
        temporal.push_back(cartas[posicion_izquierda]);
        posicion_izquierda++;
    }

    while (posicion_derecha <= fin)
    {
        temporal.push_back(cartas[posicion_derecha]);       
        posicion_derecha++;
    }

    for (int i = 0; i < temporal.size(); i++)
    {
        cartas[inicio + i] = temporal[i];
    }
}

#endif /* MERGE_H_ */