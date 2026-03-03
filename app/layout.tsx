import type { Metadata } from "next";
import { Inter, JetBrains_Mono } from "next/font/google";
import "./globals.css";
import { Header } from "@/components/Header";

const inter = Inter({ subsets: ["latin"], variable: "--font-inter" });
const jetbrains = JetBrains_Mono({ subsets: ["latin"], variable: "--font-mono" });

export const metadata: Metadata = {
  title: "AlgoVisual — PAA",
  description:
    "Visualizador interativo de algoritmos de ordenação para Projeto e Análise de Algoritmos",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="pt-BR" className="dark">
      <body
        className={`${inter.variable} ${jetbrains.variable} antialiased bg-slate-950 text-slate-100 min-h-screen flex flex-col`}
      >
        <Header />
        {children}
      </body>
    </html>
  );
}
