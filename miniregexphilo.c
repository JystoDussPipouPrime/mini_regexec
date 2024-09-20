/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniregex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdpp <jdpp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 06:04:13 by jdpp              #+#    #+#             */
/*   Updated: 2024/08/26 07:15:08 by jdpp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

typedef enum e_class
{
	c_null,
	c_af,
	c_01,
	c_07,
	c_09,
	c_af09
}	t_class;

#define BASE_AF 1
#define BASE_BIN 2
#define BASE_DEC 4
#define BASE_OCT 8
#define BASE_HEX 5

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define CRESET "\e[0m"

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// 0 = noprefix 0b = 1 0 = 2 0x = 3
static int	find_prefix(char *str)
{
	if (!str)
		return (0);
	if (str[0] && str[1])
	{
		if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B'))
			return (1);
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
			return (3);
		if (str[0] == '0')
			return (2);
	}
	return (0);
}

static size_t	skip_prefix(char *str)
{
	if (!str)
		return (0);
	if (str[0] && str[1])
	{
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
			return (2);
		if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B'))
			return (2);
	}
	return (0);
}
int	ft_charbase_toint(char c, char *base)
{
	size_t i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base_positive(char *str, char *base)
{
	size_t		i;
	long long	result;
	size_t		base_len;
	result = 0;
	i = 0;

	i = skip_prefix(str);
	base_len = ft_strlen(base);
	if (!str || !base || base_len <= 0)
		return (-1);
	while (str[i])
	{
		if (result * base_len > INT_MAX || result < 0)
			return (-1);
		result *= base_len;
		if (ft_charbase_toint(str[i], base) == -1)
			return (-1);
		if (result + ft_charbase_toint(str[i], base) > INT_MAX || result < 0)
			return (-1);
		result += ft_charbase_toint(str[i], base);
		i++;
	}
	return (result);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

bool	parse_text_one(const char *text, int (*ischeck)(int))
{
	size_t	i;

	i = 0;
	if (text[i] == '\0')
		return (false);
	while (text[i])
	{
		if (!ischeck(text[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	parse_text_two(const char *text, int (*ischeck)(int), int (*ischeck2)(int))
{
	size_t	i;

	i = 0;
	if (text[i] == '\0')
		return (false);
	while (text[i])
	{
		if (!ischeck(text[i]) && !ischeck2(text[i]))
			return (false);
		i++;
	}
	return (true);
}

int	inside_bracket(const char *pattern)
{
	int	res;
	size_t	i;
	res = 0;

	i = 1;
	while (pattern[i])
	{
		if (pattern[i] && pattern[i + 1] && pattern[i + 2])
		{
			if (pattern[i] != '[' && pattern[i + 1] != '[' && pattern[i + 2] != '[')
			{
				if (pattern[i] != ']' && pattern[i + 1] != ']' && pattern[i + 2] != ']')
				{
					if (ft_strnstr(pattern + i, "a-f", 3))
						res += 1;
					else if (ft_strnstr(pattern + i, "0-1", 3))
						res += 2;
					else if (ft_strnstr(pattern + i, "0-9", 3))
						res += 4;
					else if (ft_strnstr(pattern + i, "0-7", 3))
						res += 8;
					i += 3;
				}
			}
		}
		if (pattern[i] == ']')
			return (res);
	}
	return (res);
}

int	isbase_binary(int c)
{
	return (c == '0' || c == '1');
}

int	isbase_hex(int c)
{
	return ((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9') );
}

int	isbase_oct(int c)
{
	return (c >= '0' && c <= '7');
}

int	isbase_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	mini_regexec(char *text, char *pattern)
{
	size_t	i;
	int		class;

	i = 0;
	class = 0;
	if (!text || !pattern)
		return (-1);
	while (*pattern != '[')
	{
		if (*pattern != *text)
			return (0);
		pattern++;
		text++;
	}
	if (*pattern == '[')
		class = inside_bracket(pattern);
	if (class == BASE_BIN)
		return (parse_text_one(text, isbase_binary));
	if (class == BASE_OCT)
		return (parse_text_one(text, isbase_oct));
	if (class == BASE_DEC)
		return (parse_text_one(text, isbase_digit));
	if (class == BASE_HEX)
		return (parse_text_one(text, isbase_hex));
	return (0);
}

static void	ft_strtolower(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}
int	main(int argc, char **argv)
{
	char	patterns1[4][100] = {"[0-9]", "0b[0-1]", "0[0-7]", "0x[a-f0-9]"};
	char	base[4][100] = {"0123456789", "01", "01234567", "0123456789abcdef"};
	int		prefix;

	if (argc != 2)
		return (0);
	prefix = find_prefix(argv[1]);
	ft_strtolower(argv[1]);
	printf("PAT:\t%s\n", patterns1[prefix]);
	if (mini_regexec(argv[1], patterns1[prefix]))
		printf(GRN"OK:\t%s\n"CRESET, argv[1]);
	else
		printf(RED"NOK:\t%s\n"CRESET, argv[1]);
	printf("DEC:\t%d\n", ft_atoi_base_positive(argv[1], base[prefix]));
	return (0);
}

//const char *patterns2 = "[a-zA-Z0-9]+[@][a-z0-9]";