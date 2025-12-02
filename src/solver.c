#include "solver.h"
#include <stdio.h>
#include <stdlib.h>

#define GRID_ROWS 9
#define GRID_COLS 9 


bool is_legal(int n, int row, int col, int *grid) {
    // check for the row
    for (int i = 0; i < GRID_COLS; i++) {
        if (grid[(row * GRID_COLS) + i] == n) {
            return false;
        }
    }

    // check for the col
    for (int i = 0; i < GRID_ROWS; i++) {
        if (grid[(i * GRID_COLS) + col] == n) {
            return false;
        }
    }

    // check for the square
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int current_row = start_row + i;
            int current_col = start_col + j;

            int index = (current_row * GRID_COLS) + current_col;

            if (grid[index] == n) {
                return false;
            }
        }
    }

    return true;
}

bool solve(int *grid) {
    int row, col;
    bool is_empty = false;

    // find an empty spot if any
    for (row = 0; row < GRID_ROWS; row++) {
        for (col = 0; col < GRID_COLS; col++) {
            if (grid[(row * GRID_COLS) + col] == 0) {
                is_empty = true;
                break;
            }
        }

        if (is_empty) {
            break;
        }
    }

    // no more cell to fill... Its a win
    if (!is_empty) {
        return true;
    }

    // backtracking algorithm
    for (int value = 1; value <= 9; value++) {
        if (is_legal(value, row, col, grid)) {
            grid[(row * GRID_COLS) + col] = value;

            if (solve(grid)) { // we send modified grid
                return true;
            }

            grid[(row * GRID_COLS) + col] = 0; // put back 0 if at any point solve() returned false

        }

    }

    return false;
}
