"use client"

import { useState } from "react"
import { generateInsertionSortSteps } from "@/lib/insertionSort"
import { useAlgorithmPlayer } from "@/hooks/useAlgorithmPlayer"
import { ArrayInput } from "./ArrayInput"
import { ArrayVisualizer } from "./ArrayVisualizer"
import { StepDescription } from "./StepDescription"
import { PseudoCode } from "./PseudoCode"
import { ControlPanel } from "./ControlPanel"

export function InsertionSortVisualizer() {
    const [steps, setSteps] = useState(() =>
        generateInsertionSortSteps([34, 9, -81, 71])
    )
    const player = useAlgorithmPlayer(steps)

    const handleStart = (arr: number[]) => {
        const newSteps = generateInsertionSortSteps(arr)
        setSteps(newSteps)
        player.reset()
    }

    return (
        <div className="flex flex-col gap-4 w-full">
            {/* Input */}
            <ArrayInput onStart={handleStart} />

            {/* Visualização principal */}
            <div className="grid grid-cols-1 xl:grid-cols-2 gap-4">
                <div className="flex flex-col gap-4">
                    <ArrayVisualizer step={player.activeStep} />
                    <StepDescription
                        step={player.activeStep}
                        currentStep={player.currentStep}
                        totalSteps={player.totalSteps}
                    />
                    <ControlPanel
                        isPlaying={player.isPlaying}
                        isFinished={player.isFinished}
                        canGoNext={player.canGoNext}
                        canGoPrev={player.canGoPrev}
                        speed={player.speed}
                        onPlay={player.play}
                        onPause={player.pause}
                        onNext={player.next}
                        onPrev={player.prev}
                        onReset={player.reset}
                        onGoToEnd={player.goToEnd}
                        onSpeedChange={player.setSpeed}
                    />
                </div>
                <PseudoCode activeLine={player.activeStep.activeLine} />
            </div>
        </div>
    )
}
