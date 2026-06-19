#ifndef CRUD_H
#define CRUD_H

#include <string>
#include <vector>
#include "proyecto.h"
using namespace std;

void listarProyectos(vector<Proyecto> &proyectos);
void crearProyecto(vector<Proyecto> &proyectos);
void modificarProyecto(vector<Proyecto> &proyectos);
void eliminarProyecto(vector<Proyecto> &proyectos);

#endif
