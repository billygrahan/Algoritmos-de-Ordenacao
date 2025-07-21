#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int esq, int meio, int dir) {
    vector<int> x;
    int i = esq, j = meio + 1;

    while (i <= meio && j <= dir) {
        if (arr[i] <= arr[j]) {
            x.push_back(arr[i++]);
        } else {
            x.push_back(arr[j++]);
        }
    }

    while (i <= meio) 
        x.push_back(arr[i++]);

    while (j <= dir)  
        x.push_back(arr[j++]);

    for (int k = 0; k < x.size(); ++k) {
        arr[esq + k] = x[k];
    }
}

void mergeSort(vector<int>& arr, int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);
        merge(arr, esq, meio, dir);
    }
}

void merge_char(vector<char>& arr, int esq, int meio, int dir) {
    vector<char> x;
    int i = esq, j = meio + 1;

    while (i <= meio && j <= dir) {
        if (arr[i] <= arr[j]) {
            x.push_back(arr[i++]);
        } 
        else {
            x.push_back(arr[j++]);
        }
    }

    while (i <= meio) 
        x.push_back(arr[i++]);

    while (j <= dir)  
        x.push_back(arr[j++]);

    for (int k = 0; k < x.size(); ++k) {
        arr[esq + k] = x[k];
    }
}

void mergeSort_char(vector<char>& arr, int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSort_char(arr, esq, meio);
        mergeSort_char(arr, meio + 1, dir);
        merge_char(arr, esq, meio, dir);
    }
}

void orderedArray(vector<int>& arr) {
    cout << endl  << endl << "-------------------------------------------------------------------"<< endl;
    cout << "arrey: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, arr.size() - 1);

    // Fim da medição
    auto end = high_resolution_clock::now();
    double duration = duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    cout.precision(10);
    cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

    cout << "array Ordenado: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl << "-------------------------------------------------------------------" << endl << endl;
}

void orderedArray_char(vector<char>& arr) {
    cout << endl  << endl << "-------------------------------------------------------------------"<< endl;
    cout << "arrey: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();

    mergeSort_char(arr, 0, arr.size() - 1);

    // Fim da medição
    auto end = high_resolution_clock::now();
    double duration = duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    cout.precision(10);
    cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

    cout << "array Ordenado: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl << "-------------------------------------------------------------------" << endl << endl;
}

int main() {
    // vector<int> arr1 = {34, 9, 82, 9, -81, 71, 12, -59, -83, -28};
    // vector<char> arr2 = {'b', 'i', 'l', 'l', 'y', 'g', 'r', 'a', 'h', 'a', 'n'};
    vector<int> arr3 = {86, 49, 28, 72, 63, 38, 31, 89, 24, 29};
    // vector<int> arr4 = {81, 20, 55, 17, 24, 32, 14, 13, 68, 20};
    // vector<int> arr5 = {1,2,5,4,0,0,2,6,4,6};
    // vector<int> arr6 = {49230, 89952, 25237, 91194, 97087, 48569, 16673, 45849, 38870, 13701};

    // orderedArray(arr1);
    // orderedArray_char(arr2);
    orderedArray(arr3);
    // orderedArray(arr4);
    // orderedArray(arr5);
    // orderedArray(arr6);

    return 0;
}