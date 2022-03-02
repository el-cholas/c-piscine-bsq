/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:14:18 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/02 06:40:29 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
char	*read_file(char *file)
{
	
}
*/

char	*read_file(char *file)
{
	char	*file_memory;
	int		file_read;
	int		file_open;
	char	*file_content;
	int		count;

	file_open = open(file, O_RDONLY);
	if (file_open < 0)
	{
		return (0);
	}
	file_memory = (char *)malloc(sizeof(char) * 5000);
	file_read = read(file_open, file_memory, 5000);
	file_content = (char *)malloc(sizeof(char) * (file_read + 1));
	count = 0;
	while (count < file_read)
	{
		file_content[count] = file_memory[count];
		count++;
	}
	file_content[count] = '\0';
	free(file_memory);
	close(file_open);
	return (file_content);
}
