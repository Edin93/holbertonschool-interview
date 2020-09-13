#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer n is a palindrome.
 * @n: the number n to check if it's a palindrome.
 * Return: 1 if n is a palindrome, otherwise 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long x, y;
	unsigned long div = 1;

	if (n < 10)
		return (1);

	while (n / (div * 10) >= 1)
		div *= 10;

	while (div > 1)
	{
		x = n / div;
		y = n % 10;
		if (x != y)
			return (0);
		n = n - (x * div);
		n = n / 10;
		div = div / 100;
	}
	return (1);
}
