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

#ifndef INTERNAL_H
# define INTERNAL_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h> //////////////////////////////

# define P_BIN                  "[0-1]"
# define P_DEC                  "[0-9]"
# define P_HEX                  "[0-f]"
# define P_OCT                  "[0-7]"
# define P_LOWER                "[a-z]"
# define P_UPPER                "[A-Z]"
# define P_ALPHA                "[a-Z]"
# define P_ALPHA_DIGIT          "[a0Z]"
# define P_FILENAME             "[./t]"
# define P_MAP_BORDER           "[^1^]"
# define P_MAP_INSIDE           "[0N1]"
# define P_SPACE                "[^^^]"
# define P_UNIT_INTERVAL        "[0.X]"

#ifdef __cplusplus
extern "C" {
#endif

int     isbase_binary(int c);
int     isbase_hex(int c);
int     isbase_oct(int c);
int     isbase_dec(int c);
int     is_map_border(int c);
int     is_map_inside(int c);
int     is_minus(int c);
int     is_space(int c);
int     is_filename(int c);
int     is_lower(int c);
int     is_upper(int c);
int     is_alpha(int c);
int     is_alpha_digit(int c);
int     is_zero(int c);
int     is_dot(int c);

int     ft_atoi_base_positive(char *str, char *base);
char    *find_base(char *str);
size_t  skip_prefix(char *str);

size_t  ft_baselen(const char *str);
size_t  ft_patternlen(const char *str);
char    *ft_strnstr(const char *big, const char *little, size_t len);
char    *ft_strnchr(const char *s, int c, size_t n);

int     pattern_read(const char *tt, const char *pp, size_t *t, size_t *p);
// void    pattern_jump(const char *text, size_t *t, int (*is_check)(int));
int     pattern_jump_step(const char *text, size_t *t, int (*is_check)(int));
// void    pattern_jump_space(const char *text, size_t *t, size_t *p);
int     pattern_matchbase(const char *tt, const char *pp, size_t *t, size_t *p);
int     pattern_matchalp(const char *tt, const char *pp, size_t *t, size_t *p);
int     pattern_matchcub(const char *tt, const char *pp, size_t *t, size_t *p);
int     pattern_matchscop(const char *tt, const char *pp, size_t *t, size_t *p);

int     inside_bracket(const char *tt, const char *pp, size_t *t, size_t *p);

#ifdef __cplusplus
}
#endif

#endif
