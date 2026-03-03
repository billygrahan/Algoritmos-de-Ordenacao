"use client"

import { SortStep } from "@/lib/types"
import { Info, ArrowRight, ArrowLeftRight, CheckCircle2, MoveRight } from "lucide-react"

interface StepDescriptionProps {
    step: SortStep
    currentStep: number
    totalSteps: number
}

const phaseConfig = {
    idle: { icon: Info, color: "text-slate-400", bg: "bg-slate-700/50 border-slate-600", label: "Início" },
    extractKey: { icon: MoveRight, color: "text-amber-400", bg: "bg-amber-900/20 border-amber-700", label: "Extraindo chave" },
    compare: { icon: ArrowLeftRight, color: "text-red-400", bg: "bg-red-900/20 border-red-700", label: "Comparando" },
    shift: { icon: ArrowRight, color: "text-pink-400", bg: "bg-pink-900/20 border-pink-700", label: "Deslocando" },
    insert: { icon: MoveRight, color: "text-cyan-400", bg: "bg-cyan-900/20 border-cyan-700", label: "Inserindo" },
    done: { icon: CheckCircle2, color: "text-green-400", bg: "bg-green-900/20 border-green-700", label: "Concluído" },
}

export function StepDescription({ step, currentStep, totalSteps }: StepDescriptionProps) {
    const config = phaseConfig[step.phase] ?? phaseConfig.idle
    const Icon = config.icon
    const progress = totalSteps > 1 ? (currentStep / (totalSteps - 1)) * 100 : 0

    return (
        <div className={`rounded-xl border p-5 transition-colors ${config.bg}`}>
            <div className="flex items-center justify-between mb-3">
                <div className="flex items-center gap-2">
                    <Icon className={`w-4 h-4 ${config.color}`} />
                    <span className={`text-xs font-semibold uppercase tracking-wide ${config.color}`}>
                        {config.label}
                    </span>
                </div>
                <span className="text-slate-400 text-xs font-mono">
                    Passo {currentStep + 1} / {totalSteps}
                </span>
            </div>

            {/* Barra de progresso */}
            <div className="w-full bg-slate-700 rounded-full h-1.5 mb-3">
                <div
                    className={`h-1.5 rounded-full transition-all duration-300 ${step.phase === "done" ? "bg-green-500" : "bg-cyan-500"
                        }`}
                    style={{ width: `${progress}%` }}
                />
            </div>

            <p className="text-slate-200 text-sm leading-relaxed">{step.description}</p>
        </div>
    )
}
