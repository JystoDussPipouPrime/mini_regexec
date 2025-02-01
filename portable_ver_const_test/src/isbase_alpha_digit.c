/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbase_alpha_digit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:02:51 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:02:56 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

int	is_lower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_upper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_alpha(int c)
{
	return (is_lower(c) || is_upper(c));
}

int	is_alpha_digit(int c)
{
	return (is_lower(c) || is_upper(c) || isbase_dec(c));
}
