#include <iostream>
#include <vector>
#include "../include/busqueda.h"
using namespace std;

ResultadoBusqueda busquedaRecursivaAux(vector<Proyecto> &proyectos, string idBuscado, int inicio, int fin, int &comparaciones) {
    ResultadoBusqueda res;
    res.posicion = -1;
    res.comparaciones = comparaciones;

    if (inicio > fin) {
        return res;
    }

    int medio = inicio + (fin - inicio) / 2;
    comparaciones++;
    res.comparaciones = comparaciones;

    if (proyectos[medio].id == idBuscado) {
        res.posicion = medio;
        return res;
    }
    else if (proyectos[medio].id > idBuscado) {
        // Busca en la mitad izquierda
        return busquedaRecursivaAux(proyectos, idBuscado, inicio, medio - 1, comparaciones);
    }
    else {
        // Busca en la mitad derecha
        return busquedaRecursivaAux(proyectos, idBuscado, medio + 1, fin, comparaciones);
    }
}

// Recorre el vector uno por uno
ResultadoBusqueda busquedaSecuencial(vector<Proyecto> &proyectos, string idBuscado) {
    ResultadoBusqueda res;
    res.posicion = -1;
    res.comparaciones = 0;

    for (int i = 0; i < proyectos.size(); i++) {
        res.comparaciones++;
        if (proyectos[i].id == idBuscado) {
            res.posicion = i;
            return res;
        }
    }
    return res;
}

// Divide el vector a la mitad en cada paso (iterativa)
ResultadoBusqueda busquedaBinaria(vector<Proyecto> &proyectos, string idBuscado) {
    ResultadoBusqueda res;
    res.posicion = -1;
    res.comparaciones = 0;

    int inicio = 0;
    int fin = proyectos.size() - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        res.comparaciones++;

        if (proyectos[medio].id == idBuscado) {
            res.posicion = medio;
            return res;
        }
        else if (proyectos[medio].id > idBuscado) {
            fin = medio - 1;
        }
        else {
            inicio = medio + 1;
        }
    }
    return res;
}

// Divide el vector a la mitad en cada paso (recursiva)
ResultadoBusqueda busquedaBinariaRecursiva(vector<Proyecto> &proyectos, string idBuscado) {
    int comparaciones = 0;
    return busquedaRecursivaAux(proyectos, idBuscado, 0, proyectos.size() - 1, comparaciones);
}

void mostrarResultadoBusqueda(vector<Proyecto> &proyectos, ResultadoBusqueda resultado) {
    cout << "Comparaciones realizadas: " << resultado.comparaciones << endl;
    if (resultado.posicion == -1) {
        cout << "No se encontro ningun proyecto con ese ID." << endl;
        return;
    }
    int pos = resultado.posicion;
    cout << "========== PROYECTO ENCONTRADO ==========" << endl;
    cout << "ID          : " << proyectos[pos].id          << endl;
    cout << "Nombre      : " << proyectos[pos].nombre      << endl;
    cout << "Categoria   : " << proyectos[pos].categoria   << endl;
    cout << "Cliente     : " << proyectos[pos].cliente     << endl;
    cout << "Anio        : " << proyectos[pos].anio        << endl;
    cout << "Presupuesto : " << proyectos[pos].presupuesto << " Bs." << endl;
    cout << "Estado      : " << proyectos[pos].estado      << endl;
    cout << "==========================================" << endl;
}
