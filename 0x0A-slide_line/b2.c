#include "slide_line.h"

/**
 * push_to_left - push non-zero elements to the left edge of the array.
 * @line: A pointer to the array of integers to manipulate.
 * Return: nothing.
 */
void push_to_left(int *line);
{
	int j = 0, z = 0;

	while (line[j])
	{
		if (line[j] != 0)
			j++;
		else
		{
			z = j;
			while (line[z] && line[z] == 0)
				z++;
			if (line[z])
			{
				line[j] = line[z];
				line[z] = 0;
			}
		}
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
	size_t i, start, end, tmp;

	start = 0;
	end = size - 1;
	tmp = start;
	i = start + 1;

	while (line[i])
	{
		while (i <= end && line[i] == 0)
			i += 1;
		if (line[tmp] == line[i])
		{
			line[tmp] = line[tmp] * 2;
			line[i] = 0;
			tmp = i;
			while (tmp + 1 <= end && line[tmp] == 0)
				tmp += 1;
			i = tmp + 1;
		}
		else
		{
			tmp = i;
			i += 1;
		}
	}

	push_to_left(line);

	return (1);
}

/**
 * slide_to_right - It slides and merges an array of integers to the right.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_to_right(int *line, size_t size)
{
	size_t i, start, end, tmp;

	start = size - 1;
	end = 0;

	i = start - 1;
	tmp = start;

	while (line[i])
	{
		while (i >= end && line[i] == 0)
			i -= 1;
		if (line[tmp] == line[i])
		{
			line[tmp] = line[tmp] * 2;
			line[i] = 0;
			tmp = i;
			while (tmp - 1 >= end && line[tmp] == 0)
				tmp -= 1;
			i = tmp - 1;
		}
		else
		{
			tmp = i;
			i -= 1;
		}
	}

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
