#include <iostream>
#include <vector>
#include "../include/intercalacion.h"
#include "../include/archivos.h"
#include "../include/ordenacion.h"
using namespace std;

void intercalarArchivos(string nombreArchivo1, string nombreArchivo2, string nombreArchivoResultado) {

    // Carga los dos archivos en vectores separados
    vector<Proyecto> v1, v2, resultado;
    cargarCSV(v1, nombreArchivo1);
    cargarCSV(v2, nombreArchivo2);

    if (v1.empty() && v2.empty()) {
        cout << "Ambos archivos están vacíos. No hay nada que intercalar." << endl;
        return;
    }

	ordenarPorID(v1);
    ordenarPorID(v2);
    
    int i = 0, j = 0;

    // Compara elemento a elemento y agrega el menor al resultado
    while (i < v1.size() && j < v2.size()) {
        if (v1[i].id <= v2[j].id) {
            resultado.push_back(v1[i]);
            i++;
        } else {
            resultado.push_back(v2[j]);
            j++;
        }
    }

    // Si quedaron elementos en v1, los agrega al final
    while (i < v1.size()) {
        resultado.push_back(v1[i]);
        i++;
    }

    // Si quedaron elementos en v2, los agrega al final
    while (j < v2.size()) {
        resultado.push_back(v2[j]);
        j++;
    }

    guardarCSV(resultado, nombreArchivoResultado);
    cout << "Intercalación completada." << endl;
    cout << "Archivo generado: " << nombreArchivoResultado << endl;
    cout << "Total de proyectos: " << resultado.size() << endl;
}


