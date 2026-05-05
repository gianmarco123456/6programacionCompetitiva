#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// Estructura para guardar resultados
struct Resultado {
    string nombre;
    long long iteraciones;
    double tiempo_ms;
};

// -------------------- Bubble Sort --------------------
Resultado bubbleSort(vector<int> arr) {
    long long iteraciones = 0;

    auto inicio = high_resolution_clock::now();

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            iteraciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto fin = high_resolution_clock::now();
    double tiempo = duration<double, nano>(fin - inicio).count();

    return {"Bubble Sort", iteraciones, tiempo};
}

// -------------------- Selection Sort --------------------
Resultado selectionSort(vector<int> arr) {
    long long iteraciones = 0;

    auto inicio = high_resolution_clock::now();

    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            iteraciones++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    auto fin = high_resolution_clock::now();
    double tiempo = duration<double, nano>(fin - inicio).count();

    return {"Selection Sort", iteraciones, tiempo};
}

// -------------------- Insertion Sort --------------------
Resultado insertionSort(vector<int> arr) {
    long long iteraciones = 0;

    auto inicio = high_resolution_clock::now();

    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            iteraciones++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }

    auto fin = high_resolution_clock::now();
    double tiempo = duration<double, nano>(fin - inicio).count();

    return {"Insertion Sort", iteraciones, tiempo};
}

// -------------------- Merge Sort --------------------
long long iterMerge = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        iterMerge++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortRec(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid);
        mergeSortRec(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

Resultado mergeSort(vector<int> arr) {
    iterMerge = 0;

    auto inicio = high_resolution_clock::now();

    mergeSortRec(arr, 0, arr.size() - 1);

    auto fin = high_resolution_clock::now();
    double tiempo = duration<double, nano>(fin - inicio).count();

    return {"Merge Sort", iterMerge, tiempo};
}

// -------------------- Quick Sort --------------------
long long iterQuick = 0;

int partitionQS(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        iterQuick++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRec(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionQS(arr, low, high);
        quickSortRec(arr, low, pi - 1);
        quickSortRec(arr, pi + 1, high);
    }
}

Resultado quickSort(vector<int> arr) {
    iterQuick = 0;

    auto inicio = high_resolution_clock::now();

    quickSortRec(arr, 0, arr.size() - 1);

    auto fin = high_resolution_clock::now();
    double tiempo = duration<double, nano>(fin - inicio).count();

    return {"Quick Sort", iterQuick, tiempo};
}

// -------------------- MAIN --------------------
int main() {
    srand(time(0));

    int n, minVal, maxVal;

    cout << "========================================\n";
    cout << " COMPARADOR DE ALGORITMOS DE ORDENAMIENTO\n";
    cout << "========================================\n\n";

    cout << "Ingrese cantidad, minimo, maximo: ";
    cin >> n >> minVal >> maxVal;

    if (minVal > maxVal) {
        cout << "\nError: el minimo no puede ser mayor que el maximo.\n";
        return 0;
    }

    // Generar vector aleatorio
    vector<int> numeros(n);
    for (int i = 0; i < n; i++) {
        numeros[i] = minVal + rand() % (maxVal - minVal + 1);
    }

    vector<Resultado> resultados;

    for (int i = 0; i<n; i++){

    	cout << numeros[i] << ", ";}
    cout << "."<<endl;

    resultados.push_back(bubbleSort(numeros));
    resultados.push_back(selectionSort(numeros));
    resultados.push_back(insertionSort(numeros));
    resultados.push_back(mergeSort(numeros));
    resultados.push_back(quickSort(numeros));

    // Ordenar por menor tiempo = mayor eficiencia
    sort(resultados.begin(), resultados.end(),
        [](Resultado a, Resultado b) {
            return a.tiempo_ms < b.tiempo_ms;
        });

    // Mostrar tabla
    cout << "\n===============================================\n";
    cout << " RESULTADOS ORDENADOS POR EFICIENCIA TEMPORAL\n";
    cout << "===============================================\n\n";

    cout << left
         << setw(20) << "Algoritmo"
         << setw(20) << "Iteraciones"
         << setw(15) << "Tiempo (ns)" << endl;

    cout << string(55, '-') << endl;

    for (auto r : resultados) {
        cout << left
             << setw(20) << r.nombre
             << setw(20) << r.iteraciones
             << setw(15) << fixed << setprecision(1) << r.tiempo_ms
             << endl;
    }

    cout << "\nEl algoritmo mas eficiente fue: "
         << resultados[0].nombre << endl;

    return 0;
}
