/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:12:44 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/03 00:22:07 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

struct	s_dict
{
	char	*key;
	char	*value;
};
/* array_helper.c */
short	**create_2d(int width, int height);
int		*find_square(short **m, int w, int h);
void	fill_square(char *map, char c, int *square, int map_width);
int		get_xy_coord(int x_coord, int y_coord, int map_width);
/* conversions.c */
int		string_to_int(const char *str);
int		min(int a, int b, int c);
/* display.c */
void	print_char(char c);
void	print_string(char *str);
void	print_number(int nb);
void	print_short_map(short **arr, int width, int height);
/* file.c */
char	*read_file(char *file);
char	*read_stdin(void);
/* map_helper.c */
char	get_empty_char(char *map);
char	get_obstical_char(char *map);
int		get_width_of_map(char *map);
char	get_square_char(char *map);
/* map_validator.c */
int		is_map_valid(char *map);
int		are_chars_valid(char *map, int start);
int		is_width_valid(char *map, int start);
int		is_height_valid(char *map, int start);
/* map.c */
void	start_map(char *map_file_name);
void	main_map(char *map_string, char *chars, int m_x, int m_y);
short	**create_short_copy(char *m_s, char *c, int w, int h);
void	calculate_squares(short **m, int w, int h);
/* string.c */
int		is_char_in_arr(char c, char *arr);
int		pos_char_in_array(char c, char *arr);
int		get_string_size(char *str);
int		is_printable(char c);
char	*ft_strstr(char *str, char *to_find);
#endif