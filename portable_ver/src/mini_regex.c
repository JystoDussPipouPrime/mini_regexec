/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_regex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:05:08 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:05:10 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

static int	parse_text_one(const char *text, int (*ischeck)(int))
{
	size_t	i;

	i = 0;
	if (text[i] == '\0')
		return (0);
	while (text[i])
	{
		if (!ischeck(text[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	find_pattern(const char *str, int *res)
{
	if (ft_strnstr(str, "a-f", 3))
		*res += 1;
	else if (ft_strnstr(str, "0-1", 3))
		*res += 2;
	else if (ft_strnstr(str, "0-9", 3))
		*res += 4;
	else if (ft_strnstr(str, "0-7", 3))
		*res += 8;
}

int	inside_bracket(const char *pattern)
{
	int		res;
	size_t	i;

	res = 0;
	i = 1;
	while (pattern[i])
	{
		if (pattern[i] && pattern[i + 1] && pattern[i + 2])
		{
			if (!ft_strnchr(pattern + i, '[', 3))
				if (!ft_strnchr(pattern + i, ']', 2))
					find_pattern(pattern + i, &res);
			i += 3;
		}
		if (pattern[i] == ']')
			return (res);
	}
	return (res);
}

int	mini_regex(char *text, char *pattern)
{
	int		class;

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
