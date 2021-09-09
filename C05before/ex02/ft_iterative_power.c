int	ft_iterative_power(int nb, int power)
{
	int	sum;

	if (power < 0 || (power != 0 && nb == 0))
		return (0);
	else if (power == 0 && nb == 0)
		return (1);
	sum = 1;
	while (power > 0)
	{
		sum *= nb;
		power--;
	}
	return (sum);
}
