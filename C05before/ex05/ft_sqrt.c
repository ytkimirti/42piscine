int	ft_sqrt(int nb)
{
	int	n;

	if (nb <= 0)
		return (0);
	n = 0;
	while (n * n != nb)
	{
		n++;
		if (n > 46340)
			return (0);
	}
	return (n);
}
