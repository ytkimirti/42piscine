unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	len_d;
	int	len_s;

	len_d = 0;
	len_s = 0;
	while (dest[len_d] != 0)
		len_d++;
	while (src[len_s] != 0)
		len_s++;
	if (size < len_d)
		return (len_s + size);
	while (size - len_d - 1 > 0 && *src != 0)
	{
		dest[len_d] = *src;
		src++;
		len_d++;
	}
	dest[len_d] = 0;
	return (len_s);
}
