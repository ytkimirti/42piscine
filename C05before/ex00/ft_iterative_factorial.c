int	ft_iterative_factorial(int nb)
{
	int	sum;

	if (nb == 0)
	{
		return (1);
	}
	sum = 1;
	while (nb > 0)
	{
		sum *= nb;
		nb--;
	}
	return (sum);
}
