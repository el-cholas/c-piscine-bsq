/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 01:12:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/02/28 16:35:57 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

struct	s_dict
{
	char	*key;
	char	*value;
};

/* display.c */
void	print_char(char c);
void	print_string(char *str);
void	print_number(int nb);
/* file.c */
char	*read_file(char *file);
/* map.c */
void	start_map(char *map);
#endif