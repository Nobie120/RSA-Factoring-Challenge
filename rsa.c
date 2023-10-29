#include <stdio.h>
#include <stdlib.h>

/**
 * main - factorize numbers into two prime factors
 * @argc:arguement count
 * @argv:arguement vector
 *
 * Rerurn: 0 on success
 */

int is_prime(int num);

int main(int argc, char *argv[])
{
	long long int number, div;
	FILE *fd;
	ssize_t bytes_read, len = 0;
	int flag;
	char *line = NULL;

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (-1);
	while (bytes_read = getline(&line, &len, fd) != -1)
	{
		number = atoll(line);
		div = 2;
	
		flag = 0;
		while (flag == 0)
		{
			if (number % div == 0 && (is_prime(div) && is_prime(number / div)))
			{
				printf("%lld=%lld*%lld\n", number, number / div, div);
				flag = 1;
			}
			else
				div++;
		}
	}
	fclose(fd);
	if (line)
		free(line);

	return (0);
}

/**
 * is_prime - checks to see if a number is prime
 * @num:the number to be checked
 *
 * Return: 0 if not prime otherwise 1
 */

int is_prime(int num)
{
	int i;

	if (num <= 1 || num % 2 == 0)
		return (0);
	if (num == 2)
		return (1);
	for (i = 3; i * i <= num; i += 2)
	{
		if (num % i == 0)
			return (0);
	}
	return (1);
}
