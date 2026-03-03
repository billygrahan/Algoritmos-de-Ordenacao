"use client"

import { ArrayElement, BlockState } from "@/lib/types"

interface ArrayBlockProps {
  element: ArrayElement
  showPointer?: "i" | "j" | "key" | null
}

const stateConfig: Record<
  BlockState,
  { bg: string; border: string; text: string; label?: string }
> = {
  default:     { bg: "bg-cyan-500/20",   border: "border-cyan-500",   text: "text-cyan-300" },
  sorted:      { bg: "bg-green-500/20",  border: "border-green-500",  text: "text-green-300" },
  key:         { bg: "bg-amber-500/20",  border: "border-amber-400",  text: "text-amber-300", label: "key" },
  "pointer-i": { bg: "bg-purple-500/20", border: "border-purple-400", text: "text-purple-300" },
  "pointer-j": { bg: "bg-red-500/20",   border: "border-red-400",    text: "text-red-300" },
  shifting:    { bg: "bg-pink-500/20",  border: "border-pink-400",   text: "text-pink-300", label: "→" },
  slot:        { bg: "bg-orange-500/10", border: "border-orange-400 border-dashed", text: "text-orange-400" },
  comparing:   { bg: "bg-yellow-500/20", border: "border-yellow-400", text: "text-yellow-300" },
}

export function ArrayBlock({ element, showPointer }: ArrayBlockProps) {
  const cfg = stateConfig[element.state] ?? stateConfig.default
  const isSlot = element.state === "slot"

  return (
    <div className="flex flex-col items-center gap-1 select-none">
      {/* Ponteiro acima */}
      <div className="h-5 flex items-center justify-center">
        {showPointer === "i" && (
          <span className="text-purple-400 text-xs font-bold font-mono bg-purple-900/40 px-1.5 py-0.5 rounded">
            i
          </span>
        )}
        {showPointer === "j" && (
          <span className="text-red-400 text-xs font-bold font-mono bg-red-900/40 px-1.5 py-0.5 rounded">
            j
          </span>
        )}
        {showPointer === "key" && (
          <span className="text-amber-400 text-xs font-bold font-mono bg-amber-900/40 px-1.5 py-0.5 rounded">
            key
          </span>
        )}
      </div>

      {/* Bloco */}
      <div
        className={`
          w-14 h-14 flex items-center justify-center rounded-xl border-2
          font-mono font-bold text-lg transition-all duration-300
          ${cfg.bg} ${cfg.border} ${cfg.text}
          ${isSlot ? "opacity-50" : "opacity-100"}
        `}
      >
        {isSlot ? (
          <span className="text-orange-400 text-xl">_</span>
        ) : (
          element.value
        )}
      </div>

      {/* Índice abaixo */}
      <span className="text-slate-500 text-xs font-mono">[{element.index}]</span>

      {/* Seta de ponteiro abaixo */}
      <div className="h-5 flex flex-col items-center justify-start">
        {showPointer === "i" && (
          <div className="flex flex-col items-center">
            <div className="w-px h-2 bg-purple-400" />
            <div className="w-0 h-0 border-l-4 border-r-4 border-t-[6px] border-l-transparent border-r-transparent border-t-purple-400" />
          </div>
        )}
        {showPointer === "j" && (
          <div className="flex flex-col items-center">
            <div className="w-px h-2 bg-red-400" />
            <div className="w-0 h-0 border-l-4 border-r-4 border-t-[6px] border-l-transparent border-r-transparent border-t-red-400" />
          </div>
        )}
      </div>
    </div>
  )
}
