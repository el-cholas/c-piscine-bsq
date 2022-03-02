/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/03 00:21:13 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
map_body is the map without the 'header'

chars
0 = empty character
1 = obstcial character
2 = square character
*/
void	start_map(char *map_file_name)
{
	char	*map;
	char	*map_body;
	char	chars[3];
	int		height;

	map = read_file(map_file_name);
	map_body = ft_strstr(map, "\n") + 1;
	chars[0] = get_empty_char(map);
	chars[1] = get_obstical_char(map);
	chars[2] = get_square_char(map);
	height = string_to_int(map) - 1;
	if (is_map_valid(map))
		main_map(map_body, chars, get_width_of_map(map), height);
	else
		print_string("map error\n");
}

/*
m_x			= map width
m_y			= map height
map_short	= copy of map but in short format and as a bi-dimensional array
*/
void	main_map(char *map_string, char *chars, int m_x, int m_y)
{	
	short	**map_short;
	int		*square;

	map_short = create_short_copy(map_string, chars, m_x, m_y);
	calculate_squares(map_short, m_x, m_y);
	square = find_square(map_short, m_x, m_y);
	fill_square(map_string, chars[2], square, m_x);
	print_string(map_string);
}

/*
EXPECTS VALIDATED MAP, copies map as string to 2D array of shorts
m	= map but in short format and bi domensional array
m_s	= original map in short format
c	= list of chars, 0 = empty character, 1 = obstcial character
w	= map width
h	= map height
*/
short	**create_short_copy(char *m_s, char *c, int w, int h)
{
	short	**m;
	int		x;
	int		y;
	int		i;

	y = 0;
	m = create_2d(w, h);
	i = 0;
	while (y <= h)
	{
		x = 0;
		while (x < w)
		{
			if (m_s[i] == c[1])
				m[y][x] = 0;
			else if (i < w || m_s[i - 1] == '\n')
				m[y][x] = 1;
			x++;
			i++;
		}
		i++;
		y++;
	}
	return (m);
}

/* This is the actual algorithm */
void	calculate_squares(short **m, int w, int h)
{
	int	x;
	int	y;

	y = 0;
	while (y <= h)
	{
		x = 0;
		while (x < w)
		{
			if (m[y][x] == -1)
			{
				m[y][x] = min(m[y][x - 1], m[y - 1][x], m[y - 1][x - 1]) + 1;
			}
			x++;
		}
		y++;
	}
}
