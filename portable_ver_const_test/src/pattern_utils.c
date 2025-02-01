/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:05:08 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:05:10 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"

int	pattern_read(const char *tt, const char *pp, size_t *t, size_t *p)
{
	if (pp[*p] == '[')
		if (inside_bracket(tt, pp, t, p))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	pattern_jump_step(const char *text, size_t *t, int (*is_check)(int))
{
	int	step;

	step = 0;
	while (is_check((text[*t])))
	{
		(*t)++;
		step++;
	}
	return (step);
}

void	pattern_jump_space(const char *text, size_t *t, size_t *p)
{
	while (is_space(text[*t]))
		(*t)++;
	(*p)++;
}
