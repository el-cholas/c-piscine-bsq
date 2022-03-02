/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 01:27:45 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 02:45:35 by xcarroll         ###   ########.fr       */
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
