# N-Queens Solver

Iterative backtracking solver for the N-Queens problem, implemented in C++ without recursion.

## Problem

Place N non-attacking queens on an N×N chessboard such that no two queens share the same row, column, or diagonal. The solver supports **pre-placed queens** — given a partial board configuration, it finds a valid completion or reports that none exists.

## Technical Highlights

- **No recursion** — uses an explicit `std::stack` to simulate the backtracking search tree
- **Pre-placed queen support** — arbitrary initial configurations are handled before the search begins
- **Board state restoration** — each stack frame tracks the expected queen count, allowing O(1) rollback
- **C++17**, compiled with `-Wall`

## Build

```bash
make
```

Requires `g++` with C++17 support. Produces a `main` executable.

```bash
make clean   # remove object files and binary
```

## Usage

```
./main <input_file> <output_file>
```

Each line of the input file describes one problem. The solver writes one result line per problem to the output file.

## Input / Output Format

**Input line:** `N [row1 col1] [row2 col2] ...`

- `N` — board size and number of queens to place
- Optional space-separated `(row, col)` pairs for pre-placed queens (1-indexed)

**Output line:** space-separated `row col` pairs sorted by column, or `No solution`

### Example

`simple-input.txt`:
```
3 1 1
4 1 1
4 1 2
```

`simple-output.txt`:
```
No solution
No solution
1 2 2 4 3 1 4 3
```

- Line 1: 3-queens with a queen at (1,1) — no valid completion exists
- Line 2: 4-queens with a queen at (1,1) — no valid completion exists
- Line 3: 4-queens with a queen at (1,2) — solved: queens at columns 2, 4, 1, 3

## File Structure

| File | Description |
|------|-------------|
| `main.cpp` | Entry point — file I/O, input parsing, output formatting |
| `board.h` / `board.cpp` | `Board` class — queen placement, conflict detection, row/column tracking |
| `solveNQueens.h` / `solveNQueens.cpp` | Iterative backtracking solver using explicit stack |
| `Makefile` | Build system |
| `simple-input.txt` / `simple-output.txt` | Basic test cases |
| `Tests/` | Additional test cases (4-queens, 5-queens, larger boards) |
| `Helper/` | Java utility for visualizing board solutions |
