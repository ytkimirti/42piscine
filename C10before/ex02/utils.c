#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_err(char *filename)
{
	char	*str;

	str = strerror(errno);
	ft_putstr("tail: ");
	ft_putstr(filename);
	ft_putstr(": ");
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (0);
}

int	string_equals(char *a, char *b)
{
	while (*a != 0 && *b != 0)
		if (*(a++) != *(b++))
			return (0);
	if (*a == 0 && *b != 0)
		return (0);
	if (*a != 0 && *b == 0)
		return (0);
	return (1);
}
