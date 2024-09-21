/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_positive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:03:30 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:03:34 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

static int	ft_charbase_toint(char c, char *base)
{
	size_t	i;

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
		if (result * base_len > 2147483647 || result < 0)
			return (-1);
		result *= base_len;
		if (ft_charbase_toint(str[i], base) == -1)
			return (-1);
		if (result + ft_charbase_toint(str[i], base) > 2147483647 || result < 0)
			return (-1);
		result += ft_charbase_toint(str[i], base);
		i++;
	}
	return (result);
}
