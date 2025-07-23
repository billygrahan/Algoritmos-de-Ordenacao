#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<int> &arr, int esq, int meio, int dir)
{
    vector<int> x;
    int i = esq, j = meio + 1;

    while (i <= meio && j <= dir)
    {
        if (arr[i] <= arr[j])
        {
            x.push_back(arr[i++]);
        }
        else
        {
            x.push_back(arr[j++]);
        }
    }

    while (i <= meio)
        x.push_back(arr[i++]);

    while (j <= dir)
        x.push_back(arr[j++]);

    for (int k = 0; k < x.size(); ++k)
    {
        arr[esq + k] = x[k];
    }
}

void mergeSort(vector<int> &arr, int esq, int dir)
{
    if (esq < dir)
    {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);
        merge(arr, esq, meio, dir);
    }
}

void merge_Dec(vector<int> &arr, int esq, int meio, int dir)
{
    vector<int> x;
    int i = esq, j = meio + 1;

    while (i <= meio && j <= dir)
    {
        if (arr[i] >= arr[j]) // !!
        {
            x.push_back(arr[i++]);
        }
        else
        {
            x.push_back(arr[j++]);
        }
    }

    while (i <= meio)
        x.push_back(arr[i++]);

    while (j <= dir)
        x.push_back(arr[j++]);

    for (int k = 0; k < x.size(); ++k)
    {
        arr[esq + k] = x[k];
    }
}

void mergeSort_Dec(vector<int> &arr, int esq, int dir)
{
    if (esq < dir)
    {
        int meio = esq + (dir - esq) / 2;
        mergeSort_Dec(arr, esq, meio);
        mergeSort_Dec(arr, meio + 1, dir);
        merge_Dec(arr, esq, meio, dir);
    }
}

// void merge_char(vector<char> &arr, int esq, int meio, int dir)
// {
//     vector<char> x;
//     int i = esq, j = meio + 1;

//     while (i <= meio && j <= dir)
//     {
//         if (arr[i] <= arr[j])
//         {
//             x.push_back(arr[i++]);
//         }
//         else
//         {
//             x.push_back(arr[j++]);
//         }
//     }

//     while (i <= meio)
//         x.push_back(arr[i++]);

//     while (j <= dir)
//         x.push_back(arr[j++]);

//     for (int k = 0; k < x.size(); ++k)
//     {
//         arr[esq + k] = x[k];
//     }
// }

// void mergeSort_char(vector<char> &arr, int esq, int dir)
// {
//     if (esq < dir)
//     {
//         int meio = esq + (dir - esq) / 2;
//         mergeSort_char(arr, esq, meio);
//         mergeSort_char(arr, meio + 1, dir);
//         merge_char(arr, esq, meio, dir);
//     }
// }

void orderedArray(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, arr.size() - 1);

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

    mergeSort_Dec(arr, 0, arr.size() - 1);

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

// void orderedArray_char(vector<char> &arr)
// {
//     auto start = high_resolution_clock::now();

//     mergeSort_char(arr, 0, arr.size() - 1);

//     // Fim da medição
//     auto end = high_resolution_clock::now();
//     double duration = duration_cast<std::chrono::duration<double, std::milli> >(end - start).count();
//     cout.precision(10);
//     cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

//     cout << "array Ordenado: ";
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         cout << arr[i] << " ";
//     }
// }

void teste(int qtd, vector<int> &arr)
{
    vector<int> arr0 = arr;
    for (int i = 0; i < qtd; ++i)
    {
        cout << endl
             << endl
             << "-------------------------------------------------------------------" << endl;
        cout << "Teste " << (i + 1) * 10 << endl;
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
    vector<int> arr = {86, 49, 28, 72, 63, 38, 31, 89, 24, 29};

    teste(20, arr);

    return 0;
}