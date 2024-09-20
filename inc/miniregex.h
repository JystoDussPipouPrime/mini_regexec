/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniregex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdpp <jdpp@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 06:04:13 by jdpp              #+#    #+#             */
/*   Updated: 2024/08/26 07:15:08 by jdpp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIREGEX_H
# define MINIREGEX_H

# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

# define BASE_AF 1
# define BASE_BIN 2
# define BASE_DEC 4
# define BASE_OCT 8
# define BASE_HEX 5

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define CRESET "\e[0m"


int		isbase_binary(int c);
int		isbase_hex(int c);
int		isbase_oct(int c);
int		isbase_digit(int c);
int		find_prefix(char *str);
void	ft_strtolower(char *str);
int		mini_regexec(char *text, char *pattern);
int		ft_atoi_base_positive(char *str, char *base);

#endif
