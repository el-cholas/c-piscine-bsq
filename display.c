/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:43:36 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 20:27:36 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		print_char(str[i]);
		i++;
	}
}

void	print_number(int nb)
{
	if (nb < 0)
	{
		print_char('-');
		if (nb == -2147483648)
		{
			print_char('2');
			nb = 147483648;
		}
		else
		{
			nb *= -1;
		}
	}
	if (nb < 10)
	{
		print_char(nb + '0');
	}
	else
	{
		print_number(nb / 10);
		print_char(nb % 10);
	}
}

// for viewing pleasures
void	print_short_map(short **arr, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y <= height)
	{
		x = 0;
		while (x < width)
		{
			print_number(arr[y][x++]);
			print_string("\t");
		}
		print_string("\n");
		y++;
	}
}
