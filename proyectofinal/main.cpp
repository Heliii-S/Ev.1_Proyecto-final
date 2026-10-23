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
#include "queue.h"
#include "carga.h"

int main(){
	std::vector<Carta> coleccion_cartas;
	int r = 1, d;
	Merge merge;
	Carga coleccion_que_cargas;
	bool coleccionCargada = false;
	std::string nombreArchivo;
	    do{
		std::cout<<"\n3) Cargar una colección";	
		std::cout<<"\n4) Mostrar colección actual";
        std::cout<<"\n5) Ordenar por poder";
        std::cout<<"\n6) Ordenar por costo";
        std::cout<<"\n7) Ordenar por tasa de victoria";
		std::cout<<"\n8) Crear un mazo con altas tasas de victoria";
        std::cout<<"\nELIGE LA OPCIÓN QUE DESEES REALIZAR: ";
        std::cin>>d;
        if (d == 3)
		{
			std::cout << "Nombre del archivo (nombre.txt): ";
			std::cin >> nombreArchivo;
			if (coleccion_que_cargas.cargar(nombreArchivo, coleccion_cartas))
			{
				if (coleccion_cartas.empty()==false)
				{
					coleccionCargada = true;
					std::cout << "Coleccion cargada correctamente." << std::endl;
        		}
        		else
        		{
					coleccionCargada = false;
            		std::cout << "La coleccion esta vacia." << std::endl;
        		}
			}
			else
			{
        		coleccionCargada = false;
        		std::cout << "No se pudo abrir el archivo." << std::endl;
			}
		}
		else if(d == 4){
			if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion."<< std::endl;
			}
			else{
				std::cout << "\nCOLECCION A ORDENAR: " << std::endl;
				for (int i = 0; i < coleccion_cartas.size(); i++){
					std::cout << coleccion_cartas[i].getNombre() << std::endl;
				}
			}
        }
        else if (d == 5){
			if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion."<< std::endl;
			}
			else{
				merge.mergeDividir(coleccion_cartas, 0, coleccion_cartas.size() - 1, 1);
				std::cout << "\nCOLECCIÓN ORDENADA POR PODER: " << std::endl;
				for (int i = 0; i < coleccion_cartas.size(); i++)
				{
					std::cout << coleccion_cartas[i].getNombre() << " - Poder: " << coleccion_cartas[i].getPoder() << std::endl;
				}
			}
        }
        else if (d == 6){
			if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion."<< std::endl;
			}
			else{
				merge.mergeDividir(coleccion_cartas, 0, coleccion_cartas.size() - 1, 2);
				std::cout << "\nCOLECCIÓN ORDENADA POR COSTO: " << std::endl;
				for (int i = 0; i < coleccion_cartas.size(); i++)
				{
					std::cout << coleccion_cartas[i].getNombre() << " - Costo: " << coleccion_cartas[i].getCosto() << std::endl;
				}
			}
        }
		else if (d == 7){
			if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion."<< std::endl;
			}
			else{
				merge.mergeDividir(coleccion_cartas, 0, coleccion_cartas.size() - 1, 3);
				std::cout << "\nCOLECCIÓN ORDENADA POR TASA DE VICTORIA: " << std::endl;
				for (int i = 0; i < coleccion_cartas.size(); i++)
				{
					std::cout << coleccion_cartas[i].getNombre() << " - Tasa de victoria: " << coleccion_cartas[i].getTasaVictoria() << std::endl;
				}
			}
		}
        else if (d == 8){
			if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion."<< std::endl;
			}
			else
			{
				merge.mergeDividir(coleccion_cartas, 0, coleccion_cartas.size() - 1, 3);
				Queue mazo(12);
				for (int i = 0; i < 12; i++)
				{
					mazo.enqueue(coleccion_cartas[i]);
				}
				std::cout << "\nMAZO SUGERIDO SEGÚN LA COLECCIÓN ACTUAL: " << std::endl;
				while (mazo.empty()==false)
				{
					Carta actual = mazo.front();
					std::cout << actual.getNombre() << " - Tasa de victoria: " << actual.getTasaVictoria() << std::endl;
					mazo.dequeue();
				}
			}
		}
		else{
            std::cout<<"\nERROR: Opción incorrecta.";
			break;
        }
        std::cout<<"\n¿Quieres realizar otra acción? (1:Sí, 2:No) ";
        std::cin >> r;
    } while(r == 1);
}
