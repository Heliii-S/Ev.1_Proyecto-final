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
        void mergePoder(std::vector<Carta>& cartas, int inicio, int mitad, int fin);
        void mergeCosto(std::vector<Carta>& cartas, int inicio, int mitad, int fin);
        void mergeVictoria(std::vector<Carta>& cartas, int inicio, int mitad, int fin);
    public:
        void mergeDividirPoder(std::vector<Carta>& cartas, int inicio, int fin);
        void mergeDividirCosto(std::vector<Carta>& cartas, int inicio, int fin);
        void mergeDividirVictoria(std::vector<Carta>& cartas, int inicio, int fin);
};

void Merge::mergeDividirPoder(std::vector<Carta>& cartas, int inicio, int fin)
{
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        mergeDividirPoder(cartas, inicio, mitad);
        mergeDividirPoder(cartas, mitad + 1, fin);
        mergePoder(cartas, inicio, mitad, fin);
    }
}

void Merge::mergePoder(std::vector<Carta>& cartas, int inicio, int mitad, int fin)
{
    int posicion_izquierda = inicio;
    int posicion_derecha = mitad + 1;
    std::vector<Carta> temporal;
    while (posicion_izquierda <= mitad && posicion_derecha <= fin)
    {
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

void Merge::mergeDividirCosto(std::vector<Carta>& cartas, int inicio, int fin)
{
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        mergeDividirCosto(cartas, inicio, mitad);
        mergeDividirCosto(cartas, mitad + 1, fin);
        mergeCosto(cartas, inicio, mitad, fin);
    }
}

void Merge::mergeCosto(std::vector<Carta>& cartas, int inicio, int mitad, int fin)
{
    int posicion_izquierda = inicio;
    int posicion_derecha = mitad + 1;
    std::vector<Carta> temporal;
    while (posicion_izquierda <= mitad && posicion_derecha <= fin)
    {
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

void Merge::mergeDividirVictoria(std::vector<Carta>& cartas, int inicio, int fin)
{
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        mergeDividirVictoria(cartas, inicio, mitad);
        mergeDividirVictoria(cartas, mitad + 1, fin);
        mergeVictoria(cartas, inicio, mitad, fin);
    }
}

void Merge::mergeVictoria(std::vector<Carta>& cartas, int inicio, int mitad, int fin)
{
    int posicion_izquierda = inicio;
    int posicion_derecha = mitad + 1;
    std::vector<Carta> temporal;
    while (posicion_izquierda <= mitad && posicion_derecha <= fin)
    {
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