#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_err(char *filename)
{
	char	*str;

	str = strerror(errno);
	ft_putstr("cat: ");
	ft_putstr(filename);
	ft_putstr(": ");
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

int	read_write(char *filename);

int	string_equals(char *a, char *b);

int	main(int argc, char *argv[])
{
	int		i;

	if (argc == 1)
	{
		read_write("-");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		read_write(argv[i]);
		i++;
	}
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

//If no file specified, fd is 0, so read from stdin
//1 means success
//0 means failed
int	read_write(char *filename)
{
	int		file;
	int		numbytes;
	char	c;

	file = 0;
	if (!string_equals(filename, "-"))
		file = open(filename, O_RDONLY);
	else
		printf("%s\n", "Equals to -");
	if (file == -1)
		return (ft_err(filename));
	while (1)
	{
		numbytes = read(file, &c, 1);
		if (numbytes == -1)
			return (ft_err(filename));
		if (numbytes == 0)
			break ;
		write(0, &c, 1);
	}
	if (file != 0 && close(file) != 0)
		return (ft_err(filename));
	return (1);
}
