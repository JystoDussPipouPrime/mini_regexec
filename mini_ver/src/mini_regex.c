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

#include "internal.h"

int	inside_bracket(const char *tt, const char *pp, size_t *t, size_t *p)
{
	bool	is_found;

	is_found = 0;
	while (pp[*p] == '[')
	{
		if (pattern_matchbase(tt, pp, t, p)
			|| pattern_matchalp(tt, pp, t, p)
			|| pattern_matchcub(tt, pp, t, p)
			|| pattern_matchscop(tt, pp, t, p))
			is_found = 1;
		if (!is_found)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	mini_regex(const char *text, const char *pattern)
{
	size_t	t;
	size_t	p;

	t = 0;
	p = 0;
	while (text && pattern && pattern[p] != '\0' && text[t] != '\0')
	{
		// printf("BEF P[%ld] = |%c| T[%ld] = |%d|\n",p,pattern[p],t,text[t]);
		if (pattern_read(text, pattern, &t, &p))
			{ /*printf("FAIL: pattern");*/ return (0); }
		else if (pattern[p] == '^')
			p += pattern_jump_step(text, &t, is_space);
		else
		{
			if (pattern[p] == text[t])
			{
				p++;
				t++;
			}
			else {
				// printf("FAIL: p=t");
				return (0);
			}
		}
		// printf("AFT P[%ld] = |%d| T[%ld] = |%d|\n",p,pattern[p],t,text[t]);

	}

	if (text && pattern && (pattern[p] == '\0' && text[t] == '\0'))
		return (1);
	return (0);
}
