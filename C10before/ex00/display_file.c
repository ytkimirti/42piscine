#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	put_err(char *str)
{
	ft_putstr(str);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		file;
	int		nbytes;
	char	c;

	if (argc <= 1)
		return (put_err("File name missing.\n"));
	if (argc > 2)
		return (put_err("Too many arguments.\n"));
	file = open(argv[1], O_RDONLY);
	if (file <= 0)
		return (put_err("Cannot read file.\n"));
	while (1)
	{
		nbytes = read(file, &c, sizeof(char));
		if (nbytes < 0)
			return (put_err("Cannot read file.\n"));
		else if (nbytes > 0)
			write(1, &c, sizeof(char));
		else
		{
			close(file);
			return (0);
		}
	}
}
