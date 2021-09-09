int	ft_is_prime(int nb)
{
	int	n;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	n = 2;
	while (nb % n != 0)
	{
		n++;
		if (n >= nb)
			return (1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}
