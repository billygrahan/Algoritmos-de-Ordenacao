#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(vector<int> &arr, int n, int i)
{
    int maior = i; 
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    if (maior != i)
    {
        swap(arr[i], arr[maior]); // troca
        heapify(arr, n, maior);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0);  
    }
}

void heapify_dec(vector<int> &arr, int n, int i)
{
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] < arr[menor]) // !!
        menor = esq;

    if (dir < n && arr[dir] < arr[menor]) // !!
        menor = dir;

    if (menor != i)
    {
        swap(arr[i], arr[menor]);
        heapify_dec(arr, n, menor);
    }
}

void heapSort_dec(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_dec(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify_dec(arr, i, 0);
    }
}

void orderedArray(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    heapSort(arr);

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

    heapSort_dec(arr);

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

int main()
{
    vector<int> arr = {81, 20, 55, 17, 24, 32, 14, 13, 68, 20};
    cout << endl
         << endl
         << "-------------------------------------------------------------------" << endl;
    cout << "arrey: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    vector<int> arr1 = arr;
    orderedArray(arr1);
    cout << endl
         << endl;
    vector<int> arr2 = arr;
    orderedArray_Dec(arr2);

    cout << endl
         << "-------------------------------------------------------------------" << endl
         << endl;
    return 0;
}
