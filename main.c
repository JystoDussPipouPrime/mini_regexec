/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdpp <jdpp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 06:04:13 by jdpp              #+#    #+#             */
/*   Updated: 2024/08/26 07:15:08 by jdpp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniregex.h"
#include <stdio.h>

int	main(void)
{
	size_t		t;
	size_t		p;
	const char	*pattern[] = {"[^][0-9]\0", "[0-9]\0", NULL};
	const char	*text[] = {"   1234\0", "1232222\0", NULL};

	p = 0;
	while (pattern[p])
	{
		t = 0;
		while (text[t])
		{
			if (mini_regex(text[t], pattern[p]))
				printf("\e[0;32mOK:\t%s\n\e[0m", text[t]);
			else
				printf("\e[0;31mNOK:\t%s\n\e[0m", text[t]);
			t++;
		}
		p++;
	}
	return (0);
}
