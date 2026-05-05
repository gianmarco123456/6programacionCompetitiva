# Tarea 3: Comparación de Algoritmos de Ordenamiento

## Descripción

Este programa en C++ permite comparar distintos algoritmos de ordenamiento utilizando números aleatorios generados por el usuario.

El programa solicita:

1. Cantidad de números aleatorios a generar
2. Valor mínimo del rango
3. Valor máximo del rango

Luego ejecuta los siguientes algoritmos:

* Bubble Sort
* Selection Sort
* Insertion Sort
* Merge Sort
* Quick Sort

Finalmente muestra una tabla comparativa con:

* Número de iteraciones realizadas
* Tiempo de ejecución en milisegundos
* Orden de eficiencia temporal (del más rápido al más lento)

Esto permite analizar de forma práctica el rendimiento de cada algoritmo.

---

## Requisitos

Para ejecutar este programa en Linux se necesita:

* Compilador `g++` (parte de GCC)

Verificar instalación:

```bash
g++ --version
```

Si no está instalado:

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install g++
```

### Arch Linux

```bash
sudo pacman -S gcc
```

### Fedora

```bash
sudo dnf install gcc-c++
```

---

## Compilación

Ubicarse en la carpeta donde está el archivo:

```bash
cd tarea_ordenamientos
```

Compilar:

```bash
g++ ordenamientos.cpp -o ordenamientos
```

Esto generará el ejecutable:

```bash
./ordenamientos
```

---

## Ejecución

Ejecutar con:

```bash
./ordenamientos
```

---

## Ejemplo de ejecución 1

```text
========================================
 COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
========================================

Ingrese cantidad de numeros aleatorios: 1000
Ingrese valor minimo del rango: 1
Ingrese valor maximo del rango: 5000

===============================================
 RESULTADOS ORDENADOS POR EFICIENCIA TEMPORAL
===============================================

Algoritmo           Iteraciones        Tiempo (ms)
-------------------------------------------------------
Quick Sort          10543              0.2101
Merge Sort          9987               0.3154
Insertion Sort      248120             1.8421
Selection Sort      499500             3.1052
Bubble Sort         499500             4.2218

El algoritmo mas eficiente fue: Quick Sort
```

---

## Ejemplo de ejecución 2

```text
========================================
 COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
========================================

Ingrese cantidad de numeros aleatorios: 5000
Ingrese valor minimo del rango: 10
Ingrese valor maximo del rango: 10000

===============================================
 RESULTADOS ORDENADOS POR EFICIENCIA TEMPORAL
===============================================

Algoritmo           Iteraciones        Tiempo (ms)
-------------------------------------------------------
Quick Sort          61234              1.0254
Merge Sort          58742              1.4022
Insertion Sort      6235410            45.2184
Selection Sort      12497500           78.5311
Bubble Sort         12497500           95.7742

El algoritmo mas eficiente fue: Quick Sort
```

---

## Observaciones

* Para cantidades pequeñas todos los algoritmos funcionan rápidamente.
* Para grandes volúmenes de datos, Bubble Sort y Selection Sort pueden tardar bastante debido a su complejidad O(n²).
* Merge Sort y Quick Sort presentan mejor rendimiento gracias a su complejidad aproximada O(n log n).

Por ello, para aplicaciones reales, normalmente se prefieren algoritmos como Quick Sort o Merge Sort.

---

# Futuras tareas

Este repositorio seguirá creciendo con nuevas prácticas como:

* Búsquedas binarias y lineales
* Árboles KD-Tree
* Métodos numéricos
* Recursividad
* Divide and Conquer
* Programación dinámica
* Simulación de algoritmos
* Optimización y análisis de complejidad

---
