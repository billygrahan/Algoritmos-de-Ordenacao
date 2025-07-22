#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void countingSortRadix(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> Saida(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int k = 1; k < 10; k++)
        count[k] += count[k - 1];

    for (int l = n - 1; l >= 0; l--)
    {
        int digito = (arr[l] / exp) % 10;
        Saida[count[digito] - 1] = arr[l];
        count[digito]--;
    }

    for (int m = 0; m < n; m++)
        arr[m] = Saida[m];
}

void radixSort(vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortRadix(arr, exp);
}

void countingSortRadix_Decrescente(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> Saida(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int k = 1; k < 10; k++)
        count[k] += count[k - 1];

    for (int l = 0; l < n; l++)
    {
        int digito = (arr[l] / exp) % 10;
        Saida[n - count[digito]] = arr[l];
        count[digito]--;
    }

    for (int m = 0; m < n; m++)
        arr[m] = Saida[m];
}

void radixSort_Decrescente(vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortRadix_Decrescente(arr, exp);
}

void orderedArray(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    radixSort(arr);

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

void orderedArray_Decrescente(vector<int> &arr)
{
    auto start = high_resolution_clock::now();

    radixSort_Decrescente(arr);

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

int main()
{
    vector<int> arr = {49230, 89952, 25237, 91194, 97087, 48569, 16673, 45849, 38870, 13701};
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