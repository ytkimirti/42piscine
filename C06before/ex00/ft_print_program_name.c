#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	argc = 0;
	ft_putstr(argv[0]);
}
