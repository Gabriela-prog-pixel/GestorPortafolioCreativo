#include <iostream>
#include <vector>
#include "../include/ordenacion.h"
#include "../include/archivos.h"
using namespace std;

// Bubble Sort optimizado
void ordenarPorID(vector<Proyecto> &proyectos) {
    if (proyectos.empty()) {
        cout << "No hay proyectos para ordenar." << endl;
        return;
    }

    int n = proyectos.size();
    bool huboIntercambio;

    for (int i = 0; i < n - 1; i++) {
        huboIntercambio = false;

        for (int j = 0; j < n - 1 - i; j++) {
            // Compara los IDs de dos proyectos adyacentes
            if (proyectos[j].id > proyectos[j + 1].id) {
                // Intercambia los proyectos completos (structs)
                Proyecto aux    = proyectos[j];
                proyectos[j]    = proyectos[j + 1];
                proyectos[j + 1] = aux;
                huboIntercambio = true;
            }
        }
        // Si no hubo ningún intercambio, el vector ya está ordenado
        if (!huboIntercambio) break;
    }

    cout << "Proyectos ordenados por ID correctamente." << endl;
}


