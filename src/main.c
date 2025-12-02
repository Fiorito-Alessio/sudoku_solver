#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "solver.h"


int main(void) {
    int *grid = create_grid();
    if (!grid) {
        fprintf(stderr, "cannot create grid\n");
        return EXIT_FAILURE;
    }

    printf("Initial grid :\n");
    display_grid(grid);

    if (solve(grid)) {
        printf("\nSudoku completed successfully !\n");
        display_grid(grid);
    } else {
        printf("\nSudoku is impossible.\n");
    }

    return EXIT_SUCCESS;
}
