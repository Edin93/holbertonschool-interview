#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer n is a palindrome.
 * @n: the number n to check if it's a palindrome.
 * Return: 1 if n is a palindrome, otherwise 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long x, y, num = n, div = 1;

	if (num < 10)
		return (1);

	while (num / (div * 10) >= 1)
		div *= 10;

	while (div > 1)
	{
		x = num / div;
		y = num % 10;
		if (x != y)
			return (0);
		num = num - (x * div);
		num = num / 10;
		div = div / 100;
	}
	return (1);
}
