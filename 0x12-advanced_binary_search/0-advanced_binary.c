#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "search_algos.h"

void print_int(int n)
{
	int div = 1;
	int tmp = 0;

	while (n / (div * 10) > 1)
		div *= 10;
	while (div > 1)
	{
		tmp = n / div;
		putchar(tmp + "0");
		n = n - tmp;
		div = div / 10;
	}
}

void print_array(int *array, size_t start, size_t end)
{
	size_t i = start;

	write(1, "Searching in array: ", 1024);
	while (i <= end)
		print_int(array[i]);
}

/*
 * advanced_binary - Searches for a value in a sorted array of integers.
 *
 * @array: A pointer to the first element of the sorted (ascending order)
 * array to search in.
 * @size: the number of elements in the array.
 * @value: the value to search for.
 *
 * Return: the index of the value if it exists. otherwise -1.
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t i = 0;

	printf("size = %zu\n", size);
	printf("value = %d\n", value);

	for (i = 0; i < size; i++)
		print_int(array[i]);

	return (0);
}
