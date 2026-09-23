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
	//colección actual de cartas
	coleccion.push_back(Carta("Absorbing Man", 4,5,59.2));
	coleccion.push_back(Carta("Chameleon",3,3,50));
	coleccion.push_back(Carta("Gambit",3,3,43.2));
	coleccion.push_back(Carta("Cyclops",3,5,66.9));
	coleccion.push_back(Carta("Nightcrawler",1,3,42.9));
	coleccion.push_back(Carta("Jeff the Baby Dolphin?!",2,2,50.8));
	coleccion.push_back(Carta("Hulk", 6, 12, 65.0));
    coleccion.push_back(Carta("Iron Man", 5, 0, 70.0));
    coleccion.push_back(Carta("Ant-Man", 1, 1, 68.0));
    coleccion.push_back(Carta("Sunspot", 1, 5, 71.0));
	coleccion.push_back(Carta("Quicksilver",1,2,67.1));
	coleccion.push_back(Carta("Rogue",3,3,65.1));
	coleccion.push_back(Carta("Spider-Man Brand New Day",1,2,50.6));
	coleccion.push_back(Carta("Kitty Pryde",1,1,48.6));
	coleccion.push_back(Carta("Black Cat",1,4,75));
	coleccion.push_back(Carta("Spider-Punk",3,3,38.5));
	coleccion.push_back(Carta("Multiple Man",2,4,55.6));
	coleccion.push_back(Carta("Cosmo",3,3,58.6));
	coleccion.push_back(Carta("Silk",2,5,54.9));
	coleccion.push_back(Carta("Friendly Neighborhood Carnage",3,4,50.0));
	//
	int r = 0, d;
	Merge merge;
	    do{	
		std::cout<<"\n1) Mostrar colección actual";
        std::cout<<"\n2) Ordenar por poder";
        std::cout<<"\n3) Ordenar por costo";
        std::cout<<"\n4) Ordenar por tasa de victoria";
        std::cout<<"\nELIGE LA OPCIÓN QUE DESEES REALIZAR: ";
        std::cin>>d;
        if (d == 1){
			std::cout << "COLECCION A ORDENAR" << std::endl;
			for (int i = 0; i < coleccion.size(); i++){
				std::cout << coleccion[i].getNombre() << std::endl;
			}
        }
        else if (d == 2){
			merge.mergeDividirPoder(coleccion, 0, coleccion.size() - 1);
			std::cout << "ORDENADO POR PODER" << std::endl;
			for (int i = 0; i < coleccion.size(); i++)
			{
				std::cout << coleccion[i].getNombre() << " - Poder: " << coleccion[i].getPoder() << std::endl;
			}
        }
        else if (d == 3){
			merge.mergeDividirCosto(coleccion, 0, coleccion.size() - 1);
			std::cout << "ORDENADO POR COSTO" << std::endl;
			for (int i = 0; i < coleccion.size(); i++)
			{
				std::cout << coleccion[i].getNombre() << " - Costo: " << coleccion[i].getCosto() << std::endl;
			}
        }
		else if (d == 4){
			merge.mergeDividirVictoria(coleccion, 0, coleccion.size() - 1);
			std::cout << "ORDENADO POR TASA DE VICTORIA" << std::endl;
			for (int i = 0; i < coleccion.size(); i++)
			{
				std::cout << coleccion[i].getNombre() << " - Tasa de victoria: " << coleccion[i].getTasaVictoria() << std::endl;
			}
		}
        else{
            std::cout<<"\nERROR: Opción incorrecta.";
			break;
        }
        std::cout<<"\n¿Quieres realizar otra acción? (0:Sí, 1:No) ";
        std::cin >> r;
    } while(r == 0);
}