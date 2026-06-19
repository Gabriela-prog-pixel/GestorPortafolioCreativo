#ifndef BINARIO_H
#define BINARIO_H

#include <string>
#include <vector>
#include "proyecto.h"
using namespace std;

// Se usa char[] en lugar de string porque el binario necesita tamaño fijo
struct ProyectoBinario {
    char id[10];
    char nombre[100];
    char categoria[30];
    char cliente[100];
    int  anio;
    float presupuesto;
    char estado[20];
};

ProyectoBinario convertirABinario(Proyecto p);
Proyecto convertirDesBinario(ProyectoBinario pb);
void guardarBinario(vector<Proyecto> &proyectos, string nombreArchivo);
void cargarBinario(vector<Proyecto> &proyectos, string nombreArchivo);
void generarReporteTXT(vector<Proyecto> &proyectos, string nombreArchivo);

#endif
