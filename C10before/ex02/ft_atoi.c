_Bool	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

_Bool	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	find_num(char *p, int curr)
{
	if (is_num(*p))
		return (find_num(p + 1, curr * 10 + (*p - '0')));
	return (curr);
}

int	ft_atoi(char *str)
{
	char	*mem;
	int		negcount;

	negcount = 0;
	mem = str;
	while (ft_isspace(*str))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negcount++;
		str++;
	}
	return (find_num(str, 0) * ((((negcount + 1) % 2) * 2) - 1));
}
