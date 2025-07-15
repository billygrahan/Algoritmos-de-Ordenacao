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

void insertionSort_chat(vector<char>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void orderedArray(vector<int>& arr) {
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
    cout << endl;
}

void orderedArray_char(vector<char>& arr) {
    cout << endl  << endl << "-------------------------------------------------------------------"<< endl;
    cout << "arrey: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();

    insertionSort_chat(arr);

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
    vector<char> arr2 = {'b', 'i', 'l', 'l', 'y', 'g', 'r', 'a', 'h', 'a', 'n'};
    vector<int> arr3 = {86, 49, 28, 72, 63, 38, 31, 89, 24, 29};
    vector<int> arr4 = {81, 20, 55, 17, 24, 32, 14, 13, 68, 20};
    vector<int> arr5 = {1,2,5,4,0,0,2,6,4,6};
    vector<int> arr6 = {49230, 89952, 25237, 91194, 97087, 48569, 16673, 45849, 38870, 13701};

    orderedArray_char(arr2);

    return 0;
}
