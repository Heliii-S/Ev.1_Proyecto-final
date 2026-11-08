/*
 * main.cpp
 *
 *  Creado en: 18/09/2026
 *  Autora: Tessa Heli Serrato Martínez
 */

#include <iostream>
#include <vector>
// para poder generar números aleatorios
#include <cstdlib>
#include <string>
#include "carta.h"
#include "merge.h"
#include "queue.h"
#include "carga.h"

void simularPartida(std::vector<Carta> mazoElegido){
	Queue mazo_sim;
	std::vector<Carta> mano_jugador;
	// Mezclar las cartas de forma aleatoria
	// mientras se sigan teniendo "cartas" en el vector seguimos mezclando
	while (mazoElegido.size() > 0){
		// rand va a crear un número pesudoaleatorio y %mazoElegido.size hace que sea una pos válidad del vector
        int posicion = rand() % mazoElegido.size();
		// se agrega a la fila la carta seleccionada
		mazo_sim.enqueue(mazoElegido[posicion]);
		// y eliminamos del vector la carta seleccionada
		mazoElegido.erase(mazoElegido.begin() + posicion);
	}
	// Entregar las primeras tres cartas
	for (int i = 0; i < 3; i++){
		// en cada repetición se obtiene la primera carta de la cola y se agrega a la "mano" del jugador
		mano_jugador.push_back(mazo_sim.front());
		//luego se elimina esa carta de la cola
		mazo_sim.dequeue();
	}
	// Comienzan los seis turnos
	for (int turno = 1; turno <= 6; turno++){
		// Antes de cada turno, se comprueban 2 condiciones, para darte una carta nueva por turno
		//Tal y como pasa en el juego..
		if (turno <= 6 && mazo_sim.empty() == false){
			if (mano_jugador.size() < 7){
				// si estamos en un turno válido y tenemos cartas..
				Carta nueva = mazo_sim.front();
				mano_jugador.push_back(nueva);
				mazo_sim.dequeue();
				std::cout << "\n¡Nueva carta: "<< nueva.getNombre() << "!" <<std::endl;
			}
			else{
				std::cout << "Tienes 7 cartas. No recibiras mas cartas hasta que juegues alguna." << std::endl;
			}
		}
		std::cout << "\n--- TURNO " << turno << " ---" << std::endl;
		std::cout << "\nTus cartas disponibles:" << std::endl;
		for (int i = 0; i < mano_jugador.size(); i++){
			//empieza en 0 pero le sumamos 1 para que las opciones sean:1,2,3 y no 0,1,2
			std::cout << i + 1 << ") "
			<< mano_jugador[i].getNombre()
            << " - Costo: " << mano_jugador[i].getCosto()
            << " - Poder: " << mano_jugador[i].getPoder()
            << std::endl;
		}
		int opcion;
		// y le preguntamos al usuario que quiere hacer.. ya sea elegir una carta, pasar, o salir de la simulación
		std::cout<< "\nElige una carta para jugar (0 para pasar) (8 para salir de la simulación): ";
		std::cin>> opcion;
		//con este while comprobamos que se haya elegido una opción válida
		while (opcion < 0 || (opcion > mano_jugador.size() && opcion != 8)){
			std::cout << "Opcion incorrecta. Intenta nuevamente: ";
			// si la opción ingresada es inválida, pedimos que se ingrese otra
			std::cin >> opcion;
		}
		// esta condición es para salir de la simulación, se usa un break
		if (opcion == 8){
			break;
		}
		// con esta condición se indica que no quisimos hacer nada este turno
		if (opcion == 0){
            std::cout << "\n Decidiste pasar este turno..." << std::endl;
		}
		// si se escogió alguna de las cartas..
		else{
			//le decimos al jugador cuál carta eligió
			std::cout << "Jugaste: " << mano_jugador[opcion - 1].getNombre() << std::endl;
			// y borramos esa opción de su mano, le restamos 1 a opción en ambos casos
			//porque el jugador escogió las cartas empezando desde 1, pero el vector inicia en 0
			// así que le damos el valor correcto, ya que cambiamos los valores para mayor claridad
			//como se explicó arriba
			mano_jugador.erase(mano_jugador.begin() + opcion - 1);
		}
	}
	std::cout << "\nFin de la simulacion." << std::endl;
}

int main(){
	std::vector<Carta> coleccion_cartas;
	int r = 1, d;
	Merge merge;
	Carga coleccion_que_cargas;
	bool coleccionCargada = false;
	std::string nombreArchivo;
	//para poder generar distintos números aleatorios
	// establecemos la "semilla" que determina la secuencia de números que generará rand()
	//en la función de simular partida
	srand(10);
	do{
		std::cout<<"\n3) Cargar una colección";	
		std::cout<<"\n4) Mostrar colección actual";
        std::cout<<"\n5) Ordenar por poder";
        std::cout<<"\n6) Ordenar por costo";
        std::cout<<"\n7) Ordenar por tasa de victoria";
		std::cout<<"\n8) Crear un mazo con altas tasas de victoria";
		std::cout<<"\n9) Simular una partida con el mazo recomendado";
		std::cout<<"\n10) Exportar resultados del análisis";
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
			else if (coleccion_cartas.size() < 12){
				std::cout << "Se necesitan al menos 12 cartas para crear un mazo." << std::endl;
			}
			else
			{
				merge.mergeDividir(coleccion_cartas, 0, coleccion_cartas.size() - 1, 3);
				Queue mazo_sugerido;
				for (int i = 0; i < 12; i++)
				{
					mazo_sugerido.enqueue(coleccion_cartas[i]);
				}
				std::cout << "\nMAZO SUGERIDO SEGÚN LA COLECCIÓN ACTUAL: " << std::endl;
				while (mazo_sugerido.empty()==false)
				{
					Carta actual = mazo_sugerido.front();
					std::cout << actual.getNombre() << " - Tasa de victoria: " << actual.getTasaVictoria() << std::endl;
					mazo_sugerido.dequeue();
				}
			}
		}
		else if (d == 9){
			if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion." << std::endl;
			}
			else if (coleccion_cartas.size() < 12){
				std::cout << "Se necesitan al menos 12 cartas." << std::endl;
			}
			//ordenamos las cartas por orden de tasa de victoria para generar un mazo sugerido
			else{
				merge.mergeDividir(coleccion_cartas, 0 ,coleccion_cartas.size() - 1, 3);
				std::vector<Carta> mazoElegido;
				for (int i = 0; i < 12; i++){
					mazoElegido.push_back(coleccion_cartas[i]);
				}
				simularPartida(mazoElegido);
			}
		}
		else if (d == 10)
		{
    		if (coleccionCargada == false){
				std::cout << "Primero debes cargar una coleccion." << std::endl;
			}
			else{
			// se hacen copias de la coleccion original para ordenarlas
			std::vector<Carta> porPoder = coleccion_cartas;
			std::vector<Carta> porCosto = coleccion_cartas;
			std::vector<Carta> porVictoria = coleccion_cartas;
			merge.mergeDividir(porPoder, 0, porPoder.size() - 1, 1);
			merge.mergeDividir(porCosto, 0, porCosto.size() - 1, 2);
			merge.mergeDividir(porVictoria, 0, porVictoria.size() - 1, 3);
			Queue mazo;
			for (int i = 0; i < 12; i++){
				mazo.enqueue(porVictoria[i]);
			}
			coleccion_que_cargas.guardar("resultados.txt",porPoder,porCosto,porVictoria,mazo);
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
