# Gestor de Portafolio de Proyectos Creativos

Sistema de gestión desarrollado en C++ para la asignatura **Programación I (SIS-112)**.  
Carrera: Comunicación Digital y Multimedia — Gestión 1/2026.  
Integrantes: Gabriela Cárdenas Chipana y Rosa Llanos Vargas

---

## Descripción

Sistema que permite a un comunicador digital gestionar sus proyectos creativos:
registrarlos, buscarlos, ordenarlos e intercalar portafolios, con persistencia en archivos CSV y binarios.

## Entidad principal

**struct Proyecto** con 7 campos:

| Campo | Tipo | Descripción |
|---|---|---|
| id | string | Identificador único (ej: "001") |
| nombre | string | Nombre del proyecto |
| categoria | string | branding / UX / ilustracion / video / web |
| cliente | string | Nombre del cliente |
| anio | int | Año de realización |
| presupuesto | float | Monto en bolivianos |
| estado | string | completado / en_progreso / pausado |

---

## Estructura del proyecto

```
GestorPortafolioCreativo/
├── include/          → Archivos de cabecera (.h)
├── src/              → Implementaciones (.cpp)
├── data/             → Archivos de datos (.csv, .dat)
├── main.cpp          → Punto de entrada
└── .gitignore
```

---

## Módulos

| Módulo | Responsabilidad |
|---|---|
| proyecto.h | Define el struct Proyecto |
| archivos | Leer y escribir archivos CSV |
| crud | Crear, listar, modificar, eliminar |
| ordenacion | Bubble Sort optimizado con bandera |
| busqueda | Búsqueda secuencial, binaria iterativa y recursiva |
| intercalacion | Fusión de dos archivos ordenados |
| comparativo | Reporte comparativo de algoritmos |
| binario | Generación de reporte de datos y extracción de datos en un archivo .dat |
| utilidades | Menú, pausar, limpiar pantalla |

---

## Menú del sistema

```
1.  Listar proyectos
2.  Agregar proyecto
3.  Modificar proyecto
4.  Eliminar proyecto
5.  Ordenar por ID (Bubble Sort)
6.  Busqueda secuencial
7.  Busqueda binaria iterativa
8.  Intercalar con segundo portafolio
9.  Reporte comparativo de algoritmos
10. Busqueda binaria recursiva
11. Guardar copia en archivo binario
12. Generar reporte TXT
0.  Salir
```

---

## Compilación y ejecución

```bash
# Compilar
g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o Gestor

# Ejecutar en Windows
Gestor.exe
```

---

## Algoritmos implementados

**Bubble Sort optimizado** — ordena por ID con bandera de intercambio.

**Búsqueda secuencial** — recorre el vector uno a uno.

**Búsqueda binaria iterativa** — divide el vector a la mitad en cada paso.

**Búsqueda binaria recursiva** — misma lógica que la iterativa pero con llamadas recursivas.

**Intercalación** — fusiona dos archivos CSV ordenados en uno manteniendo el orden.

---

## Conclusión

El proyecto demuestra el uso de arquitectura modular, manejo de archivos CSV y binarios,
algoritmos clásicos de ordenación y búsqueda, y estructuras de datos en C++,
aplicados a un dominio relevante para la carrera de Comunicación Digital y Multimedia.
