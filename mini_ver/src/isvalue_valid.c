/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalue_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcurto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:02:51 by mcurto            #+#    #+#             */
/*   Updated: 2024/09/21 07:02:56 by mcurto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isbase_binary(int c)            { return (c == '0' || c == '1'); }
int	isbase_hex(int c)               { return ((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9')); }
int	isbase_oct(int c)               { return (c >= '0' && c <= '7'); }
int	isbase_dec(int c)               { return (c >= '0' && c <= '9'); }

int	is_lower(int c)                 { return (c >= 'a' && c <= 'z'); }
int	is_upper(int c)                 { return (c >= 'A' && c <= 'Z'); }
int	is_alpha(int c)                 { return (is_lower(c) || is_upper(c)); }
int	is_alpha_digit(int c)           { return (is_lower(c) || is_upper(c) || isbase_dec(c)); }

int	is_filename(int c)              { return ((c >= 97 && c <= 122) || c == '.' || c == '/'); }
int	is_map_border(int c)            { return ((c >= 9 && c <= 13) || c == 32 || c == 49); }
int	is_space(int c)                 { return ((c >= 9 && c <= 13) || c == 32); }
int	is_minus(int c)                 { return (c == 45); }
int	is_zero(int c)                 	{ return (c == 48); }
int	is_dot(int c)                 	{ return (c == 46); }

int	is_map_inside(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (is_map_border(c) || c == 48);
}

