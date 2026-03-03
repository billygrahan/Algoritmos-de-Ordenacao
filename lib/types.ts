// Estado visual de cada bloco do array
export type BlockState =
    | "default"    // Não visitado ainda
    | "sorted"     // Já na posição correta
    | "key"        // Elemento extraído como chave
    | "pointer-i"  // Posição do ponteiro i
    | "pointer-j"  // Posição do ponteiro j (sendo comparado)
    | "shifting"   // Sendo deslocado para a direita
    | "slot"       // Slot vazio onde o key será inserido
    | "comparing"  // Comparação geral

// Um elemento do array no estado atual
export interface ArrayElement {
    value: number
    state: BlockState
    index: number
}

// Linha do pseudocódigo que pode ser destacada
export type PseudoCodeLine =
    | "outer-for"
    | "key-assign"
    | "j-assign"
    | "while-cond"
    | "shift"
    | "j-decrement"
    | "insert"
    | "done"

// Um passo da animação
export interface SortStep {
    elements: ArrayElement[]
    iPointer: number | null      // Índice do ponteiro i
    jPointer: number | null      // Índice do ponteiro j
    keyValue: number | null      // Valor da variável chave
    keyExtracted: boolean        // Se a chave foi retirada do array
    activeLine: PseudoCodeLine   // Linha ativa no pseudocódigo
    description: string          // Texto descritivo para o usuário
    phase: "idle" | "extractKey" | "compare" | "shift" | "insert" | "done"
}

// Algoritmo disponível na sidebar
export interface Algorithm {
    id: string
    name: string
    available: boolean
}
