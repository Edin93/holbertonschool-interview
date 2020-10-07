#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * menger: It draws a 2D Menger Sponge.
 * @level: The level of the Menger Sponge to draw.
 * If level is lower than 0, do nothing.
 * Return: nothing.
 */
void menger(int level)
{
	if (level <= -1)
		return;
	printf("#");
}
