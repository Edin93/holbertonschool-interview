#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * is_grid_stable - Check if a grid is stable or not.
 * @grid: the 2 dimentional grid to check.
 * @unstable: a pointer to the variable reflecting the grid stability.
 */
void is_grid_stable(int grid[3][3], int *unstable)
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("grid[%d][%d] = %d\n", i, j, grid[i][j]);
	}
	printf("unstable = %d\n--------------------------------\n", *unstable);
}
/**
 * sandpiles_sum - Computes the sum of 2 sandpiles and make grid1 stable.
 * @grid1: a 2 dimentional array of integers between 0 and 3.
 * @grid2: a 2 dimentional array of integers between 0 and 3.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0;
	int tmp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	is_grid_stable(grid1, &unstable);
	is_grid_stable(grid2, &unstable);
	is_grid_stable(tmp, &unstable);
}
