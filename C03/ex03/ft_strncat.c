char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0 && nb > 0)
	{
		*dest = *src;
		src ++;
		dest++;
		nb--;
	}
	*dest = 0;
	return (dest);
}
