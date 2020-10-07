#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * menger - It draws a 2D Menger Sponge.
 * @level: The level of the Menger Sponge to draw.
 * If level is lower than 0, do nothing.
 * Return: nothing.
 */
void menger(int level)
{
	int r, c, s;
	int x, y;
	char p[1];

	if (level <= -1)
		return;

	s = (int)pow(3, level);

	for (r = 0; r < s; r++)
	{
		for (c = 0; c < s;)
		{
			p[0] = '#';
			x = r;
			y = c++;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					p[0] = ' ';
				}
				x /= 3;
				y /= 3;
			}
			putchar(p[0]);
		}
		printf("\n");
	}
}
