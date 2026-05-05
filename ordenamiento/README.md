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

Ingrese cantidad, minimo, maximo: 1000 1 5000

===============================================
 RESULTADOS ORDENADOS POR EFICIENCIA TEMPORAL
===============================================

Algoritmo           Iteraciones         Tiempo (ns)    
-------------------------------------------------------
Quick Sort          10014               327544.0       
Merge Sort          8721                857306.0       
Insertion Sort      257489              3382595.0      
Selection Sort      499500              4918517.0      
Bubble Sort         499500              12892975.0  

El algoritmo mas eficiente fue: Quick Sort
```

---

## Ejemplo de ejecución 2

```text
========================================
 COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
========================================

Ingrese cantidad, minimo, maximo: 5000 10 10000

===============================================
 RESULTADOS ORDENADOS POR EFICIENCIA TEMPORAL
===============================================

Algoritmo           Iteraciones         Tiempo (ns)    
-------------------------------------------------------
Quick Sort          76659               2121936.0      
Merge Sort          55199               4888822.0      
Insertion Sort      6158792             80085411.0     
Selection Sort      12497500            118889037.0    
Bubble Sort         12497500            337228555.0  

El algoritmo mas eficiente fue: Quick Sort
```

---

## Observaciones

* Para cantidades pequeñas todos los algoritmos funcionan rápidamente.
* Para grandes volúmenes de datos, Bubble Sort y Selection Sort pueden tardar bastante debido a su complejidad O(n²).
* Merge Sort y Quick Sort presentan mejor rendimiento gracias a su complejidad aproximada O(n log n).

Por ello, para aplicaciones reales, normalmente se prefieren algoritmos como Quick Sort o Merge Sort.
