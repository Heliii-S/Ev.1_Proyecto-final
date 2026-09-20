/*
 * main.cpp
 *
 *  Creado en: 18/09/2026
 *  Autora: Tessa Heli Serrato Martínez
 */

#include <iostream>
#include <vector>
#include "carta.h"
#include "merge.h"

int main(){
	std::vector<Carta> coleccion;
	//cambiar cartas, agregar más, etc
	coleccion.push_back(Carta("Hulk", 6, 12, 65.0));
    coleccion.push_back(Carta("Iron Man", 5, 0, 70.0));
    coleccion.push_back(Carta("Ant-Man", 1, 1, 68.0));
    coleccion.push_back(Carta("Sunspot", 1, 5, 71.0));
	//
	std::cout << "COLECCION A ORDENAR" << std::endl;
	for (int i = 0; i < coleccion.size(); i++)
	{
		std::cout << coleccion[i].getNombre() << std::endl;
	}
	//
	Merge merge;
	merge.mergeDividirPoder(coleccion, 0, coleccion.size() - 1);
	std::cout << "ORDENADO POR PODER" << std::endl;
	for (int i = 0; i < coleccion.size(); i++)
	{
		std::cout << coleccion[i].getNombre() << " - Poder: " << coleccion[i].getPoder() << std::endl;
	}

	merge.mergeDividirCosto(coleccion, 0, coleccion.size() - 1);
	std::cout << "ORDENADO POR COSTO" << std::endl;
	for (int i = 0; i < coleccion.size(); i++)
	{
		std::cout << coleccion[i].getNombre() << " - Costo: " << coleccion[i].getCosto() << std::endl;
	}

	merge.mergeDividirVictoria(coleccion, 0, coleccion.size() - 1);
	std::cout << "ORDENADO POR TASA DE VICTORIA" << std::endl;
	for (int i = 0; i < coleccion.size(); i++)
	{
		std::cout << coleccion[i].getNombre() << " - Tasa de victoria: " << coleccion[i].getTasaVictoria() << std::endl;
	}
}