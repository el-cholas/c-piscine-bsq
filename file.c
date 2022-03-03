/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:14:18 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/03 18:10:17 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* 1 GB files supported */
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
		print_string("map error\n");
		exit(0);
	}
	file_memory = (char *)malloc(sizeof(char) * 1000000000);
	file_read = read(file_open, file_memory, 1000000000);
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

void	read_stdin(void)
{
	int		a;
	char	c;
	int		file;

	a = read(STDIN_FILENO, &c, 1);
	file = open("no_args.txt", O_CREAT | O_RDWR | O_TRUNC, 0755);
	while (a != 0)
	{
		write(file, &c, 1);
		a = read(STDIN_FILENO, &c, 1);
	}
	close(file);
}
