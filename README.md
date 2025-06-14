# Rush 01 — Skyscraper Puzzle

![42 Project](https://img.shields.io/badge/42%20School-Project-blue)
![Language](https://img.shields.io/badge/language-C-informational)
![License](https://img.shields.io/badge/status-Completed-success)

> Weekend group project at 42 School.  
> The goal is to build a logic-based puzzle solver for a simplified version of the "Skyscraper" game using C.

## 🧠 Project Overview

Rush 01 challenges students to implement a puzzle-solving algorithm in C for a variant of the **Skyscraper** puzzle. The player must fill a 4x4 grid with numbers `1` to `4`, ensuring that:

- No number repeats in any row or column (like Sudoku)
- Clues on the sides of the grid indicate how many skyscrapers (numbers) are visible from that direction
- A taller building hides shorter ones behind it

The program must parse input constraints and output the valid solution — or print `Error` if no solution exists.

## 🎯 Rules

- Grid size: 4x4  
- Only one correct solution should be printed  
- Input is a single string of 16 numbers (from 1 to 4) separated by spaces, representing clues in this order:


