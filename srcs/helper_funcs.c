/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:51:44 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:39:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int			get_width(char *line)
{
	int width;
	int pointer;

	width = 0;
	pointer = 1;
	while (*line)
	{
		if (pointer != (*line == ' '))
			if (pointer)
				width++;
		pointer = (*line == ' ');
		line++;
	}
	return (width);
}

t_map		*set_height_width(t_map *matrix)
{
	matrix->width = MAPWIDTH;
	matrix->height = MAPHEIGHT;
	return (matrix);
}
