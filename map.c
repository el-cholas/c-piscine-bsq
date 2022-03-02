/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 01:20:57 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
map is the map without the first line

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

	map_short = create_short_copy(map_string, chars, m_x, m_y);
	printf("%s\n\n", map_string);
	//print_num_map(map_copy);
	//printf("%s", map_copy);
	//printf("%c\n", map[get_xy_coord(20, 10, map_width)]);
}

/*
m	= map but in short format and bi domensional array
m_s	= original map in short format
c	= list of chars, 0 = empty character, 1 = obstcial character
w	= map width
h	= map height
m[x][y] = -1 means that I will change the variable later
*/
short	**create_short_copy(char *m_s, char *c, int w, int h)
{
	short	**m;
	int		x;
	int		y;
	int		i;

	x = 0;
	m = (short **)malloc(sizeof(short) * w * h);
	i = 0;
	y = 0;
	while (m_s[i] != '0')
	{
		if (m_s[i] == '\n')
		{
			y++;
			x = 0;
		}
		else if (m_s[i] == c[1])
			m[x][y] = 0;
		else if (m_s[i] == c[0])
		{
			if (i <= w || m_s[i - 1] == '\n')
			{
				m[x][y] = 1;
			}
			else
			{
				m[x][y] = -1;
			}
		}
		i++;
		x++;
	}
	return (m);
}

//printf("current: %c a: %c b: %c c: %c\n",mc[i],  mc[i - 1],
//mc[i - mw],  mc[i - mw - 1]);
//mc[i] = get_min(mc[i - 1], mc[i - mw], mc[i - mw - 1]) + '0';

//Input "false" coords to return the char index of that position
// 0, 0 will return 0
int	get_xy_coord(int x_coord, int y_coord, int map_width)
{
	map_width++;
	return (map_width * y_coord + x_coord);
}

/*
mc = map_copy
mw = map_width + 1;
1 = 
0 = obstical
-1 = temp, it wil be changed later
-2 = new line, will be ignored
-10 = end of 'string'
*/

/*
void	change_chars(char *i_map, char empty, char obstical, int map_width)
{
	int	i;
	int	mw;

	i = 0;
	mw = map_width + 1;
	while (mc[i] != -10)
	{
		if (mc[i] == '\n')
			mc[i] = -2;
		if (mc[i] == obstical)
			mc[i] = 0;
		else if (mc[i] == empty)
		{
			if (i <= map_width || mc[i - 1] == -2)
				mc[i] = 1;
			else
				mc[i] = -1;
		}
		i++;
	}
}
*/
