#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		*p;
	int		i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	p = (int *)malloc(sizeof(int) * (max - min));
	if (p == 0)
	{
		*range = 0;
		return (-1);
	}
	*range = p;
	i = 0;
	while (i < max - min)
	{
		p[i] = min + i;
		i++;
	}
	return (max - min);
}
