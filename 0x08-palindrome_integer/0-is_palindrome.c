#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer n is a palindrome.
 * @n: the number n to check if it's a palindrome.
 * Return: 1 if n is a palindrome, otherwise 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long x = 0, num = n;

	x = n % 10;
	n /= 10;

	while (n != 0)
	{
		x *= 10;
		x += n % 10;
		n /= 10;
	}
	if (x == num)
		return (1);
	return (0);
}
