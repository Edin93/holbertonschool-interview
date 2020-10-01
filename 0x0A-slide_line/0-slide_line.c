#include "slide_line.h"

/**
 * push_to_left - push non-zero elements to the left edge of the array.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: nothing.
 */
void push_to_left(int *line, size_t size)
{
	int j = 0;
	int z = 0;

	while (j < (int)size)
	{
		while (j + 1 < (int)size && line[j] != 0)
			j++;
		z = j;
		while (z + 1 < (int)size && line[z] == 0)
			z++;
		if (z < (int)size - 1)
		{
			line[j] = line[z];
			line[z] = 0;
		}
		j++;
	}
}

/**
 * slide_to_left - It slides and merges an array of integers to the left.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_to_left(int *line, size_t size)
{
	int tmp = 0;
	int i = 1;

	while (i < (int)size)
	{
		while (i + 1 < (int)size && line[i] == 0)
			i++;
		if (line[tmp] == 0)
		{
			line[tmp] = line[i];
			line[i] = 0;
			i++;
		}
		else if (line[tmp] == line[i] && line[i] != 0)
		{
			line[tmp] = line[tmp] * 2;
			line[i] = 0;
			tmp = i;
			i++;
		}
		else
		{
			tmp = i;
			i++;
		}
	}

	push_to_left(line, size);

	return (1);
}

/**
 * push_to_right - push non-zero elements to the right edge of the array.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: nothing.
 */
void push_to_right(int *line, int size)
{
	int j = (int)size - 1;
	int z = j;

	while (j >= 0)
	{
		while (j - 1 >= 0 && line[j] != 0)
			j--;
		z = j;
		while (z > 0 && line[z] == 0)
			z--;
		line[j] = line[z];
		if (j > 0)
		{
			line[z] = 0;
		}
		j--;
	}
}

/**
 * slide_to_right - It slides and merges an array of integers to the right.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_to_right(int *line, size_t size)
{
	int tmp = (int)size - 1;
	int i = tmp - 1;

	while (i >= 0)
	{
		while (i - 1 > 0 && line[i] == 0)
			i--;
		if (line[tmp] == 0)
		{
			line[tmp] = line[i];
			line[i] = 0;
			i--;
		}
		else if (line[tmp] == line[i] && line[i] != 0)
		{
			line[tmp] = line[tmp] * 2;
			line[i] = 0;
			tmp = i;
			i--;
		}
		else
		{
			tmp = i;
			i--;
		}
	}

	push_to_right(line, (int)size);

	return (1);
}

/**
 * slide_line - It slides and merges an array of integers.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * @direction: The direction to which the array should be merged,
 * It can either be SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (size < 2)
		return (1);
	if (direction == 1)
		return (slide_to_right(line, size));
	return (slide_to_left(line, size));
}
