"use client"

import { useState } from "react"
import { Sidebar } from "@/components/Sidebar"
import { InsertionSortVisualizer } from "@/components/InsertionSortVisualizer"

export default function HomePage() {
  const [activeAlgorithm, setActiveAlgorithm] = useState("insertion-sort")

  return (
    <div className="flex flex-1 h-[calc(100vh-65px)]">
      <Sidebar activeAlgorithm={activeAlgorithm} onSelect={setActiveAlgorithm} />
      <main className="flex-1 overflow-y-auto p-6">
        {activeAlgorithm === "insertion-sort" && <InsertionSortVisualizer />}
      </main>
    </div>
  )
}
