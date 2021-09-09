#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 && *s2 != 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == 0 && *s2 != 0)
	{
		return (-1);
	}
	else if (*s1 != 0 && *s2 == 0)
	{
		return (1);
	}
	return (0);
}

void	ft_sort_str(char **tab, int size)
{
	int		i;
	int		j;
	char	*current;

	i = 1;
	while (i < size)
	{
		current = tab[i];
		j = i - 1;
		while (j >= 0 && ft_strcmp(tab[j], current) > 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = current;
		i++;
	}
}

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
	int	i;

	ft_sort_str(&argv[1], argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
