#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * factors - factorizes a number
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	long long int div, number;
	FILE *fd;
	int flag;
	ssize_t bytes_read, len = 0;

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (-1);
	while (bytes_read = getline(&line, &len, fd) != -1)
	{
		div = 2;
		number = atoll(line);
	
		flag = 0;
		while (flag == 0)
		{
			if (number % div == 0)
			{
				printf("%lld=%lld*%lld\n", number, div, number / div);
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