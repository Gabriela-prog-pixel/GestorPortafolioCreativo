#include <iostream>
#include <vector>
#include "../include/comparativo.h"
#include "../include/ordenacion.h"
using namespace std;

// Bubble Sort que cuenta sin modificar el original - Recibe el vector por valor
MetricasOrdenacion bubbleSortConMetricas(vector<Proyecto> proyectos) {
    MetricasOrdenacion m;
    m.comparaciones = 0;
    m.intercambios  = 0;

    int n = proyectos.size();
    bool huboIntercambio;

    for (int i = 0; i < n - 1; i++) {
        huboIntercambio = false;
        for (int j = 0; j < n - 1 - i; j++) {
            m.comparaciones++;
            if (proyectos[j].id > proyectos[j + 1].id) {
                Proyecto aux     = proyectos[j];
                proyectos[j]     = proyectos[j + 1];
                proyectos[j + 1] = aux;
                m.intercambios++;
                huboIntercambio = true;
            }
        }
        if (!huboIntercambio) break;
    }
    return m;
}

// Intercalación que cuenta comparaciones entre elementos de ambos vectores
MetricasOrdenacion intercalacionConMetricas(vector<Proyecto> v1, vector<Proyecto> v2) {
    MetricasOrdenacion m;
    m.comparaciones = 0;
    m.intercambios  = 0; // La intercalación no hace intercambios, solo inserciones

    ordenarPorID(v1);
    ordenarPorID(v2);

    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        m.comparaciones++;
        if (v1[i].id <= v2[j].id) {
            i++;
        } else {
            j++;
        }
    }
    return m;
}

void mostrarReporteComparativo(MetricasOrdenacion burbuja, MetricasOrdenacion intercalacion, int totalElementos) {
    cout << "========================================" << endl;
    cout << "           Reporte Comparativo          " << endl;
    cout << "========================================" << endl;
    cout << "Total de elementos analizados: " << totalElementos << endl;
    cout << "----------------------------------------" << endl;
    cout << "  BUBBLE SORT:" << endl;
    cout << "    Comparaciones : " << burbuja.comparaciones << endl;
    cout << "    Intercambios  : " << burbuja.intercambios  << endl;
    cout << "----------------------------------------" << endl;
    cout << "  INTERCALACION:" << endl;
    cout << "    Comparaciones : " << intercalacion.comparaciones << endl;
    cout << "    Intercambios  : 0 (no aplica)"        << endl;
    cout << "----------------------------------------" << endl;

    // Conclusión automática
    if (burbuja.comparaciones > intercalacion.comparaciones) {
        cout << "  Resultado: Intercalacion hizo menos comparaciones." << endl;
    } else {
        cout << "  Resultado: Bubble Sort hizo menos comparaciones." << endl;
    }
    cout << "========================================" << endl;
}
