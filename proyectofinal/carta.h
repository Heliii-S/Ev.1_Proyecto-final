/*
 * carta.h
 *
 *  Creado en: 18/09/2026
 *  Autora: Tessa Heli Serrato Martínez
 */
#ifndef CARTA_H_
#define CARTA_H_
#include <string>

class Carta {
    private:
        std::string nombre;
        int costo;
        int poder;
        double tasaVictoria;
    public:
        Carta(std::string n, int c, int p, double t):nombre(n),costo(c),poder(p),tasaVictoria(t){};
        std::string getNombre();
        int getCosto();
        int getPoder();
        double getTasaVictoria();
};

std::string Carta::getNombre(){
    return nombre;
}

int Carta::getCosto(){
    return costo;
}

int Carta::getPoder(){
    return poder;
}

double Carta::getTasaVictoria(){
    return tasaVictoria;
}

#endif /* CARTA_H_ */