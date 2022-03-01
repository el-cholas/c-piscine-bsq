/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/01 23:33:22 by xcarroll         ###   ########.fr       */
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
	char	*map_copy;
	char	chars[3];
	int		*int_map;

	map = read_file(map_file_name);
	map_copy = read_file(map_file_name);
	map_body = ft_strstr(map_copy, "\n") + 1;
	map_copy = ft_strstr(map_copy, "\n") + 1;
	int_map = (int *)map_copy;
	int_map[get_string_size(map_copy) + 1] = -10;
	chars[0] = get_empty_char(map);
	chars[1] = get_obstical_char(map);
	chars[2] = get_square_char(map);
	if (is_map_valid(map))
		main_map(map, int_map, chars, get_width_of_map(map));
	else
		print_string("map error\n");
}

/*
square_coords holds (posx, posy, size)
where posx and posy are top left
*/
void	main_map(char *map, int *map_copy, char *chars, int map_width)
{
	int		square_coords[3];

	change_chars(map_copy, chars[0], chars[1], map_width);
	printf("%s\n\n", map);
	//printf("%s", map_copy);
	square_coords[0] = 1;
	square_coords[1] = 1;
	square_coords[2] = 1;
	//printf("%c\n", map[get_xy_coord(20, 10, map_width)]);
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
void	change_chars(int *mc, char empty, char obstical, int map_width)
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

//printf("current: %c a: %c b: %c c: %c\n",mc[i],  mc[i - 1], mc[i - mw],  mc[i - mw - 1]);
//mc[i] = get_min(mc[i - 1], mc[i - mw], mc[i - mw - 1]) + '0';

//Input "false" coords to return the char index of that position
// 1, 1 will return 0
int	get_xy_coord(int x_coord, int y_coord, int map_width)
{
	map_width++;
	y_coord--;
	x_coord--;
	return (map_width * y_coord + x_coord);
}
