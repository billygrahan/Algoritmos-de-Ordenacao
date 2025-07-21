#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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

    insertionSort(arr);

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
    vector<int> arr1 = {34, 9, 82, 9, -81, 71, 12, -59, -83, -28};

    orderedArray(arr1);

    return 0;
}
