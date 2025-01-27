#include "miniregex.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	size_t		t;
	size_t		p;
	const char	*pattern[] = {"[^^^][0-9]\0", "[0-9]\0", NULL};
	const char	*text[] = {"   1234\0", "1232222\0", NULL};

	p = 0;
	while (pattern[p])
	{
		t = 0;
		while (text[t])
		{
			if (mini_regex(text[t], pattern[p]))
				printf("\e[0;32mOK:\t%s\n\e[0m", text[t]);
			else
				printf("\e[0;31mNOK:\t%s\n\e[0m", text[t]);
			t++;
		}
		p++;
	}
	return (0);
}