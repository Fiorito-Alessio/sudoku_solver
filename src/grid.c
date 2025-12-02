#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_ROWS 9
#define GRID_COLS 9

// create a grid to be populated by a .txt file
// if memory allocation succeeded and data is properly set inside grid, then return a pointer to the grid
// returns NULL otherwise
int *create_grid(void) {
    int *grid = calloc(GRID_ROWS * GRID_COLS, sizeof(int));

    if (!grid) {
        fprintf(stderr, "cannot allocate memory to create grid\n");
        return NULL;
    }

    int status = populate_grid(grid, "data.txt");

    if (status != 0) {
        fprintf(stderr, "error while allocating grid\n");
        free(grid);
        return NULL;
    }

    return grid;
}

// read a data file and populate each grid cell with a valid number
// return status 1 if any fails happen
// returns 0 if data is set correctly in the grid
int populate_grid(int *grid, const char *filename) {
    FILE *grid_data = fopen(filename, "r");

    if (!grid_data) {
        fprintf(stderr, "cannot open grid data file (%s)\n", filename);
        return 1;
    }

    int current_row = 0;
    int current_col = 0;
    int c;
    while ((c = fgetc(grid_data)) != EOF) {
        if (c == '\n' || c == '\r' || c == ' ') {
            continue;
        }

        if (c < '0' || c > '9') {
            fprintf(stderr, "detection of an invalid number.\n");
            fclose(grid_data);
            return 1;
        }

        grid[(current_row * GRID_COLS) + current_col] = c - '0';
        current_col++;

        if (current_col == 9) {
            current_col = 0;
            current_row++;
        }

        if (current_row == 9) {
            break;
        }
    }
    fclose(grid_data);
    return 0;
}


void display_grid(int *grid) {
    printf("\n+-------+-------+-------+\n");

    for (int i = 0; i < GRID_ROWS; i++) {
        usleep(10000);
        printf("| ");
        for (int j = 0; j < GRID_COLS; j++) {
            int value = grid[(i * GRID_COLS) + j];

            if (value == 0) {
                usleep(10000);
                fflush(stdout);
                printf(". ");
            } else {
                usleep(10000);
                fflush(stdout);
                printf("%d ", value);
            }

            if ((j + 1) % 3 == 0) {
                usleep(10000);
                fflush(stdout);
                printf("| ");
            }
        }

        printf("\n");

        if ((i + 1) % 3 == 0) {
            usleep(10000);
            fflush(stdout);
            printf("+-------+-------+-------+\n");
        }
    }
}
