#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "../include/binario.h"
using namespace std;

ProyectoBinario convertirABinario(Proyecto p) {
    ProyectoBinario pb;
    // Limpiar los arreglos primero
    memset(&pb, 0, sizeof(ProyectoBinario));
    strncpy(pb.id,        p.id.c_str(),        9);
    strncpy(pb.nombre,    p.nombre.c_str(),    99);
    strncpy(pb.categoria, p.categoria.c_str(), 29);
    strncpy(pb.cliente,   p.cliente.c_str(),   99);
    pb.anio        = p.anio;
    pb.presupuesto = p.presupuesto;
    strncpy(pb.estado,    p.estado.c_str(),    19);
    return pb;
}

Proyecto convertirDesBinario(ProyectoBinario pb) {
    Proyecto p;
    p.id          = string(pb.id);
    p.nombre      = string(pb.nombre);
    p.categoria   = string(pb.categoria);
    p.cliente     = string(pb.cliente);
    p.anio        = pb.anio;
    p.presupuesto = pb.presupuesto;
    p.estado      = string(pb.estado);
    return p;
}

void guardarBinario(vector<Proyecto> &proyectos, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str(), ios::binary);
    if (!archivo) {
        cout << "Error: no se pudo abrir el archivo binario para guardar." << endl;
        return;
    }
    for (int i = 0; i < proyectos.size(); i++) {
        ProyectoBinario pb = convertirABinario(proyectos[i]);
        archivo.write(reinterpret_cast<char*>(&pb), sizeof(ProyectoBinario));
    }
    archivo.close();
    cout << "Datos guardados en archivo binario correctamente." << endl;
}

void cargarBinario(vector<Proyecto> &proyectos, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str(), ios::binary);
    if (!archivo) {
        cout << "Aviso: no se encontro el archivo binario." << endl;
        return;
    }
    proyectos.clear();
    ProyectoBinario pb;
    while (archivo.read(reinterpret_cast<char*>(&pb), sizeof(ProyectoBinario))) {
        proyectos.push_back(convertirDesBinario(pb));
    }
    archivo.close();
    cout << "Datos cargados desde archivo binario correctamente." << endl;
}

void generarReporteTXT(vector<Proyecto> &proyectos, string nombreArchivo) {
    ofstream reporte(nombreArchivo.c_str());
    if (!reporte) {
        cout << "Error: no se pudo crear el reporte." << endl;
        return;
    }

    reporte << "========================================" << endl;
    reporte << "   REPORTE DE PORTAFOLIO DE PROYECTOS   " << endl;
    reporte << "========================================" << endl;
    reporte << "Total de proyectos: " << proyectos.size() << endl;
    reporte << "----------------------------------------" << endl;

    for (int i = 0; i < proyectos.size(); i++) {
        reporte << "Proyecto #" << (i + 1) << endl;
        reporte << "  ID          : " << proyectos[i].id          << endl;
        reporte << "  Nombre      : " << proyectos[i].nombre      << endl;
        reporte << "  Categoria   : " << proyectos[i].categoria   << endl;
        reporte << "  Cliente     : " << proyectos[i].cliente     << endl;
        reporte << "  Anio        : " << proyectos[i].anio        << endl;
        reporte << "  Presupuesto : " << proyectos[i].presupuesto << " Bs." << endl;
        reporte << "  Estado      : " << proyectos[i].estado      << endl;
        reporte << "----------------------------------------" << endl;
    }

    reporte.close();
    cout << "Reporte generado: " << nombreArchivo << endl;
}
