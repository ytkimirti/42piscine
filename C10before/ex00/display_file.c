#include <stdio.h>
#include <unistd.h>

#include <fcntl.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>


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

// Deneme comment2
int	main(int argc, char *argv[])
{


	/*if (argc <= 1)*/
		/*return (put_err("File name missing.\n"));*/
	/*if (argc > 2)*/
		/*return (put_err("Too many arguments.\n"));*/
	/*if (fptr == 0)*/
		/*return (put_err("Cannot read file.\n"));*/

}
