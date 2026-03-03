"use client"

import { Algorithm } from "@/lib/types"
import { CheckCircle2, Lock } from "lucide-react"

const algorithms: Algorithm[] = [
    { id: "insertion-sort", name: "Insertion Sort", available: true },
    { id: "bubble-sort", name: "Bubble Sort", available: false },
    { id: "selection-sort", name: "Selection Sort", available: false },
    { id: "merge-sort", name: "Merge Sort", available: false },
    { id: "quick-sort", name: "Quick Sort", available: false },
    { id: "heap-sort", name: "Heap Sort", available: false },
    { id: "counting-sort", name: "Counting Sort", available: false },
    { id: "radix-sort", name: "Radix Sort", available: false },
]

interface SidebarProps {
    activeAlgorithm: string
    onSelect: (id: string) => void
}

export function Sidebar({ activeAlgorithm, onSelect }: SidebarProps) {
    return (
        <aside className="w-56 bg-slate-900 border-r border-slate-700 flex flex-col py-6 shrink-0">
            <p className="text-xs font-semibold text-slate-400 uppercase tracking-wider px-4 mb-3">
                Algoritmos
            </p>
            <nav className="flex flex-col gap-1 px-2">
                {algorithms.map((algo) => {
                    const isActive = algo.id === activeAlgorithm
                    return (
                        <button
                            key={algo.id}
                            onClick={() => algo.available && onSelect(algo.id)}
                            disabled={!algo.available}
                            className={`
                flex items-center gap-2 px-3 py-2 rounded-lg text-sm font-medium transition-all
                ${isActive
                                    ? "bg-slate-700 text-cyan-400 border-l-2 border-cyan-400"
                                    : algo.available
                                        ? "text-slate-300 hover:bg-slate-800 hover:text-slate-100 cursor-pointer"
                                        : "text-slate-600 cursor-not-allowed"
                                }
              `}
                        >
                            {algo.available ? (
                                <CheckCircle2 className={`w-4 h-4 shrink-0 ${isActive ? "text-cyan-400" : "text-green-500"}`} />
                            ) : (
                                <Lock className="w-4 h-4 shrink-0 text-slate-600" />
                            )}
                            {algo.name}
                            {!algo.available && (
                                <span className="ml-auto text-xs text-slate-600">em breve</span>
                            )}
                        </button>
                    )
                })}
            </nav>
        </aside>
    )
}
