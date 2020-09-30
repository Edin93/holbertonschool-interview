#include "slide_line.h"

/**
 * slide_to_left: It slides and merges an array of integers to the left.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_to_left(int *line, size_t size)
{
	size_t i, j, start, end;

	start = 0;
	end = size - 1;

	return (1);
}

/**
 * slide_to_right: It slides and merges an array of integers to the right.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_to_right(int *line, size_t size)
{
	size_t i, j, start, end;

	start = size - 1;
	end = 0;

	i = start;

        while ((direction == 1 && i >= end) || (direction == 2 && i <= end))
        {
                if (line[i] % 2 != 0)
                        return (0);
                if (direction == 1 && i - 1 >= end)
                        j = i - 1;
                else if (direction == 2 && i + 1 <= end)
                        j = i + 1;
        }

	return (1);
}

/**
 * slide_line: It slides and merges an array of integers.
 * @line: A pointer to the array of integers to manipulate.
 * @size: The number of the array's elements.
 * @direction: The direction to which the array should be merged,
 * It can either be SLIDE_LEFT or SLIDE_RIGHT.
 * Return: 1 upon success, 0 otherwise.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j, start, end;

	if (direction == 1)
		return (slide_to_right(line, size));
	return (slide_to_left(line, size));
}
