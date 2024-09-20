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

#include "miniregex.h"

int	main(int argc, char **argv)
{
	char	patterns1[4][100] = {"[0-9]", "0b[0-1]", "0[0-7]", "0x[a-f0-9]"};
	// char	base[4][100] = {"0123456789", "01", "01234567", "0123456789abcdef"};
	int		prefix;

	if (argc != 2)
		return (printf(RED"./mini_regex <num>\n"CRESET), 0);
	prefix = find_prefix(argv[1]);
	ft_strtolower(argv[1]);
	printf("PAT:\t%s\n", patterns1[prefix]);
	if (mini_regexec(argv[1], patterns1[prefix]))
		printf(GRN"OK:\t%s\n"CRESET, argv[1]);
	else
		printf(RED"NOK:\t%s\n"CRESET, argv[1]);
	// printf("DEC:\t%d\n", ft_atoi_base_positive(argv[1], base[prefix]));
	return (0);
}
