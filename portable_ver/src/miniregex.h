/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniregex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:03:39 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 08:03:42 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIREGEX_H
# define MINIREGEX_H

# include <stdio.h> //
# include <stdlib.h>

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

int		ft_atoi_base_positive(char *str, char *base);
char	*find_base(char *str);
size_t	skip_prefix(char *str);

size_t	ft_strlen(const char *str);
void	ft_strtolower(char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strnchr(const char *s, int c, size_t n);

int		mini_regex(char *text, char *pattern);

#endif
