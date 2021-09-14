#include <stdio.h>
#include <stdlib.h>

_Bool	is_sep(char *c, char *charset)
{
	while (*charset != 0)
	{
		if (*charset == *c)
		{
			return (1);
		}
		charset++;
	}
	return (0);
}

int	split(char *str, char *charset, int w_c, char **arr)
{
	int		cs_i;
	int		w_i;
	int		b_i;
	_Bool	safemode;

	safemode = (w_c == -1);
	w_c = 0;
	cs_i = 0;
	while (str[cs_i] != 0)
	{
		while (is_sep(str + cs_i, charset) && str[cs_i] != 0)
			cs_i++;
		w_i = 0;
		while (str[cs_i + w_i] != 0 && !is_sep(str + cs_i + w_i, charset))
			w_c += (w_i++ == 0);
		b_i = 0;
		if (w_i != 0 && !safemode)
			arr[w_c - 1] = (char *)malloc(w_i + 1);
		if (safemode)
			cs_i = cs_i + w_i;
		else
			while (w_i != 0 && str[cs_i] != 0 && !is_sep(str + cs_i, charset))
				arr[w_c - 1][b_i++] = str[cs_i++];
	}
	return (w_c);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**arr;

	word_count = split(str, charset, -1, 0);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	arr[word_count] = 0;
	split(str, charset, 0, arr);
	return (arr);
}
