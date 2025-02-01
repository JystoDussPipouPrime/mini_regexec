/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:05:08 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:05:10 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

int	pattern_matchbase(const char *tt, const char *pp, size_t *t, size_t *p)
{
	size_t	step;

	step = 0;
	if (ft_strnstr(pp + *p, P_BIN, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, isbase_binary);
		(*p) += ft_patternlen(P_BIN);
	}
	else if (ft_strnstr(pp + *p, P_DEC, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, isbase_dec);
		(*p) += ft_patternlen(P_DEC);
	}
	else if (ft_strnstr(pp + *p, P_HEX, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, isbase_hex);
		(*p) += ft_patternlen(P_HEX);
	}
	else if (ft_strnstr(pp + *p, P_OCT, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, isbase_oct);
		(*p) += ft_patternlen(P_OCT);
	}
	return (step);
}

int	pattern_matchalp(const char *tt, const char *pp, size_t *t, size_t *p)
{
	size_t	step;

	step = 0;
	if (ft_strnstr(pp + *p, P_LOWER, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_lower);
		(*p) += ft_patternlen(P_LOWER);
	}
	else if (ft_strnstr(pp + *p, P_UPPER, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_upper);
		(*p) += ft_patternlen(P_UPPER);
	}
	else if (ft_strnstr(pp + *p, P_ALPHA, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_alpha);
		(*p) += ft_patternlen(P_ALPHA);
	}
	else if (ft_strnstr(pp + *p, P_ALPHA_DIGIT, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_alpha_digit);
		(*p) += ft_patternlen(P_ALPHA_DIGIT);
	}
	return (step);
}

int	pattern_matchcub(const char *tt, const char *pp, size_t *t, size_t *p)
{
	size_t	step;

	step = 0;
	if (ft_strnstr(pp + *p, P_FILENAME, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_filename);
		(*p) += ft_patternlen(P_FILENAME);
	}
	if (ft_strnstr(pp + *p, P_MAP_BORDER, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_map_border);
		(*p) += ft_patternlen(P_MAP_BORDER);
	}
	if (ft_strnstr(pp + *p, P_MAP_INSIDE, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_map_inside);
		(*p) += ft_patternlen(P_MAP_INSIDE);
	}
	else if (ft_strnstr(pp + *p, P_SPACE, 5) != NULL)
	{
		step = pattern_jump_step(tt, t, is_space);
		(*p) += ft_patternlen(P_SPACE);
	}
	return (step);
}
