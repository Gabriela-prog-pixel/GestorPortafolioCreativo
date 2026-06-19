#include <iostream>
#include <vector>
#include "include/proyecto.h"
#include "include/archivos.h"
#include "include/crud.h"
#include "include/ordenacion.h"
#include "include/busqueda.h"
#include "include/intercalacion.h"
#include "include/utilidades.h"
#include "include/comparativo.h"
#include "include/binario.h"
using namespace std;

int main() {
    vector<Proyecto> proyectos;
    seedArchivoSiVacio(proyectos, "data/portafolio.csv");
    cargarCSV(proyectos, "data/portafolio.csv");
    
    int opcion;

    // Carga los proyectos del CSV al iniciar el programa
    cargarCSV(proyectos, "data/portafolio.csv");

    do {
        limpiarPantalla();
        opcion = mostrarMenu();

        if (!opcionValida(opcion, 0, 12)) {
            cout << "Opción no válida. Intente de nuevo." << endl;
            pausar();
            continue;
        }

        switch (opcion) {
            case 1:
                limpiarPantalla();
                listarProyectos(proyectos);
                pausar();
                break;

            case 2:
                limpiarPantalla();
                crearProyecto(proyectos);
                pausar();
                break;

            case 3:
                limpiarPantalla();
                modificarProyecto(proyectos);
                pausar();
                break;

            case 4:
                limpiarPantalla();
                eliminarProyecto(proyectos);
                pausar();
                break;

            case 5:
                limpiarPantalla();
                ordenarPorID(proyectos);
                guardarCSV(proyectos, "data/portafolio.csv");
                pausar();
                break;

            case 6: {
    			limpiarPantalla();
    			cout << "Ingrese el ID a buscar: ";
    			string idBuscado;
    			cin >> idBuscado;
    			cout << "-- Busqueda Secuencial --" << endl;
    			mostrarResultadoBusqueda(proyectos, busquedaSecuencial(proyectos, idBuscado));
    			pausar();
			    break;
			}

            case 7: {
    			limpiarPantalla();
    			cout << "AVISO: requiere proyectos ordenados (opcion 5)." << endl;
    			cout << "Ingrese el ID a buscar: ";
    			string idBuscado2;
    			cin >> idBuscado2;
    			cout << "-- Busqueda Binaria Iterativa --" << endl;
    			mostrarResultadoBusqueda(proyectos, busquedaBinaria(proyectos, idBuscado2));
    			pausar();
    			break;
			}

            case 8:
                limpiarPantalla();
                cout << "AVISO: Ambos archivos deben estar ordenados por ID." << endl;
                intercalarArchivos("data/portafolio.csv", "data/portafolio2.csv","data/resultado.csv");
                pausar();
                break;

			case 9: {
	    		limpiarPantalla();
			    // Carga el segundo portafolio para la comparación
			    vector<Proyecto> portafolio2;
			    cargarCSV(portafolio2, "data/portafolio2.csv");
			    MetricasOrdenacion mBurbuja = bubbleSortConMetricas(proyectos);
			    MetricasOrdenacion mIntercalacion = intercalacionConMetricas(proyectos, portafolio2);
			    mostrarReporteComparativo(mBurbuja, mIntercalacion, proyectos.size() + portafolio2.size());
			    pausar();
			    break;
			}
			
			case 10: {
			    limpiarPantalla();
			    cout << "AVISO: requiere proyectos ordenados (opcion 5)." << endl;
			    cout << "Ingrese el ID a buscar: ";
			    string idBuscado3;
			    cin >> idBuscado3;
			    cout << "-- Busqueda Binaria Recursiva --" << endl;
			    mostrarResultadoBusqueda(proyectos, busquedaBinariaRecursiva(proyectos, idBuscado3));
			    pausar();
			    break;
			}
			
			case 11: {
			    limpiarPantalla();
			    guardarBinario(proyectos, "data/portafolio.dat");
			    pausar();
			    break;
			}
			
			case 12: {
			    limpiarPantalla();
			    generarReporteTXT(proyectos, "data/reporte_portafolio.txt");
			    pausar();
			    break;
			}

            case 0:
                limpiarPantalla();
                cout << "Saliendo del sistema. Hasta luego." << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}
