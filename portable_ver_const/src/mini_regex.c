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

int	inside_bracket(const char *tt, const char *pp, size_t *t, size_t *p)
{
	bool	is_found;

	is_found = 0;
	while (pp[*p] == '[')
	{
		if (pattern_matchbase(tt, pp, t, p)
			|| pattern_matchalp(tt, pp, t, p)
			|| pattern_matchcub(tt, pp, t, p))
			is_found = 1;
		if (!is_found)
			return (EXIT_FAILURE);
		(*p) += 5;
	}
	return (EXIT_SUCCESS);
}

int	mini_regex(const char *text, const char *pattern)
{
	size_t	t;
	size_t	p;

	t = 0;
	p = 0;
	while (pattern[p] != '\0' && text[t] != '\0')
	{
		if (pattern_read(text, pattern, &t, &p))
			return (0);
		else if (pattern[p] == '^')
			pattern_jump_space(text, &t, &p);
		else
		{
			if (pattern[p] == text[t])
			{
				p++;
				t++;
			}
			else
				return (0);
		}
	}
	if ((pattern[p] == '\0' && text[t] == '\0'))
		return (1);
	return (0);
}
