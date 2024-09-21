/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:04:35 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:04:37 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
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

void	ft_strtolower(char *str)
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

char	*ft_strnchr(const char *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (char)c && i < n)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
