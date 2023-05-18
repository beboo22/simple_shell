#include "shell.h"
/**
 * _atoi - convert a string into an integer
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int i, counter, num;

	i = 0;
	counter = 0;

	while (!(s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
	{
		if (s[i] == '-')
			counter++;

		i++;
	}
	num = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (s[i] - '0') + (num * 10);
		i++;
	}
	if (counter % 2 != 0)
		num = -num;

	return (num);
}

/**
 * printnum - print num
 * @n: num
 */
void printnum(int n)
{
	int digit, sum, last;
	int div = 1000000000;
	unsigned int num;

	num = n;
	sum = 0;

	while (div > 1)
	{
		digit = (num / div) % 10;
		sum += digit;
		if (sum != 0)
			_putchar(digit + '0');
		div = div / 10;
	}
	last = num % 10;
	_putchar(last + '0');
}
