/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/02/28 21:11:39 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	start_map(char *map_file_name)
{
	char	*map_contents;

	map_contents = read_file(map_file_name);
	if (map_contents == 0)
		print_string("map error");
	else
		main_map(map_contents);
}

void	main_map(char *map)
{
	char	empty_char;
	char	obstical_char;
	char	square_char;

	empty_char = get_empty_char(map);
	obstical_char = get_obstical_char(map);
	square_char = get_square_char(map);
	if (is_map_valid(map) == 1)
		print_string("Map is valid\n");
	else
		print_string("Map is not valid\n");
}
