
#ifndef CARGA_H_
#define CARGA_H_

#include <fstream> //permite trabajar con archivos, en este caso leer el archivo .txt.
#include <string>
#include <vector>
#include "carta.h"
#include "queue.h"

class Carga
{
public:
    bool cargar(std::string nombreArchivo, std::vector<Carta>& cartas);
    void guardar(std::string nombreArchivo, std::vector<Carta>& porPoder, std::vector<Carta>& porCosto, std::vector<Carta>& porVictoria, Queue& mazo);
};

bool Carga::cargar(std::string nombreArchivo, std::vector<Carta>& cartas)
{
    std::ifstream archivo(nombreArchivo.c_str()); //intenta abrir un archivo para leerlo, c_str() va a convertir el nombre a una forma de texto que esta versión de ifstream acepta
    if (archivo.is_open()==false)
    {
        return false;
    }
    //cartas.clear() va a eliminar las cartas que teníamos anteriormente cargadas, para NO combinar colecciones
    cartas.clear();
    // creamos las variables que se van usar al momento de leer
    std::string nombre;
    int costo;
    int poder;
    double tasaVictoria;
    char coma;
    while (std::getline(archivo, nombre, ',')) //va leyendo hasta encontrar una coma y guarda en la sección correspondiente
    {
        archivo >> costo;
        archivo >> coma;
        archivo >> poder;
        archivo >> coma;
        archivo >> tasaVictoria;
        //ignora los caracteres restantes hasta encontrar un salto de línea
        archivo.ignore(1000, '\n');
        // Crea una nueva carta con los valores correspondientes
        Carta nueva(nombre, costo, poder, tasaVictoria);
        // agrega esa carta a la colección de cartas leídas
        cartas.push_back(nueva);
    }
    archivo.close();
    return true;
}

void Carga::guardar(std::string nombreArchivo, std::vector<Carta>& porPoder, std::vector<Carta>& porCosto, std::vector<Carta>& porVictoria, Queue& mazo)
{
    std::ofstream archivo(nombreArchivo.c_str());
    if (archivo.is_open())
    {
        archivo << "- RESULTADOS DEL ANALISIS -" << std::endl;
        archivo << "\n- COLECCION ORDENADA POR PODER - " << std::endl;
        // usa un ciclo for para obtener las cartas que están en el vector de ordenadas por poder
        for (int i = 0; i < porPoder.size(); i++)
        {
            archivo << porPoder[i].getNombre()
                    << " - Poder: " << porPoder[i].getPoder()
                    << std::endl;
        }
        archivo << "\n- COLECCION ORDENADA POR COSTO - " << std::endl;
        // usa un ciclo for para obtener las cartas que están en el vector de ordenadas por costo
        for (int i = 0; i < porCosto.size(); i++)
        {
            archivo << porCosto[i].getNombre()
                    << " - Costo: " << porCosto[i].getCosto()
                    << std::endl;
        }
        // usa un ciclo for para obtener las cartas que están en el vector de ordenadas por tasa de victoria
        archivo << "\nCOLECCION ORDENADA POR TASA DE VICTORIA:" << std::endl;
        for (int i = 0; i < porVictoria.size(); i++)
        {
            archivo << porVictoria[i].getNombre()
                    << " - Tasa de victoria: "
                    << porVictoria[i].getTasaVictoria()
                    << std::endl;
        }
        archivo << "\nMAZO RECOMENDADO:" << std::endl;
        if (mazo.empty() == false)
        {
            while (mazo.empty() == false){
                Carta actual = mazo.front();
                archivo << actual.getNombre()
                << " - Tasa de victoria: "
                << actual.getTasaVictoria()
                << std::endl;
                mazo.dequeue();
            }
        }
        else{
            archivo << "No hay cartas para mostrar." << std::endl;
        }
        archivo.close();
        std::cout << "Resultados guardados correctamente en "<< nombreArchivo << std::endl;
    }
    else
    {
        std::cout << "No se pudo crear el archivo." << std::endl;
    }
}

#endif

