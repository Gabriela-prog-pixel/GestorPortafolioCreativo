#ifndef PROYECTO_H
#define PROYECTO_H

#include <string>
using namespace std;

struct Proyecto {
    string id;
    string nombre;
    string categoria; // branding, UX, ilustracion, video, web
    string cliente;
    int anio;
    float presupuesto;
    string estado; // en progreso, completado, pausado
};

#endif
