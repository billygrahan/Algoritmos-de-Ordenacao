"use client"

import { SortStep } from "@/lib/types"
import { ArrayBlock } from "./ArrayBlock"

interface ArrayVisualizerProps {
    step: SortStep
}

const legendItems = [
    { color: "bg-cyan-500/20 border-cyan-500", label: "Não visitado" },
    { color: "bg-green-500/20 border-green-500", label: "Ordenado" },
    { color: "bg-amber-500/20 border-amber-400", label: "key (chave)" },
    { color: "bg-purple-500/20 border-purple-400", label: "Ponteiro i" },
    { color: "bg-red-500/20 border-red-400", label: "Ponteiro j" },
    { color: "bg-pink-500/20 border-pink-400", label: "Deslocando" },
    { color: "bg-orange-500/10 border-orange-400 border-dashed", label: "Slot livre" },
]

export function ArrayVisualizer({ step }: ArrayVisualizerProps) {
    const { elements, iPointer, jPointer, keyValue, keyExtracted } = step

    return (
        <div className="bg-slate-800 rounded-xl border border-slate-700 p-5">
            <h2 className="text-slate-200 font-semibold mb-5 text-sm uppercase tracking-wide">
                Visualização
            </h2>

            {/* Variáveis auxiliares */}
            <div className="flex gap-4 mb-6 flex-wrap">
                <div className={`flex items-center gap-2 px-3 py-1.5 rounded-lg border text-sm font-mono
          ${iPointer !== null ? "bg-purple-500/10 border-purple-500 text-purple-300" : "bg-slate-700 border-slate-600 text-slate-500"}`}>
                    <span className="font-bold">i</span>
                    <span className="text-slate-400">=</span>
                    <span>{iPointer !== null ? iPointer : "—"}</span>
                </div>
                <div className={`flex items-center gap-2 px-3 py-1.5 rounded-lg border text-sm font-mono
          ${jPointer !== null && jPointer >= 0 ? "bg-red-500/10 border-red-500 text-red-300" : "bg-slate-700 border-slate-600 text-slate-500"}`}>
                    <span className="font-bold">j</span>
                    <span className="text-slate-400">=</span>
                    <span>{jPointer !== null ? jPointer : "—"}</span>
                </div>
                <div className={`flex items-center gap-2 px-3 py-1.5 rounded-lg border text-sm font-mono
          ${keyExtracted ? "bg-amber-500/10 border-amber-400 text-amber-300" : "bg-slate-700 border-slate-600 text-slate-500"}`}>
                    <span className="font-bold">key</span>
                    <span className="text-slate-400">=</span>
                    <span>{keyValue !== null ? keyValue : "—"}</span>
                </div>
            </div>

            {/* Array blocks */}
            <div className="flex flex-wrap gap-3 mb-6 min-h-[110px] items-end">
                {elements.map((el) => {
                    const isI = el.index === iPointer && !keyExtracted
                    const isJ = el.index === jPointer && jPointer !== null && jPointer >= 0
                    const isKey = el.index === iPointer && keyExtracted && el.state !== "slot"

                    let pointer: "i" | "j" | "key" | null = null
                    if (isKey) pointer = "key"
                    else if (isI) pointer = "i"
                    else if (isJ) pointer = "j"

                    return (
                        <ArrayBlock
                            key={el.index}
                            element={el}
                            showPointer={pointer}
                        />
                    )
                })}
            </div>

            {/* Legenda */}
            <div className="flex flex-wrap gap-2 pt-4 border-t border-slate-700">
                {legendItems.map((item) => (
                    <div key={item.label} className="flex items-center gap-1.5">
                        <div className={`w-4 h-4 rounded border-2 ${item.color}`} />
                        <span className="text-slate-400 text-xs">{item.label}</span>
                    </div>
                ))}
            </div>
        </div>
    )
}
