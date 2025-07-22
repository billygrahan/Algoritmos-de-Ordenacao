#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition_Decrescente(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (arr[j] > pivot) // !!
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort_Decrescente(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition_Decrescente(arr, low, high);
        quickSort_Decrescente(arr, low, pi - 1);
        quickSort_Decrescente(arr, pi + 1, high);
    }
}

// int partition_char(vector<char>& arr, int low, int high) {
//     char pivot = arr[high];
//     int i = low - 1;
//     for (int j = low; j < high; ++j) {
//         if (arr[j] < pivot) {
//             ++i;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort_char(vector<char>& arr, int low, int high) {
//     if (low < high) {
//         int pi = partition_char(arr, low, high);
//         quickSort_char(arr, low, pi - 1);
//         quickSort_char(arr, pi + 1, high);
//     }
// }

void orderedArray(vector<int>& arr) {
    auto start = high_resolution_clock::now();

    quickSort(arr, 0, arr.size() - 1);

    // Fim da medição
    auto end = high_resolution_clock::now();
    double duration = duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
    cout.precision(10);
    cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

    cout << "array Ordenado: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    
}

void orderedArray_Decrescente(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    quickSort_Decrescente(arr, 0, arr.size() - 1);

    // Fim da medição
    auto end = high_resolution_clock::now();
    double duration = duration_cast<std::chrono::duration<double, std::milli> >(end - start).count();
    cout.precision(10);
    cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

    cout << "array Ordenado: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
}

// void orderedArray_char(vector<char>& arr) {
//     cout << endl  << endl << "-------------------------------------------------------------------"<< endl;
//     cout << "arrey: ";
//     for (int i = 0; i < arr.size(); ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     auto start = high_resolution_clock::now();

//     //insertionSort_chat(arr);

//     // Fim da medição
//     auto end = high_resolution_clock::now();
//     double duration = duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
//     cout.precision(10);
//     cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

//     cout << "array Ordenado: ";
//     for (int i = 0; i < arr.size(); ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl << "-------------------------------------------------------------------" << endl << endl;
// }

int main() {
    vector<int> arr = {81, 20, 55, 17, 24, 32, 14, 13, 68, 20};
    cout << endl
         << endl
         << "-------------------------------------------------------------------" << endl;
    cout << "arrey: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> arr1 = arr;
    orderedArray(arr1);
    cout << endl
         << endl;
    vector<int> arr2 = arr;
    orderedArray_Decrescente(arr2);

    cout << endl
         << "-------------------------------------------------------------------" << endl
         << endl;
    return 0;
}