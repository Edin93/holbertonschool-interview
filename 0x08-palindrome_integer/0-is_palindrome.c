#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer n is a palindrome.
 * @n: the number n to check if it's a palindrome.
 * Return: 1 if n is a palindrome, otherwise 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long div = 1;

	while (n / (div * 10) >= 1)
		div *= 10;

	while (div > 1)
	{
		if (n / div != n % 10)
			return (0);
		n = n - ((n / div) * div);
		n = n / 10;
		div = div / 100;
	}
	return (1);
}
