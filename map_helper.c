/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:14:29 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 20:25:50 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* Expects map with header */
char	get_empty_char(char *map)
{
	int	first_line_len;

	first_line_len = pos_char_in_array('\n', map) + 1;
	return (map[first_line_len - 4]);
}

/* Expects map with header */
char	get_obstical_char(char *map)
{
	int	first_line_len;

	first_line_len = pos_char_in_array('\n', map) + 1;
	return (map[first_line_len - 3]);
}

/* Expects map with header */
char	get_square_char(char *map)
{
	int	first_line_len;

	first_line_len = pos_char_in_array('\n', map) + 1;
	return (map[first_line_len - 2]);
}

/*
Returns width not including new line char
Map has to get width from map with header
*/
int	get_width_of_map(char *map)
{
	int	counter;
	int	offset;

	offset = pos_char_in_array('\n', map) + 1;
	counter = offset;
	while (map[counter] != '0')
	{
		if (map[counter] == '\n')
			return (counter - offset);
		counter++;
	}
	return (0);
}
