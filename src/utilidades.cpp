#include <iostream>
#include <limits>
#include "../include/utilidades.h"
using namespace std;

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int mostrarMenu() {
    int opcion;
    cout << endl;
    cout << "==========================================" << endl;
    cout << "            GESTOR DE PORTAFOLIO         " << endl;
    cout << "==========================================" << endl;
    cout << "  1. Listar proyectos                     " << endl;
    cout << "  2. Agregar proyecto                     " << endl;
    cout << "  3. Modificar proyecto                   " << endl;
    cout << "  4. Eliminar proyecto                    " << endl;
    cout << "  5. Ordenar proyectos por ID             " << endl;
    cout << "  6. Busqueda secuencial por ID           " << endl;
    cout << "  7. Busqueda binaria por ID              " << endl;
    cout << "  8. Intercalar con segundo portafolio    " << endl;
    cout << "  9. Reporte comparativo de algoritmos    " << endl;
    cout << " 10. Busqueda binaria recursiva           " << endl;
    cout << " 11. Guardar copia en archivo binario     " << endl;
	cout << " 12. Generar reporte TXT                  " << endl;
    cout << "  0. Salir                                " << endl;
    cout << "==========================================" << endl;
    cout << "  Opcion: ";
    cin >> opcion;
    return opcion;
}

bool opcionValida(int opcion, int min, int max) {
    return (opcion >= min && opcion <= max);
}
