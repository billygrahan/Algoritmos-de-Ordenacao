"use client"

import { useState } from "react"
import { Plus, Minus, Shuffle, Play } from "lucide-react"

interface ArrayInputProps {
    onStart: (arr: number[]) => void
}

function randomInt(min: number, max: number) {
    return Math.floor(Math.random() * (max - min + 1)) + min
}

export function ArrayInput({ onStart }: ArrayInputProps) {
    const [values, setValues] = useState<string[]>(["34", "9", "-81", "71"])
    const [error, setError] = useState<string | null>(null)

    const updateValue = (index: number, val: string) => {
        const next = [...values]
        next[index] = val
        setValues(next)
        setError(null)
    }

    const addElement = () => {
        if (values.length >= 12) {
            setError("Máximo de 12 elementos.")
            return
        }
        setValues([...values, String(randomInt(-99, 99))])
    }

    const removeElement = (index: number) => {
        if (values.length <= 2) {
            setError("Mínimo de 2 elementos.")
            return
        }
        setValues(values.filter((_, i) => i !== index))
    }

    const shuffle = () => {
        setValues([...values].sort(() => Math.random() - 0.5))
    }

    const handleStart = () => {
        const parsed: number[] = []
        for (const v of values) {
            const n = parseInt(v, 10)
            if (isNaN(n)) {
                setError(`"${v}" não é um número inteiro válido.`)
                return
            }
            parsed.push(n)
        }
        setError(null)
        onStart(parsed)
    }

    return (
        <div className="bg-slate-800 rounded-xl border border-slate-700 p-5">
            <h2 className="text-slate-200 font-semibold mb-4 text-sm uppercase tracking-wide">
                Elementos do Array
            </h2>

            <div className="flex flex-wrap gap-2 mb-4">
                {values.map((val, i) => (
                    <div key={i} className="flex items-center gap-1">
                        <div className="flex flex-col items-center">
                            <input
                                type="number"
                                value={val}
                                onChange={(e) => updateValue(i, e.target.value)}
                                className={`
                  w-16 text-center bg-slate-700 border rounded-lg px-2 py-2
                  text-slate-100 font-mono text-sm focus:outline-none focus:border-cyan-400
                  transition-colors
                  ${val === "" || isNaN(parseInt(val)) ? "border-red-500" : "border-slate-600"}
                `}
                            />
                            <span className="text-slate-500 text-xs mt-1">[{i}]</span>
                        </div>
                        {values.length > 2 && (
                            <button
                                onClick={() => removeElement(i)}
                                className="text-slate-500 hover:text-red-400 transition-colors self-start mt-1"
                                title="Remover"
                            >
                                <Minus className="w-3 h-3" />
                            </button>
                        )}
                    </div>
                ))}
            </div>

            {error && (
                <p className="text-red-400 text-xs mb-3">{error}</p>
            )}

            <div className="flex flex-wrap gap-2">
                <button
                    onClick={addElement}
                    className="flex items-center gap-1.5 px-3 py-1.5 rounded-lg bg-slate-700 hover:bg-slate-600 text-slate-300 text-sm transition-colors"
                >
                    <Plus className="w-4 h-4" /> Adicionar
                </button>
                <button
                    onClick={shuffle}
                    className="flex items-center gap-1.5 px-3 py-1.5 rounded-lg bg-slate-700 hover:bg-slate-600 text-slate-300 text-sm transition-colors"
                >
                    <Shuffle className="w-4 h-4" /> Embaralhar
                </button>
                <button
                    onClick={handleStart}
                    className="flex items-center gap-1.5 px-4 py-1.5 rounded-lg bg-cyan-500 hover:bg-cyan-400 text-slate-900 font-semibold text-sm transition-colors ml-auto"
                >
                    <Play className="w-4 h-4" /> Iniciar Visualização
                </button>
            </div>
        </div>
    )
}
