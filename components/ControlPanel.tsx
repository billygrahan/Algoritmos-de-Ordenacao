"use client"

import {
    StepBack,
    Play,
    Pause,
    StepForward,
    SkipForward,
    RotateCcw,
} from "lucide-react"

interface ControlPanelProps {
    isPlaying: boolean
    isFinished: boolean
    canGoNext: boolean
    canGoPrev: boolean
    speed: number
    onPlay: () => void
    onPause: () => void
    onNext: () => void
    onPrev: () => void
    onReset: () => void
    onGoToEnd: () => void
    onSpeedChange: (s: number) => void
}

const speedOptions = [0.25, 0.5, 1, 1.5, 2, 3]

function IconBtn({
    onClick,
    disabled,
    children,
    title,
    className = "",
}: {
    onClick: () => void
    disabled?: boolean
    children: React.ReactNode
    title?: string
    className?: string
}) {
    return (
        <button
            onClick={onClick}
            disabled={disabled}
            title={title}
            className={`
        p-2.5 rounded-lg transition-all
        ${disabled
                    ? "text-slate-600 cursor-not-allowed"
                    : "text-slate-300 hover:bg-slate-600 hover:text-slate-100 active:scale-95"}
        ${className}
      `}
        >
            {children}
        </button>
    )
}

export function ControlPanel({
    isPlaying,
    isFinished,
    canGoNext,
    canGoPrev,
    speed,
    onPlay,
    onPause,
    onNext,
    onPrev,
    onReset,
    onGoToEnd,
    onSpeedChange,
}: ControlPanelProps) {
    return (
        <div className="bg-slate-800 rounded-xl border border-slate-700 px-5 py-4">
            <div className="flex items-center justify-between flex-wrap gap-4">
                {/* Controles de navegação */}
                <div className="flex items-center gap-1 bg-slate-900 rounded-xl p-1">
                    <IconBtn onClick={onReset} title="Reiniciar">
                        <RotateCcw className="w-4 h-4" />
                    </IconBtn>
                    <IconBtn onClick={onPrev} disabled={!canGoPrev} title="Passo anterior">
                        <StepBack className="w-5 h-5" />
                    </IconBtn>

                    {isPlaying ? (
                        <button
                            onClick={onPause}
                            className="p-2.5 rounded-lg bg-cyan-500 hover:bg-cyan-400 text-slate-900 transition-all active:scale-95"
                            title="Pausar"
                        >
                            <Pause className="w-5 h-5" />
                        </button>
                    ) : (
                        <button
                            onClick={onPlay}
                            disabled={isFinished && !canGoPrev}
                            className={`
                p-2.5 rounded-lg transition-all active:scale-95
                ${isFinished
                                    ? "bg-green-600 hover:bg-green-500 text-white"
                                    : "bg-cyan-500 hover:bg-cyan-400 text-slate-900"}
                ${isFinished && !canGoPrev ? "opacity-50 cursor-not-allowed" : ""}
              `}
                            title="Reproduzir"
                        >
                            <Play className="w-5 h-5" />
                        </button>
                    )}

                    <IconBtn onClick={onNext} disabled={!canGoNext} title="Próximo passo">
                        <StepForward className="w-5 h-5" />
                    </IconBtn>
                    <IconBtn onClick={onGoToEnd} disabled={!canGoNext} title="Ir ao final">
                        <SkipForward className="w-5 h-5" />
                    </IconBtn>
                </div>

                {/* Controle de velocidade */}
                <div className="flex items-center gap-3">
                    <span className="text-slate-400 text-xs font-medium">Velocidade:</span>
                    <div className="flex items-center gap-1 bg-slate-900 rounded-xl p-1">
                        {speedOptions.map((s) => (
                            <button
                                key={s}
                                onClick={() => onSpeedChange(s)}
                                className={`
                  px-3 py-1.5 rounded-lg text-xs font-mono font-semibold transition-all
                  ${speed === s
                                        ? "bg-cyan-500 text-slate-900"
                                        : "text-slate-400 hover:text-slate-200 hover:bg-slate-700"}
                `}
                            >
                                {s}x
                            </button>
                        ))}
                    </div>
                </div>
            </div>
        </div>
    )
}
