#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - print a 3x3 grid.
 * @grid: the grid to print.
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

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
		{
			if (grid[i][j] > 3)
			{
				*unstable = 1;
				break;
			}
		}
	}
}
/**
 * sandpiles_sum - Computes the sum of 2 sandpiles and make grid1 stable.
 * @grid1: a 2 dimentional array of integers between 0 and 3.
 * @grid2: a 2 dimentional array of integers between 0 and 3.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 0, i, j;
	int grid1_copy[3][3] = {
		{1, 3, 1},
		{3, 3, 3},
		{1, 3, 1}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
				unstable = 1;
		}
	}

	while (unstable != 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				grid1_copy[i][j] = grid1[i][j];
		}
		printf("=\n");
		print_grid(grid1);
		unstable = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1_copy[i][j] > 3)
				{
					grid1[i][j] -= 4;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j + 1 <= 2)
						grid1[i][j + 1] += 1;
					if (i + 1 <= 2)
						grid1[i + 1][j] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
				}
			}
		}
		is_grid_stable(grid1, &unstable);
	}
}
