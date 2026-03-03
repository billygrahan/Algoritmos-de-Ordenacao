import { useState, useCallback, useEffect, useRef } from "react"
import { SortStep } from "@/lib/types"

type PlayerState = "idle" | "playing" | "paused" | "finished"

export function useAlgorithmPlayer(steps: SortStep[]) {
    const [currentStep, setCurrentStep] = useState(0)
    const [playerState, setPlayerState] = useState<PlayerState>("idle")
    const [speed, setSpeed] = useState(1) // 1 = normal, 0.25 = lento, 3 = rápido
    const intervalRef = useRef<NodeJS.Timeout | null>(null)

    const totalSteps = steps.length

    const clearTimer = useCallback(() => {
        if (intervalRef.current) {
            clearInterval(intervalRef.current)
            intervalRef.current = null
        }
    }, [])

    const goToStep = useCallback(
        (step: number) => {
            const clamped = Math.max(0, Math.min(step, totalSteps - 1))
            setCurrentStep(clamped)
            if (clamped === totalSteps - 1) {
                setPlayerState("finished")
                clearTimer()
            }
        },
        [totalSteps, clearTimer]
    )

    const next = useCallback(() => {
        setCurrentStep((prev) => {
            const next = prev + 1
            if (next >= totalSteps - 1) {
                setPlayerState("finished")
                clearTimer()
                return totalSteps - 1
            }
            return next
        })
    }, [totalSteps, clearTimer])

    const prev = useCallback(() => {
        clearTimer()
        setPlayerState("paused")
        setCurrentStep((prev) => Math.max(0, prev - 1))
    }, [clearTimer])

    const play = useCallback(() => {
        if (currentStep >= totalSteps - 1) {
            setCurrentStep(0)
        }
        setPlayerState("playing")
    }, [currentStep, totalSteps])

    const pause = useCallback(() => {
        clearTimer()
        setPlayerState("paused")
    }, [clearTimer])

    const reset = useCallback(() => {
        clearTimer()
        setCurrentStep(0)
        setPlayerState("idle")
    }, [clearTimer])

    const goToEnd = useCallback(() => {
        clearTimer()
        setCurrentStep(totalSteps - 1)
        setPlayerState("finished")
    }, [totalSteps, clearTimer])

    // Gerencia o intervalo de play
    useEffect(() => {
        if (playerState === "playing") {
            const delay = Math.round(1000 / speed)
            intervalRef.current = setInterval(() => {
                next()
            }, delay)
        } else {
            clearTimer()
        }
        return clearTimer
    }, [playerState, speed, next, clearTimer])

    const activeStep = steps[currentStep] ?? steps[0]

    return {
        activeStep,
        currentStep,
        totalSteps,
        playerState,
        speed,
        setSpeed,
        play,
        pause,
        next,
        prev,
        reset,
        goToEnd,
        goToStep,
        isPlaying: playerState === "playing",
        isFinished: playerState === "finished",
        canGoNext: currentStep < totalSteps - 1,
        canGoPrev: currentStep > 0,
    }
}
