#include <stdio.h>
#include <stdlib.h>
#include "grid.h"


int main(void) {

    int *grid = create_grid();
    display_grid(grid);

    return EXIT_SUCCESS;
}
