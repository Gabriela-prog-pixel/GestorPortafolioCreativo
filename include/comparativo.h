#ifndef COMPARATIVO_H
#define COMPARATIVO_H

#include <vector>
#include "proyecto.h"
using namespace std;

struct MetricasOrdenacion {
    int comparaciones;  // Cuántas veces comparó dos elementos
    int intercambios;   // Cuántas veces intercambió dos elementos
};

MetricasOrdenacion bubbleSortConMetricas(vector<Proyecto> proyectos);
MetricasOrdenacion intercalacionConMetricas(vector<Proyecto> v1, vector<Proyecto> v2);
void mostrarReporteComparativo(MetricasOrdenacion burbuja, MetricasOrdenacion intercalacion, int totalElementos);

#endif
