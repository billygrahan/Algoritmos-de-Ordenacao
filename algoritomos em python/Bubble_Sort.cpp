#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// void bubbleSort(vector<int>& arr) {
//     for (int i = 0; i < arr.size() - 1; ++i) {
//         for (int j = 0; j < arr.size() - i - 1; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

void bubbleSort_char(vector<char> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort_char_Decrecente(vector<char> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] < arr[j + 1]) // !!
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// void orderedArray(vector<int>& arr) {

//     auto start = high_resolution_clock::now();

//     bubbleSort(arr);

//     // Fim da medição
//     auto end = high_resolution_clock::now();
//     double duration = duration_cast<std::chrono::duration<double, std::milli>>(end - start).count();
//     cout.precision(10);
//     cout << "Tempo de execução: " << fixed << duration << " milissegundos" << endl;

//     cout << "array Ordenado: ";
//     for (int i = 0; i < arr.size(); ++i) {
//         cout << arr[i] << " ";
//     }
// }

void orderedArray_char(vector<char> &arr)
{
    auto start = high_resolution_clock::now();

    bubbleSort_char(arr);

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

void orderedArray_char_Dec(vector<char> &arr)
{
    auto start = high_resolution_clock::now();

    bubbleSort_char_Decrecente(arr);

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

void teste(int qtd, vector<char> &arr)
{
    vector<char> arr0 = arr;
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

        vector<char> arr1 = arr0;
        orderedArray_char(arr1);
        cout << endl
             << endl;
        vector<char> arr2 = arr0;
        orderedArray_char_Dec(arr2);

        cout << endl
             << "-------------------------------------------------------------------" << endl
             << endl;

        arr0.insert(arr0.end(), arr.begin(), arr.end());
    }
}

int main()
{
    vector<char> arr = {'b', 'i', 'l', 'l', 'y', 'g', 'r', 'a', 'h', 'a', 'n'};
    
    teste(20, arr);

    return 0;
}