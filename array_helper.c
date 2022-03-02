/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:27:45 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 20:29:21 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	**create_2d(int width, int height)
{
	short	**arr;
	int		x;
	int		y;

	y = 0;
	arr = (short **)malloc(sizeof(short *) * height + 1);
	while (y <= height)
	{
		arr[y] = (short *)malloc(sizeof(short ) * width);
		x = 0;
		while (x < width)
			arr[y][x++] = -1;
		y++;
	}
	return (arr);
}

/*
takes input of pre-processed array with algorithm implimented
square is [posX, posY, height]
where pos x and y are bottom right corner

function goes throgh array backwards to always find top left
*/
int	*find_square(short **m, int w, int h)
{
	int	*square;
	int	x;
	int	y;

	square = (int *)malloc(sizeof(int) * 3);
	square[0] = 0;
	square[1] = 0;
	square[2] = 0;
	y = h;
	while (y >= 0)
	{
		x = w - 1;
		while (x >= 0)
		{
			if (m[y][x] >= square[2])
			{
				square[0] = x;
				square[1] = y;
				square[2] = m[y][x];
			}
			x--;
		}
		y--;
	}
	return (square);
}

/*
map	= 1D string of map
c	= char used to fill square
*/
void	fill_square(char *map, char c, int *square, int map_width)
{
	int	x;
	int	y;

	y = square[1] - square[2];
	while (y < square[1])
	{
		x = square[0] - square[2];
		while (x < square[0])
		{
			map[get_xy_coord(x + 1, y + 1, map_width)] = c;
			x++;
		}
		y++;
	}
}

//Input coords to return the char index of that position
// 0, 0 will return 0
int	get_xy_coord(int x_coord, int y_coord, int map_width)
{
	map_width++;
	return (map_width * y_coord + x_coord);
}
