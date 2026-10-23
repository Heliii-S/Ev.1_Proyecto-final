
#ifndef CARGA_H_
#define CARGA_H_

#include <fstream> //permite trabajar con archivos, en este caso leer el archivo .txt.
#include <string>
#include <vector>
#include "carta.h"

class Carga
{
public:
    bool cargar(std::string nombreArchivo, std::vector<Carta>& cartas);
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
#endif

