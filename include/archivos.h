#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string>
#include <vector>
#include "proyecto.h"
using namespace std;

string quitarComillas(string texto);
void guardarCSV(vector<Proyecto> &proyectos, string nombreArchivo);
void cargarCSV(vector<Proyecto> &proyectos, string nombreArchivo);
void seedArchivoSiVacio(vector<Proyecto> &proyectos, string nombreArchivo);

#endif
