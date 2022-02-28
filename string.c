/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:32:13 by xcarroll          #+#    #+#             */
/*   Updated: 2022/02/28 18:42:18 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
0 = False
1 = True
*/
int	is_char_in_arr(char c, char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		if (arr[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* This will return the position of the first instance of the char */
int	pos_char_in_array(char c, char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
	{
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_string_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
