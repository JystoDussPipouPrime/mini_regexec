/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:04:13 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:04:16 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

//	char	base[4][100] = {"0123456789", "01", "01234567", "0123456789abcdef"};

char	*find_base(char *str)
{
	if (!str)
		return (NULL);
	if (str[0] && str[1])
	{
		if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B'))
			return ("01");
		if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
			return ("0123456789abcdef");
		if (str[0] == '0')
			return ("01234567");
	}
	return ("0123456789");
}

size_t	skip_prefix(char *str)
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
