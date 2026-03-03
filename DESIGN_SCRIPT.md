# AlgoVisual PAA — Script de Design do Site

> **Contexto:** Aplicação web para auxiliar a monitoria de Projeto e Análise de Algoritmos (PAA), tornando algoritmos de ordenação visualmente compreensíveis através de animações passo a passo.

---

## 1. Identidade Visual

### Paleta de Cores

| Papel                        | Cor (hex)  | Uso                                              |
|------------------------------|------------|--------------------------------------------------|
| Background principal         | `#0f172a`  | Fundo geral da página (slate-950)                |
| Background secundário        | `#1e293b`  | Cards, painéis, sidebar (slate-800)              |
| Background de card           | `#334155`  | Elementos internos, code block (slate-700)       |
| Borda sutil                  | `#475569`  | Divisores e contornos (slate-600)                |
| Texto principal              | `#f1f5f9`  | Títulos e texto geral (slate-100)                |
| Texto secundário             | `#94a3b8`  | Subtítulos, legenda (slate-400)                  |
| **Azul Ciano — Ativo/Padrão**| `#22d3ee`  | Elemento padrão do array                         |
| **Âmbar — Key (chave)**      | `#f59e0b`  | Elemento chave separado do array durante inserção|
| **Roxo — Ponteiro i**        | `#a855f7`  | Borda e indicador do ponteiro i                  |
| **Vermelho — Ponteiro j**    | `#ef4444`  | Borda e indicador do ponteiro j (comparação)     |
| **Verde — Ordenado**         | `#22c55e`  | Elementos já em posição final correta             |
| **Rosa — Deslocamento**      | `#ec4899`  | Elemento sendo deslocado (shift)                 |
| **Laranja — Posição final**  | `#fb923c`  | Slot onde o key será inserido                    |

### Tipografia
- **Títulos**: Inter / sans-serif, bold
- **Código/Pseudocódigo**: JetBrains Mono / monospace
- **Corpo**: Inter, regular / medium

---

## 2. Estrutura de Layout

```
┌──────────────────────────────────────────────────────────┐
│                        HEADER                            │
│   [AlgoVisual]   Projeto e Análise de Algoritmos — PAA  │
│                  UFAL · Ciência da Computação            │
├──────────────────────────────────────────────────────────┤
│  SIDEBAR        │          CONTEÚDO PRINCIPAL            │
│                 │                                        │
│  ► Insertion    │  ┌─────────── PAINEL DE ENTRADA ──┐   │
│    Sort  ✓      │  │  [ 34 ] [ 9 ] [-81] [ 71 ]     │   │
│                 │  │  + Adicionar elemento  [Iniciar]│   │
│  ○ Bubble Sort  │  └────────────────────────────────┘   │
│  ○ Merge Sort   │                                        │
│  ○ Quick Sort   │  ┌──────── ÁREA DE VISUALIZAÇÃO ───┐   │
│  ○ Heap Sort    │  │                                  │   │
│  ○ Counting Sort│  │   [  9 ] [ 12] [ 34] [ 82]      │   │
│  ○ Radix Sort   │  │     ↑i         ↑j                │   │
│                 │  │                                  │   │
│                 │  │   key = 12    [slot livre]       │   │
│                 │  │                                  │   │
│                 │  └──────────────────────────────────┘  │
│                 │                                        │
│                 │  ┌──── DESCRIÇÃO DO PASSO ATUAL ───┐   │
│                 │  │  Passo 3/12                     │   │
│                 │  │  Comparando arr[j]=34 com key=12│   │
│                 │  │  34 > 12 → deslocar 34 para dir.│   │
│                 │  └────────────────────────────────┘   │
│                 │                                        │
│                 │  ┌────── PSEUDOCÓDIGO ─────────────┐   │
│                 │  │  for i = 1 to n-1               │   │
│                 │  │  ► key = arr[i]  ← linha ativa  │   │
│                 │  │    j = i - 1                    │   │
│                 │  │    while j ≥ 0 and arr[j] > key │   │
│                 │  │      arr[j+1] = arr[j]          │   │
│                 │  │      j = j - 1                  │   │
│                 │  │    arr[j+1] = key               │   │
│                 │  └────────────────────────────────┘   │
│                 │                                        │
│                 │  ┌────── CONTROLES ────────────────┐   │
│                 │  │  |◄  ◄  ▶/⏸  ►  ►|   [======] │   │
│                 │  │  Passo 3 de 12    Velocidade    │   │
│                 │  └────────────────────────────────┘   │
└─────────────────┴──────────────────────────────────────┘
```

---

## 3. Componentes Principais

### Header
- Logo textual "AlgoVisual" em ciano
- Subtítulo "Projeto e Análise de Algoritmos — PAA"
- Linha fina separadora

### Sidebar
- Lista de algoritmos com ícone de status:
  - `✓` verde = implementado e disponível
  - `○` cinza = em breve (locked)
- Item ativo com borda esquerda ciano e fundo levemente destacado

### Painel de Entrada do Array
- Campos de input numérico inline para cada elemento (mín. 4)
- Botões: `+ Adicionar`, `- Remover`, `Embaralhar`, `Reiniciar`, `▶ Iniciar Visualização`
- Validação visual (borda vermelha se vazio ou inválido)

### Área de Visualização (core)
- Blocos retangulares para cada elemento do array
  - Exibem: valor e índice abaixo
  - Cor muda dinamicamente conforme estado
  - Animação suave de transição (translate/scale)
- Slot fantasma (dashed border) mostrando posição atual do `key`
- Ponteiros `i` e `j` como setas/labels coloridas abaixo dos blocos
- Display separado da variável `key` com destaque âmbar
- Legenda de cores na parte inferior da visualização

### Painel de Descrição de Passo
- Número do passo atual / total
- Texto descritivo em linguagem natural (pt-BR)
- Fundo levemente destacado para o tipo de operação (comparação, deslocamento, inserção)

### Painel de Pseudocódigo
- Linhas numeradas com fonte monospace
- Linha ativa destacada em amarelo/ciano com seta `▶`
- Sintaxe colorida simples

### Controles
- Botões: `|◄` (início) `◄` (passo anterior) `▶/⏸` (play/pause) `►` (próximo passo) `►|` (fim)
- Slider de velocidade: Lento → Rápido
- Indicador: "Passo X de Y"

---

## 4. Estados Visuais dos Blocos

| Estado               | Cor de fundo      | Borda         | Ícone ponteiro |
|----------------------|-------------------|---------------|----------------|
| Default (não visitado)| Ciano `#22d3ee`  | —             | —              |
| Ordenado             | Verde `#22c55e`  | —             | —              |
| Sendo comparado (j)  | Vermelho `#ef4444`| Vermelho thick| `j ↑`          |
| Ponteiro i           | Roxo `#a855f7`   | Roxo thick    | `i ↑`          |
| Key (extraído)       | Âmbar `#f59e0b`  | —             | `key`          |
| Sendo deslocado      | Rosa `#ec4899`   | Rosa          | —              |
| Slot de inserção     | Dashed laranja   | Laranja dash  | —              |

---

## 5. Fluxo de Interação

```
1. Usuário digita 4+ números nos inputs
2. Clica em "▶ Iniciar Visualização"
3. Algoritmo gera lista de todos os passos (snapshots)
4. Usuário controla navegação via botões de controle
5. A cada passo:
   - Array visual atualiza com cores e animações
   - Pseudocódigo destaca linha correspondente
   - Descrição textual explica a operação
   - Variáveis auxiliares (i, j, key) são exibidas
6. Ao finalizar, todos os blocos ficam verdes + mensagem "Ordenado!"
```

---

## 6. Tecnologias

- **Framework**: Next.js 14+ com App Router
- **Linguagem**: TypeScript
- **Estilização**: Tailwind CSS
- **Animações**: CSS transitions + Framer Motion (leve)
- **Icons**: Lucide React
- **Estado**: React useState/useReducer (sem lib externa)

---

## 7. Estrutura de Pastas

```
algovisual/
├── app/
│   ├── layout.tsx          # Layout global com header
│   ├── page.tsx            # Página principal
│   └── globals.css         # Estilos globais
├── components/
│   ├── Header.tsx
│   ├── Sidebar.tsx
│   ├── ArrayInput.tsx      # Input dos elementos
│   ├── ArrayVisualizer.tsx # Visualização principal
│   ├── ArrayBlock.tsx      # Bloco individual do array
│   ├── PointerLabel.tsx    # Labels i, j, key
│   ├── StepDescription.tsx # Descrição do passo
│   ├── PseudoCode.tsx      # Painel de pseudocódigo
│   └── ControlPanel.tsx    # Botões e slider
├── lib/
│   ├── insertionSort.ts    # Gerador de passos
│   └── types.ts            # Interfaces TypeScript
└── hooks/
    └── useAlgorithmPlayer.ts # Lógica play/pause/step
```
