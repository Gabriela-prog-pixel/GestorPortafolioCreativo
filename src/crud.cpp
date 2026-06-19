#include <iostream>
#include <vector>
#include <limits>
#include "../include/crud.h"
#include "../include/archivos.h"
using namespace std;

void listarProyectos(vector<Proyecto> &proyectos) {
    if (proyectos.empty()) {
        cout << "No hay proyectos registrados." << endl;
        return;
    }
    cout << "==========================================" << endl;
    cout << "        LISTADO DE PROYECTOS              " << endl;
    cout << "==========================================" << endl;
    for (int i = 0; i < proyectos.size(); i++) {
        cout << "ID          : " << proyectos[i].id          << endl;
        cout << "Nombre      : " << proyectos[i].nombre      << endl;
        cout << "Categoría   : " << proyectos[i].categoria   << endl;
        cout << "Cliente     : " << proyectos[i].cliente     << endl;
        cout << "Año         : " << proyectos[i].anio        << endl;
        cout << "Presupuesto : " << proyectos[i].presupuesto << " Bs." << endl;
        cout << "Estado      : " << proyectos[i].estado      << endl;
        cout << "------------------------------------------" << endl;
    }
}

void crearProyecto(vector<Proyecto> &proyectos) {
    Proyecto p;
    cout << "========== NUEVO PROYECTO ==========" << endl;

    cout << "ID          : "; cin >> p.id;
    cin.ignore(); // Limpia el buffer antes de usar getline

    cout << "Nombre      : "; getline(cin, p.nombre);
    
    cout << "Categoría (branding/UX/ilustracion/video/web): ";
    getline(cin, p.categoria);
    
    cout << "Cliente     : "; getline(cin, p.cliente);
    
    cout << "Año         : "; cin >> p.anio;
    
    cout << "Presupuesto : "; cin >> p.presupuesto;
    cin.ignore();
    
    cout << "Estado (en_progreso/completado/pausado): ";
    getline(cin, p.estado);

    proyectos.push_back(p);
    guardarCSV(proyectos, "data/portafolio.csv");
    cout << "Proyecto guardado correctamente." << endl;
}

void modificarProyecto(vector<Proyecto> &proyectos) {
    string idBuscado;
    cout << "Ingrese el ID del proyecto a modificar: ";
    cin >> idBuscado;
    cin.ignore();

    for (int i = 0; i < proyectos.size(); i++) {
        if (proyectos[i].id == idBuscado) {
            cout << "Proyecto encontrado. Ingrese los nuevos datos:" << endl;

            cout << "Nombre      : "; getline(cin, proyectos[i].nombre);
            
            cout << "Categoría (branding/UX/ilustracion/video/web): ";
            getline(cin, proyectos[i].categoria);
            
            cout << "Cliente     : "; getline(cin, proyectos[i].cliente);
            
            cout << "Año         : "; cin >> proyectos[i].anio;
            
            cout << "Presupuesto : "; cin >> proyectos[i].presupuesto;
            cin.ignore();
            
            cout << "Estado (en_progreso/completado/pausado): ";
            getline(cin, proyectos[i].estado);

            guardarCSV(proyectos, "data/portafolio.csv");
            cout << "Proyecto modificado correctamente." << endl;
            return;
        }
    }
    cout << "No se encontró un proyecto con ID: " << idBuscado << endl;
}

void eliminarProyecto(vector<Proyecto> &proyectos) {
    string idBuscado;
    cout << "Ingrese el ID del proyecto a eliminar: ";
    cin >> idBuscado;
    cin.ignore();

    for (int i = 0; i < proyectos.size(); i++) {
        if (proyectos[i].id == idBuscado) {
            proyectos.erase(proyectos.begin() + i);
            guardarCSV(proyectos, "data/portafolio.csv");
            cout << "Proyecto eliminado correctamente." << endl;
            return;
        }
    }
    cout << "No se encontró un proyecto con ID: " << idBuscado << endl;
}
