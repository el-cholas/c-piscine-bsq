/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/01 19:31:31 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* map is the map without the first line */
void	start_map(char *map_file_name)
{
	char	*map_contents;
	char	*map;

	map_contents = read_file(map_file_name);
	map = ft_strstr(map_contents, "\n") + 1;
	if (is_map_valid(map_contents))
		main_map(map);
	else
		print_string("map error\n");
}

/*
square_coords holds (posx, posy, size)
where posx and posy are top left

chars
0 = empty character
1 = obstcial character
2 = square character
*/
void	main_map(char *map)
{
	char	chars[3];
	int		square_coords[3];
	int		map_width;

	chars[0] = get_empty_char(map);
	chars[1] = get_obstical_char(map);
	chars[2] = get_square_char(map);
	square_coords[0] = 0;
	square_coords[1] = 0;
	square_coords[2] = 1;
	map_width = get_width_of_map(map);
	printf("%c\n", map[get_xy_coord(20, 10, map_width)]);
}

/*
int	find_square(int size, char *map, int map_width)
{
	
}
*/

//Input "false" coords to return the char index of that position
// 1, 1 will return 0
int	get_xy_coord(int x_coord, int y_coord, int map_width)
{
	map_width++;
	y_coord--;
	x_coord--;
	return (map_width * y_coord + x_coord);
}
