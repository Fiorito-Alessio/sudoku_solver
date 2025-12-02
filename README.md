# C-Sudoku Solver

A lightweight, efficient, and memory-safe command-line tool written in C that solves 9x9 Sudoku puzzles. This project was developed to demonstrate low-level memory management, pointer arithmetic, and recursive algorithmic logic.

## How it Works

The core of the application relies on a **Recursive Backtracking Algorithm**, a "brute-force" approach optimized with constraint checking.

1.  **Scan:** The program searches the grid for the first empty cell (represented by `0`).
2.  **Hypothesize:** It attempts to place numbers from `1` to `9` in that cell.
3.  **Validate:** A helper function checks if the number is legal according to Sudoku rules (it must be unique in its Row, Column, and 3x3 Subgrid).
4.  **Recurse:** If the number is valid, the function calls itself to solve the *rest* of the grid.
5.  **Backtrack:** If the algorithm hits a dead end (no valid numbers can be placed), it returns to the previous cell, resets it to `0` (empty), and tries the next possible number.

## Input Format

The solver reads the puzzle from a plain text file (e.g., `data.txt`). The format expects a continuous stream of digits representing the 9x9 grid, where:

* **Digits 1-9:** Represent pre-filled cells.
* **Digit 0:** Represents empty cells to be solved.
* **Newlines:** Are ignored by the parser but recommended for readability.

**Example `data.txt` content:**

```text
500062300
060000000
009000500
001400002
000008040
000700006
070001084
130000000
040820000
```
