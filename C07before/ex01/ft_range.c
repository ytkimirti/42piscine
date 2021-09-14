#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*p;
	int		i;

	if (min >= max)
		return (0);
	p = (int *)malloc(sizeof(int) * (max - min));
	if (p == 0)
		return (0);
	i = 0;
	while (min < max)
	{
		p[i] = min;
		min++;
		i++;
	}
	return (p);
}
