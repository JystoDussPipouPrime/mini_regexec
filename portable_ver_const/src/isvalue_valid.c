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

int	is_map_border(int c)
{
	return ((c >= 9 && c <= 13) || c == 32 || c == 49);
}

int	is_map_inside(int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (is_map_border(c) || c == 48);
}

int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_filename(int c)
{
	return ((c >= 97 && c <= 122) || c == '.' || c == '/');
}

int	is_base_bin_coordinate(int c)
{
	return (c == 48 || c == 49 || c == 'N' || c == 'S' || c == 'W' || c == 'E');
}
