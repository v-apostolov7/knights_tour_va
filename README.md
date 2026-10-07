# Knight's Tour Problem (Warnsdorff's Heuristic)

An optimized C implementation solving the classic **Knight's Tour** mathematical puzzle on an 8x8 chessboard using **Warnsdorff's algorithm**.

---

## Problem Overview

The **Knight's Tour** is a classic sequence of moves where a chess knight visits every square of the board exactly once. Finding a complete tour using naive backtracking has factorial time complexity and easily gets trapped.

This project implements **Warnsdorff's Heuristic**:
* At each step, the algorithm inspects all valid L-shaped knight moves from the current position.
* It evaluates the forward degree (number of unvisited onward moves) for each candidate.
* The knight prioritizes moving to the square with the **minimal onward accessibility degree**, preventing the knight from stranding itself early and finding a full 64-step path in linear time.

---

## Board Representation & Conventions

* **Coordinates:** Squares are designated by two-digit integers RC, where R is the row (1–8) and C is the column (1–8) (e.g., 11 is row 1, column 1; 88 is row 8, column 8).
* **State Markers:**
  * `k` — Current location of the knight.
  * `v` — Visited square.
  * `RC` — Unvisited square showing its coordinates.

---

## Tech Stack & Requirements

* **Language:** C (C99 / C11 compliant)
* **Compiler:** GCC (MinGW-w64 on Windows or native GCC on Linux/macOS)
* **Build Tools:** Command-line terminal / PowerShell

---

## Getting Started

### 1. Clone the repository
git clone https://github.com/v-apostolov7/knights_tour_va.git
cd knights_tour_va

### 2. Compile the source
gcc main.c -o knights_tour.exe

### 3. Run the application
.\knights_tour.exe

Or redirect all step-by-step boards to a file:
.\knights_tour.exe > tour_solution.txt

---

## How to Use

1. Launch the executable.
2. The initial numbered 8x8 board will be printed.
3. Enter your desired starting square when prompted (e.g., `11` for top-left, `45` for center).
4. The algorithm will sequentially display the board after every move until all 64 squares are covered.