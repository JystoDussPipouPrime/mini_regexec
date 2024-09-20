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

typedef enum e_class
{
	c_null,
	c_az,
	c_AZ,
	c_aZ,
	c_09,
	c_az09,
	c_AZ09,
	c_aZ09
}	t_class;

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
			{
				return ((char *)big + i);
			}
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
	while (text[i])
	{
		if (!ischeck(text[i]) && !ischeck2(text[i]))
			return (false);
		i++;
	}
	return (true);
}

int	inside_bracket(const char *pattern, size_t *i)
{
	int	res;

	res = 0;
	(*i)++;
	while (pattern[*i])
	{
		if (pattern[*i] && pattern[*i + 1] && pattern[*i + 2])
		{
			if (pattern[*i] != '[' && pattern[*i + 1] != '[' && pattern[*i + 2] != '[')
			{
				if (pattern[*i] != ']' && pattern[*i + 1] != ']' && pattern[*i + 2] != ']')
				{
					if (ft_strnstr(pattern + *i, "a-z", 3))
						res += 1;
					else if (ft_strnstr(pattern + *i, "A-Z", 3))
						res += 2;
					else if (ft_strnstr(pattern + *i, "0-9", 3))
						res += 4;
					(*i) += 3;
				}
			}
		}
		if (pattern[*i] == ']' )
			return (res);
	}
	return (res);
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
	if (pattern[i] == '[')
		class = inside_bracket(pattern, &i);
	if (class == c_az)
		return (parse_text_one(text, islower));
	else if (class == c_AZ)
		return (parse_text_one(text, isupper));
	else if (class == c_aZ)
		return (parse_text_one(text, isalpha));
	else if (class == c_09)
		return (parse_text_one(text, isdigit));
	else if (class == c_az09)
		return (parse_text_two(text, isdigit, islower));
	else if (class == c_AZ09)
		return (parse_text_two(text, isdigit, isupper));
	else if (class == c_aZ09)
		return (parse_text_two(text, isdigit, isalpha));
	return (0);
}
