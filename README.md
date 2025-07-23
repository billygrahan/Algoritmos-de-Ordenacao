# Algoritmos de Ordenação

Este repositório contém implementações em C++ de diversos algoritmos clássicos de ordenação, tanto para inteiros quanto para caracteres, com suporte para ordenação crescente e decrescente. O objetivo é comparar o desempenho e o funcionamento de cada algoritmo, além de servir como material de estudo e referência.

## Algoritmos Implementados

- **Bubble Sort** (inteiros e caracteres)
- **Insertion Sort**
- **Selection Sort**
- **Merge Sort**
- **Quick Sort**
- **Heap Sort**
- **Counting Sort**
- **Radix Sort**

Cada algoritmo possui funções para ordenação crescente e decrescente, além de medições de tempo de execução utilizando `std::chrono`.

---

## Estrutura dos Arquivos

- `Bubble_Sort.cpp`  
  Implementa Bubble Sort para inteiros e caracteres, com funções de teste e medição de tempo.

- `Insertion_Sort.cpp`  
  Implementa Insertion Sort crescente e decrescente, com testes automáticos para diferentes tamanhos de vetor.

- `Selection_Sort.cpp`  
  (Se presente) Implementa Selection Sort crescente e decrescente.

- `Merge_Sort.cpp`  
  Implementa Merge Sort crescente e decrescente, incluindo funções para ordenação de inteiros.

- `Quick_Sort.cpp`  
  Implementa Quick Sort crescente e decrescente, com funções de teste e medição de tempo.

- `Heap_Sort.cpp`  
  Implementa Heap Sort crescente e decrescente, com funções de teste e medição de tempo.

- `Counting_Sort.cpp`  
  Implementa Counting Sort crescente e decrescente, adequado para inteiros não-negativos.

- `Radix_Sort.cpp`  
  Implementa Radix Sort crescente e decrescente, utilizando Counting Sort como sub-rotina.

---

## Como Executar

1. **Compile o arquivo desejado** (exemplo para o Insertion Sort):

   ```bash
   g++ -std=c++11 Insertion_Sort.cpp -o insertion_sort
   ./insertion_sort
