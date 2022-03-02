/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:21:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 20:04:58 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
0 = False
1 = True
prev_eol is Previous End Of Line, which is a position i n the file
lc is Line Count

For validate height, need to only count consecutive lines where the
Line length is not 0.
*/
int	is_map_valid(char *map)
{
	int	start;

	start = pos_char_in_array('\n', map) + 1;
	if (!are_chars_valid(map, start))
		return (0);
	else if (!is_width_valid(map, start))
		return (0);
	else if (!is_height_valid(map, start))
		return (0);
	return (1);
}

int	are_chars_valid(char *map, int start)
{
	int		counter;
	char	chars[3];

	chars[0] = get_empty_char(map);
	chars[1] = get_obstical_char(map);
	chars[2] = get_square_char(map);
	if (chars[0] == chars[1] || chars[0] == chars[2] || chars[1] == chars[2])
		return (0);
	else if (!is_printable(chars[0]))
		return (0);
	else if (!is_printable(chars[1]))
		return (0);
	else if (!is_printable(chars[2]))
		return (0);
	counter = start;
	while (map[counter] != 0)
	{
		if (!is_char_in_arr(map[counter], chars) && map[counter] != '\n')
			return (0);
		counter++;
	}
	return (1);
}

/* prev_eol = previous end of line */
int	is_width_valid(char *map, int start)
{
	int	i;
	int	prev_eol;
	int	map_width;

	map_width = get_width_of_map(map) + 1;
	i = start;
	prev_eol = 0;
	while (map[i] != 0)
	{
		if (map[i] == '\n')
		{
			if (i - prev_eol == map_width || prev_eol == 0)
				prev_eol = i;
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	is_height_valid(char *map, int start)
{
	int	counter;
	int	lc;

	lc = 0;
	counter = start;
	while (map[counter] != 0)
	{
		if (map[counter] == '\n' && map[counter + 1])
			lc++;
		counter++;
	}
	if (lc == string_to_int(map) - 1)
		return (1);
	else
		return (0);
}

/*
THIS IS 3 x FASTER BUT NORMINETTE IS A BOOT LICKER
int	is_map_valid_old(char *map)
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
	while (map[counter] != 0)
	{
		if (map[counter] == '\n')
		{
			if (counter - prev_eol == map_width + 1 || prev_eol == 0)
			{
				prev_eol = counter;
				lc++;
			}
			else
				return (2);
		}
		else if (!is_char_in_arr(map[counter], allowed_chars))
			return (3);
		counter++;
	}
	if (lc == string_to_int(map) || lc == string_to_int(map) - 1)
		return (1);
	else
		return (4);
}
*/