"use client"

import { PseudoCodeLine } from "@/lib/types"
import { ChevronRight } from "lucide-react"

interface PseudoCodeProps {
    activeLine: PseudoCodeLine
}

const lines: { id: PseudoCodeLine; code: string; indent: number }[] = [
    { id: "outer-for", code: "for i = 1 to n - 1 do", indent: 0 },
    { id: "key-assign", code: "key = arr[i]", indent: 1 },
    { id: "j-assign", code: "j = i - 1", indent: 1 },
    { id: "while-cond", code: "while j ≥ 0 and arr[j] > key do", indent: 1 },
    { id: "shift", code: "arr[j + 1] = arr[j]", indent: 2 },
    { id: "j-decrement", code: "j = j - 1", indent: 2 },
    { id: "insert", code: "arr[j + 1] = key", indent: 1 },
]

const lineColors: Record<PseudoCodeLine, string> = {
    "outer-for": "bg-purple-500/20 border-l-2 border-purple-400",
    "key-assign": "bg-amber-500/20 border-l-2 border-amber-400",
    "j-assign": "bg-red-500/20 border-l-2 border-red-400",
    "while-cond": "bg-red-500/20 border-l-2 border-red-400",
    "shift": "bg-pink-500/20 border-l-2 border-pink-400",
    "j-decrement": "bg-red-500/20 border-l-2 border-red-400",
    "insert": "bg-cyan-500/20 border-l-2 border-cyan-400",
    "done": "bg-green-500/20 border-l-2 border-green-400",
}

export function PseudoCode({ activeLine }: PseudoCodeProps) {
    return (
        <div className="bg-slate-800 rounded-xl border border-slate-700 p-5">
            <h2 className="text-slate-200 font-semibold mb-4 text-sm uppercase tracking-wide">
                Pseudocódigo — Insertion Sort
            </h2>
            <div className="font-mono text-sm rounded-lg overflow-hidden bg-slate-900">
                {lines.map((line, idx) => {
                    const isActive = line.id === activeLine
                    return (
                        <div
                            key={line.id}
                            className={`
                flex items-center gap-2 px-3 py-2 transition-colors
                ${isActive ? lineColors[activeLine] : "hover:bg-slate-800/50"}
              `}
                        >
                            {/* Número da linha */}
                            <span className="text-slate-600 text-xs w-4 shrink-0 select-none">
                                {idx + 1}
                            </span>
                            {/* Ícone ativo */}
                            <span className="w-3 shrink-0">
                                {isActive && <ChevronRight className="w-3 h-3 text-cyan-400" />}
                            </span>
                            {/* Indentação + código */}
                            <span
                                className={`${isActive ? "text-slate-100" : "text-slate-400"}`}
                                style={{ paddingLeft: `${line.indent * 1.25}rem` }}
                            >
                                {line.code}
                            </span>
                        </div>
                    )
                })}
                {/* Linha "done" especial */}
                <div
                    className={`
            flex items-center gap-2 px-3 py-2 transition-colors
            ${activeLine === "done" ? lineColors["done"] : "hover:bg-slate-800/50"}
          `}
                >
                    <span className="text-slate-600 text-xs w-4 shrink-0 select-none">
                        {lines.length + 1}
                    </span>
                    <span className="w-3 shrink-0">
                        {activeLine === "done" && <ChevronRight className="w-3 h-3 text-green-400" />}
                    </span>
                    <span className={activeLine === "done" ? "text-green-300" : "text-slate-500"}>
                        {"// Array ordenado! ✓"}
                    </span>
                </div>
            </div>
        </div>
    )
}
