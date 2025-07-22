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

// Radix Sort principal
void radixSort(vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortRadix(arr, exp);
}

void orderedArray(vector<int> &arr)
{
    cout << endl
         << endl
         << "-------------------------------------------------------------------" << endl;
    cout << "arrey: ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

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
    cout << endl
         << "-------------------------------------------------------------------" << endl
         << endl;
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
    vector<int> arr6 = {49230, 89952, 25237, 91194, 97087, 48569, 16673, 45849, 38870, 13701};

    orderedArray(arr6);

    return 0;
}