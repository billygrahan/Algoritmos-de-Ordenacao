#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void insertionSort_Dec(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) // !!
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void orderedArray(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    insertionSort(arr);

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

void orderedArray_Dec(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    insertionSort_Dec(arr);

    // Fim da medição
    auto end = high_resolution_clock::now();
    double duration = duration_cast<std::chrono::duration<double, std::milli> >(end - start).count();
    cout.precision(10);
    cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

    cout << "array Ordenado Decrescente: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
}

void teste(int qtd, vector<int> &arr)
{
    vector<int> arr0 = arr;
    for (int i = 0; i < qtd; ++i)
    {
        cout << endl
             << endl
             << "-------------------------------------------------------------------" << endl;
        cout << "Teste " << (i + 1)*10 << endl;
        cout << "arrey: ";
        for (int i = 0; i < arr0.size(); ++i)
        {
            cout << arr0[i] << " ";
        }
        cout << endl
             << endl;

        vector<int> arr1 = arr0;
        orderedArray(arr1);
        cout << endl
             << endl;
        vector<int> arr2 = arr0;
        orderedArray_Dec(arr2);

        cout << endl
             << "-------------------------------------------------------------------" << endl
             << endl;
        
        arr0.insert(arr0.end(), arr.begin(), arr.end());
    }
}

int main()
{
    vector<int> arr = {34, 9, 82, 9, -81, 71, 12, -59, -83, -28};
    
    teste(20, arr);

    return 0;
}
