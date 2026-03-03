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

## Visual Aplication

This is a [Next.js](https://nextjs.org) project bootstrapped with [`create-next-app`](https://nextjs.org/docs/app/api-reference/cli/create-next-app).

## Getting Started

First, run the development server:

```bash
npm run dev
# or
yarn dev 
# or
pnpm dev
# or
bun dev
```

Open [http://localhost:3000](http://localhost:3000) with your browser to see the result.

You can start editing the page by modifying `app/page.tsx`. The page auto-updates as you edit the file.

This project uses [`next/font`](https://nextjs.org/docs/app/building-your-application/optimizing/fonts) to automatically optimize and load [Geist](https://vercel.com/font), a new font family for Vercel.

## Learn More

To learn more about Next.js, take a look at the following resources:

- [Next.js Documentation](https://nextjs.org/docs) - learn about Next.js features and API.
- [Learn Next.js](https://nextjs.org/learn) - an interactive Next.js tutorial.

You can check out [the Next.js GitHub repository](https://github.com/vercel/next.js) - your feedback and contributions are welcome!

## Deploy on Vercel

The easiest way to deploy your Next.js app is to use the [Vercel Platform](https://vercel.com/new?utm_medium=default-template&filter=next.js&utm_source=create-next-app&utm_campaign=create-next-app-readme) from the creators of Next.js.

Check out our [Next.js deployment documentation](https://nextjs.org/docs/app/building-your-application/deploying) for more details.
