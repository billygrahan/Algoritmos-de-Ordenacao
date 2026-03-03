import { SortStep, ArrayElement, BlockState } from "./types"

function makeElements(
    arr: number[],
    stateMap: Record<number, BlockState> = {}
): ArrayElement[] {
    return arr.map((value, index) => ({
        value,
        index,
        state: stateMap[index] ?? "default",
    }))
}

/**
 * Gera todos os passos do Insertion Sort para uma lista de números.
 * Cada passo representa um snapshot do estado visual para animação.
 */
export function generateInsertionSortSteps(input: number[]): SortStep[] {
    const steps: SortStep[] = []
    const arr = [...input]
    const n = arr.length

    // Passo inicial: mostrar o array original
    steps.push({
        elements: makeElements(arr),
        iPointer: null,
        jPointer: null,
        keyValue: null,
        keyExtracted: false,
        activeLine: "outer-for",
        description: `Array inicial com ${n} elementos. O Insertion Sort percorre o array da esquerda para a direita, inserindo cada elemento em sua posição correta.`,
        phase: "idle",
    })

    // Marca os elementos já ordenados (inicialmente nenhum, exceto o índice 0)
    const sortedIndices = new Set<number>([0])

    // ─── Loop externo ─────────────────────────────────────────────
    for (let i = 1; i < n; i++) {
        const key = arr[i]

        // Passo: ponteiro i avança, linha "for"
        steps.push({
            elements: makeElements(arr, {
                ...Object.fromEntries([...sortedIndices].map((idx) => [idx, "sorted"])),
                [i]: "pointer-i",
            }),
            iPointer: i,
            jPointer: null,
            keyValue: null,
            keyExtracted: false,
            activeLine: "outer-for",
            description: `Iteração i = ${i}: ponteiro i aponta para o elemento arr[${i}] = ${key}.`,
            phase: "idle",
        })

        // Passo: extraindo a chave
        steps.push({
            elements: makeElements(arr, {
                ...Object.fromEntries([...sortedIndices].map((idx) => [idx, "sorted"])),
                [i]: "key",
            }),
            iPointer: i,
            jPointer: null,
            keyValue: key,
            keyExtracted: true,
            activeLine: "key-assign",
            description: `key = arr[${i}] = ${key}. O elemento é extraído e guardado na variável auxiliar "key".`,
            phase: "extractKey",
        })

        let j = i - 1

        // Passo: j = i - 1
        steps.push({
            elements: makeElements(arr, {
                ...Object.fromEntries([...sortedIndices].map((idx) => [idx, "sorted"])),
                [i]: "slot",
                [j]: "pointer-j",
            }),
            iPointer: i,
            jPointer: j,
            keyValue: key,
            keyExtracted: true,
            activeLine: "j-assign",
            description: `j = i - 1 = ${j}. Ponteiro j aponta para arr[${j}] = ${arr[j]}, o elemento anterior.`,
            phase: "compare",
        })

        // ─── Loop interno ───────────────────────────────────────────
        while (j >= 0 && arr[j] > key) {
            // Passo: verificando condição while
            steps.push({
                elements: makeElements(arr, {
                    ...Object.fromEntries(
                        [...sortedIndices].map((idx) => [idx, "sorted"])
                    ),
                    [j]: "pointer-j",
                    [j + 1]: "slot",
                }),
                iPointer: i,
                jPointer: j,
                keyValue: key,
                keyExtracted: true,
                activeLine: "while-cond",
                description: `Condição: j = ${j} ≥ 0 ✓ e arr[${j}] = ${arr[j]} > key = ${key} ✓ → deve deslocar.`,
                phase: "compare",
            })

            // Deslocamento
            arr[j + 1] = arr[j]

            // Passo: mostrando o deslocamento
            steps.push({
                elements: makeElements(arr, {
                    ...Object.fromEntries(
                        [...sortedIndices].map((idx) => [idx, "sorted"])
                    ),
                    [j]: "pointer-j",
                    [j + 1]: "shifting",
                }),
                iPointer: i,
                jPointer: j,
                keyValue: key,
                keyExtracted: true,
                activeLine: "shift",
                description: `arr[${j + 1}] = arr[${j}] = ${arr[j + 1]}. O elemento ${arr[j + 1]} é deslocado uma posição para a direita.`,
                phase: "shift",
            })

            // Passo: decrementando j
            j--

            steps.push({
                elements: makeElements(arr, {
                    ...Object.fromEntries(
                        [...sortedIndices].map((idx) => [idx, "sorted"])
                    ),
                    ...(j >= 0 ? { [j]: "pointer-j" } : {}),
                    [j + 1]: "slot",
                }),
                iPointer: i,
                jPointer: j,
                keyValue: key,
                keyExtracted: true,
                activeLine: "j-decrement",
                description:
                    j >= 0
                        ? `j = j - 1 = ${j}. Ponteiro j recua para arr[${j}] = ${arr[j]}.`
                        : `j = j - 1 = ${j}. j < 0, saindo do loop while.`,
                phase: "compare",
            })
        }

        // Passo: condição while falsa (se j ≥ 0 e arr[j] <= key)
        if (j >= 0) {
            steps.push({
                elements: makeElements(arr, {
                    ...Object.fromEntries(
                        [...sortedIndices].map((idx) => [idx, "sorted"])
                    ),
                    [j]: "pointer-j",
                    [j + 1]: "slot",
                }),
                iPointer: i,
                jPointer: j,
                keyValue: key,
                keyExtracted: true,
                activeLine: "while-cond",
                description: `Condição: arr[${j}] = ${arr[j]} ≤ key = ${key} → condição falsa, saindo do while. Posição de inserção encontrada: ${j + 1}.`,
                phase: "compare",
            })
        }

        // Inserção do key
        arr[j + 1] = key
        sortedIndices.add(i)

        // Marca os índices 0..i como ordenados
        const newSortedMap: Record<number, BlockState> = {}
        for (let k = 0; k <= i; k++) newSortedMap[k] = "sorted"

        steps.push({
            elements: makeElements(arr, newSortedMap),
            iPointer: i,
            jPointer: j,
            keyValue: key,
            keyExtracted: false,
            activeLine: "insert",
            description: `arr[${j + 1}] = key = ${key}. O elemento ${key} é inserido na posição ${j + 1}. Os primeiros ${i + 1} elementos estão ordenados.`,
            phase: "insert",
        })
    }

    // Passo final: tudo ordenado
    const finalMap: Record<number, BlockState> = {}
    for (let k = 0; k < n; k++) finalMap[k] = "sorted"

    steps.push({
        elements: makeElements(arr, finalMap),
        iPointer: null,
        jPointer: null,
        keyValue: null,
        keyExtracted: false,
        activeLine: "done",
        description: `Array completamente ordenado! O Insertion Sort realizou ${steps.length} passos para ordenar ${n} elementos.`,
        phase: "done",
    })

    return steps
}
