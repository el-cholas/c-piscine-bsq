/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:14:29 by xcarroll          #+#    #+#             */
/*   Updated: 2022/02/28 20:18:23 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
0 = False
1 = True
prev_eol is Previous End Of Line, which is a position i n the file
lc is Line Count
*/
int	is_map_valid(char *map)
{
	int		counter;
	char	allowed_chars[3];
	int		prev_eol;
	int		map_width;
	int		lc;

	counter = pos_char_in_array('\n', map) + 1;
	map_width = get_width_of_map(map);
	prev_eol = 0;
	allowed_chars[0] = get_empty_char(map);
	allowed_chars[1] = get_obstical_char(map);
	lc = 0;
	while (map[counter] != 0 && counter < 10000)
	{
		if (map[counter] == '\n')
		{
			if (counter - prev_eol == map_width + 1 || prev_eol == 0)
			{
				prev_eol = counter;
				lc++;
			}
			else
				return (0);
		}
		else if (!is_char_in_arr(map[counter], allowed_chars))
			return (0);
		counter++;
	}
	if (lc == string_to_int(map) || lc == string_to_int(map) - 1)
		return (1);
	else
		return (0);
}


char	get_empty_char(char *map)
{
	int	first_line_len;

	first_line_len = pos_char_in_array('\n', map) + 1;
	return (map[first_line_len - 4]);
}

char	get_obstical_char(char *map)
{
	int	first_line_len;

	first_line_len = pos_char_in_array('\n', map) + 1;
	return (map[first_line_len - 3]);
}

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
	return (-1);
}
