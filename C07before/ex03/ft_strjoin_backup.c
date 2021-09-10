#include <stdlib.h>
#include <stdio.h>

int	len(char *str)
{
	int	l;
	
	l = 0;
	while (str[l] != 0)
		l++;
	return (l);
}

char *allocate_mem(int size, char **strs, char *sep)
{

}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		big_i;
	int		len_sum;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	big_i = 0;
	len_sum = 0;
	while (big_i < size)
	{
		len_sum += len(strs[big_i]);
		big_i++;
	}
	len_sum += len(sep) * (size - 1) + 1;
	joined = (char *)malloc(sizeof(char) * len_sum);
	big_i = 0;
	int	local_i; // Local index for small strings
	int	global_i; // Global index for *joined;
	global_i = 0;
	while (big_i < size)
	{
		local_i = 0;
		while (strs[big_i][local_i] != 0)
		{
			joined[global_i] = strs[big_i][local_i];
			local_i++;
			global_i++;
		}
		local_i = 0;
		while (sep[local_i] != 0 && big_i != size - 1)
		{
			joined[global_i] = sep[local_i];
			local_i++;
			global_i++;
		}
		big_i++;
	}
	joined[global_i] = 0;
	return (joined);
}

#include <unistd.h>

int	main(void)
{
	printf("%d", len("Hello"));
	printf("%s","\n");
	char *strs[] = {"as", "df", "xd"};

	char *joined;

	joined = ft_strjoin(3, strs, "");

	free(joined);

	for (int i = 0; i < len(joined)+1; i++)
	{
		if (joined[i] == 0)
			write(1, "0", 1);
		else
			write(1, &joined[i], 1);
	}
}
