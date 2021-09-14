int	find_num(char str, char *base)
{
	int	i;

	i = 0;
	while (str != base[i])
	{
		if (base[i] == 0)
			return (-1);
		i++;
	}
	return (i);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*find_flag(char *str, int *flag)
{
	*flag = 0;
	while (1)
	{
		if (*str == '\t' || *str == '\n')
			str++;
		else if (*str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		else
			break ;
	}
	while (1)
	{
		if (*str == '-')
			*flag += 1;
		else if (*str != '+')
			break ;
		str++;
	}
	*flag = ((*flag + 1) % 2) * 2 - 1;
	return (str);
}

_Bool	is_valid(char *charset, int len)
{
	int	stat;
	int	i;

	stat = 0;
	if (charset[0] == 0 || charset[1] == 0)
		return (0);
	while (stat < len)
	{
		if (charset[stat] == '+' || charset[stat] == '-')
			return (0);
		i = 0;
		while (i < len)
		{
			if (i != stat && charset[i] == charset[stat])
				return (0);
			i++;
		}
		stat++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *charset)
{
	int	base;
	int	len_c;
	int	i;
	int	sum;
	int	f;

	len_c = len(charset);
	if (!is_valid(charset, len_c))
		return (0);
	str = find_flag(str, &f);
	i = len(str) - 1;
	base = 1;
	sum = 0;
	while (i >= 0)
	{
		if (find_num(str[i], charset) == -1)
			return (0);
		sum += base * find_num(str[i], charset) * f;
		i--;
		base *= len_c;
	}
	return (sum);
}
