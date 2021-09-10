#include <stdlib.h>

int	len(char *str)
{
	int	l;

	l = 0;
	while (str[l] != 0)
		l++;
	return (l);
}

char	*allocate_mem(int size, char **strs, char *sep)
{
	int		big_i;
	int		len_sum;

	big_i = 0;
	len_sum = 0;
	while (big_i < size)
	{
		len_sum += len(strs[big_i]);
		big_i++;
	}
	len_sum += len(sep) * (size - 1) + 1;
	return ((char *)malloc(sizeof(char) * len_sum));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		big_i;
	int		local_i;
	int		global_i;

	if (size <= 0)
		return ((char *)malloc(sizeof(char)));
	joined = allocate_mem(size, strs, sep);
	big_i = 0;
	global_i = 0;
	while (big_i < size)
	{
		local_i = 0;
		while (strs[big_i][local_i] != 0)
			joined[global_i++] = strs[big_i][local_i++];
		local_i = 0;
		while (sep[local_i] != 0 && big_i != size - 1)
			joined[global_i++] = sep[local_i++];
		big_i++;
	}
	joined[global_i] = 0;
	return (joined);
}
