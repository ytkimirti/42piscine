#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 != 0 && *s2 != 0 && n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
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
