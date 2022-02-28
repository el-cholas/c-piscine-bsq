/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:14:18 by xcarroll          #+#    #+#             */
/*   Updated: 2022/02/28 16:16:28 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_error(int fun)
{
	if (fun < 0)
	{
		write(1, "File Error\n", 11);
		exit (1);
	}
}

char	*read_file(char *file)
{
	char	*dict_memory;
	int		dict_read;
	int		dict_open;
	char	*dict;
	int		count;

	dict_open = open(file, O_RDONLY);
	check_error(dict_open);
	dict_memory = (char *)malloc(sizeof(char) * 2000);
	dict_read = read(dict_open, dict_memory, 2000);
	dict = (char *)malloc(sizeof(char) * (dict_read + 1));
	count = 0;
	while (count < dict_read)
	{
		dict[count] = dict_memory[count];
		count++;
	}
	dict[count] = '\0';
	free(dict_memory);
	close(dict_open);
	return (dict);
}