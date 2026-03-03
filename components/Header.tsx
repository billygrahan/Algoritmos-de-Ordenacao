"use client"

import { BarChart2 } from "lucide-react"

export function Header() {
    return (
        <header className="bg-slate-900 border-b border-slate-700 px-6 py-4 flex items-center gap-4">
            <div className="flex items-center gap-2">
                <BarChart2 className="text-cyan-400 w-7 h-7" />
                <span className="text-cyan-400 font-bold text-xl tracking-tight">
                    AlgoVisual
                </span>
            </div>
            <div className="h-6 w-px bg-slate-600" />
            <div>
                <p className="text-slate-200 font-semibold text-sm leading-tight">
                    Projeto e Análise de Algoritmos — PAA
                </p>
                <p className="text-slate-400 text-xs">
                    Visualizador interativo de algoritmos de ordenação
                </p>
            </div>
        </header>
    )
}
