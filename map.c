/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:05 by xcarroll          #+#    #+#             */
/*   Updated: 2022/02/28 19:14:43 by xcarroll         ###   ########.fr       */
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
	if (is_map_valid(map))
		printf("Map is valid\n");
	else
		printf("Map is not valid\n");
}
