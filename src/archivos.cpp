#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "../include/archivos.h"
using namespace std;

string quitarComillas(string texto) {
    if (texto.length() >= 2 && texto[0] == '"' && texto[texto.length()-1] == '"') {
        return texto.substr(1, texto.length() - 2);
    }
    return texto;
}

void guardarCSV(vector<Proyecto> &proyectos, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo) {
        cout << "Error: no se pudo abrir el archivo para guardar." << endl;
        return;
    }
    for (int i = 0; i < proyectos.size(); i++) {
        archivo << "\"" << proyectos[i].id          << "\","
                << "\"" << proyectos[i].nombre       << "\","
                << "\"" << proyectos[i].categoria    << "\","
                << "\"" << proyectos[i].cliente      << "\","
                <<         proyectos[i].anio          << ","
                <<         proyectos[i].presupuesto   << ","
                << "\"" << proyectos[i].estado       << "\""
                << endl;
    }
    archivo.close();
}

void cargarCSV(vector<Proyecto> &proyectos, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo) {
        cout << "Aviso: no se encontró el archivo. Se creará al guardar." << endl;
        return;
    }
    proyectos.clear(); // Limpia el vector antes de cargar
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        string campo;
        Proyecto p;
        getline(ss, campo, ','); p.id          = quitarComillas(campo);
        getline(ss, campo, ','); p.nombre      = quitarComillas(campo);
        getline(ss, campo, ','); p.categoria   = quitarComillas(campo);
        getline(ss, campo, ','); p.cliente     = quitarComillas(campo);
        getline(ss, campo, ','); p.anio        = atoi(campo.c_str());
		getline(ss, campo, ','); p.presupuesto = atof(campo.c_str());
        getline(ss, campo, ','); p.estado      = quitarComillas(campo);
        proyectos.push_back(p);
    }
    archivo.close();
}

void seedArchivoSiVacio(vector<Proyecto> &proyectos, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    bool estaVacio = true;
    if (archivo) {
        string linea;
        if (getline(archivo, linea) && !linea.empty()) {
            estaVacio = false;
        }
        archivo.close();
    }

    if (!estaVacio) return;

    cout << "Archivo vacio detectado. Cargando registros de ejemplo..." << endl;

    Proyecto seed[10] = {
        {"001", "Logo Restaurante El Sabor", "branding", "Restaurante El Sabor", 2022, 1000, "completado"},
        {"003", "Cartel Festival de Cine", "ilustracion", "CineBolivia", 2024,  800, "completado"},
        {"005", "Cartel Festival de Cine 2", "ilustracion", "CineBolivia", 2024,  800, "completado"},
        {"007", "Manual de Marca Boutique", "branding", "Boutique Luna", 2024, 2100, "completado"},
        {"009", "Prototipo App Turismo", "UX", "BoliviaTour", 2020, 3800, "pausado"},
        {"011", "Video Corporativo ONG", "video", "FundaVida", 2026, 4270, "en_progreso"},
        {"013", "Ilustracion Libro Infantil", "ilustracion", "Editorial Arco Iris", 2023, 1500, "completado"},
        {"015", "Identidad Visual Cafeteria", "branding", "Cafe Central El Topo", 2025, 1850, "pausado"},
        {"017", "Landing Page Consultora", "web", "ConsultoraBP", 2022, 2630, "completado"},
        {"019", "Campana Visual Producto Leche", "branding", "Lacteos del Valle", 2024, 3100, "en_progreso"}
    };

    for (int i = 0; i < 10; i++) {
        proyectos.push_back(seed[i]);
    }

    guardarCSV(proyectos, nombreArchivo);
    cout << "10 registros de ejemplo cargados correctamente." << endl;
}
