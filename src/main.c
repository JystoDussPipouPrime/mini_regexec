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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf(RED"./mini_regex <num>\n"CRESET), 0);
	ft_strtolower(argv[1]);
	if (mini_regexec(argv[1], "[0-9]"))
		printf(GRN"OK:\t%s\n"CRESET, argv[1]);
	else if (mini_regexec(argv[1], "0b[0-1]"))
		printf(GRN"OK:\t%s\n"CRESET, argv[1]);
	else if (mini_regexec(argv[1], "0[0-7]"))
		printf(GRN"OK:\t%s\n"CRESET, argv[1]);
	else if (mini_regexec(argv[1], "0x[a-f0-9]"))
		printf(GRN"OK:\t%s\n"CRESET, argv[1]);
	else
	{
		printf(RED"NOK:\t%s\n"CRESET, argv[1]);
		return (0);
	}
	printf("DEC:\t%d\n", ft_atoi_base_positive(argv[1], find_base(argv[1])));
	return (0);
}
