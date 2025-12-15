#ifndef figuras
#define figuras

#include <vector>
#include <iostream>
#include <string>
#include <cmath>

class Punto{
    private: 
    int x;
    int y;

    public: 
    Punto();
    Punto(int x1, int y1);
    float get_distancia(Punto p);
        void imprimir();
};

class Poligono{
    private: 
    std::vector<Punto> pol;
    float get_perimetro();

    public:
    void imprimir();
    void añadir_punto();

};

#endif