/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:27:45 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 03:39:05 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

short	**create_2d(int width, int height)
{
	short	**arr;
	int		x;
	int		y;

	y = 0;
	arr = (short **)malloc(sizeof(short *) * height);
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
takes input of pre-processed array
square is [posX, posY, height]
where pos x and y are bottom right corner

function goes throgh array backwards to always find top left
*/
void	find_squares(short **m, int w, int h)
{
	int	square[3];
	int	x;
	int	y;

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
	printf("x: %d\ny: %d\n", x, y);
	printf("x: %d\ny: %d\nsize: %d\n", square[0], square[1], square[2]);
}
