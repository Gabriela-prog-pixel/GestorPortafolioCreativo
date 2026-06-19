#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <string>
#include <vector>
#include "proyecto.h"
using namespace std;

struct ResultadoBusqueda {
    int posicion;       // Índice donde se encontró
    int comparaciones;  // Cuántas comparaciones hizo el algoritmo
};

ResultadoBusqueda busquedaSecuencial(vector<Proyecto> &proyectos, string idBuscado);
ResultadoBusqueda busquedaBinaria(vector<Proyecto> &proyectos, string idBuscado);
ResultadoBusqueda busquedaBinariaRecursiva(vector<Proyecto> &proyectos, string idBuscado);
void mostrarResultadoBusqueda(vector<Proyecto> &proyectos, ResultadoBusqueda resultado);

#endif
