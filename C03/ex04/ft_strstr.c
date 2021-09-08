char	*ft_strstr(char *str, char *to_find)
{
	char	*base;
	char	*needle;
	char	*stack;

	if (*str == 0)
		return (str);
	base = str;
	while (*base != 0)
	{
		needle = to_find;
		stack = base;
		while (1)
		{
			if (*needle == 0)
				return (base);
			else if (*stack != *needle || *stack == 0)
				break ;
			needle++;
			stack++;
		}
		base++;
	}
	return (0);
}
