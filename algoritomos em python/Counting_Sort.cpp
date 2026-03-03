#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

vector<int> countingSort(const vector<int> &A, int k)
{
    int n = A.size();
    vector<int> Saida(n);
    vector<int> Count(k + 1, 0);

    for (int j = 0; j < n; j++)
    {
        Count[A[j]] ++;
    }

    for (int i = 1; i <= k; i++)
    {
        Count[i] += Count[i - 1];
    }

    for (int j = n - 1; j >= 0; j--)
    {
        Saida[Count[A[j]] - 1] = A[j];
        Count[A[j]] --;
    }

    return Saida;
}

vector<int> countingSort_Decrescente(const vector<int> &A, int k)
{
    int n = A.size();
    vector<int> Saida(n);
    vector<int> Count(k + 1, 0);

    for (int j = 0; j < n; j++)
    {
        Count[A[j]] ++;
    }

    for (int i = 1; i <= k; i++)
    {
        Count[i] += Count[i - 1];
    }

    for (int j = 0; j < n; j++)
    {
        Saida[n - Count[A[j]]] = A[j];
        Count[A[j]] --;
    }

    return Saida;
}

void orderedArray(vector<int> &arr)
{

    auto start = high_resolution_clock::now();

    arr = countingSort(arr, *max_element(arr.begin(), arr.end()));

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

    arr = countingSort_Decrescente(arr, *max_element(arr.begin(), arr.end()));

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
        orderedArray_Decrescente(arr2);

        cout << endl
             << "-------------------------------------------------------------------" << endl
             << endl;

        arr0.insert(arr0.end(), arr.begin(), arr.end());
    }
}

int main()
{
    vector<int> arr = {1, 2, 5, 4, 0, 0, 2, 6, 4, 6};
    
    teste(20, arr);
    
    return 0;
}