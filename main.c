/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcarroll <xcarroll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 04:42:49 by xcarroll          #+#    #+#             */
/*   Updated: 2022/03/01 18:23:26 by xcarroll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	maps;
	int	current_map;

	maps = argc - 1;
	current_map = 0;
	while (current_map < maps)
	{
		start_map(argv[current_map + 1]);
		current_map++;
		if (current_map < maps)
			print_string("\n");
	}
	if (maps == 0)
	{
		/* Standard input shit */
	}
}
