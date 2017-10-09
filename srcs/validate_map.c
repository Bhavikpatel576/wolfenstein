/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				validate_map_nums(t_map *matrix)
{
	int			i;
	int			j;
	int			z_value;

	z_value = 0;
	i = -1;
	while (++i < matrix->height)
	{
		j = -1;
		while (++j < matrix->width)
		{
			if (matrix->matrix_values[i][j] > 4
				|| matrix->matrix_values[i][j] < 0)
			{
				ft_puterror(2);
				return (-1);
			}
		}
	}
	return (0);
}

int				validate_map_size(char *filename, t_map *matrix)
{
	int			fd;
	int			x;
	int			w;
	int			h;
	char		*line;

	x = 0;
	w = 0;
	h = 0;
	fd = open(filename, O_RDONLY);
	while ((x = get_next_line(fd, &line)) > 0)
	{
		while (line[w])
			w++;
		ft_memdel((void**)&line);
		h++;
	}
	ft_memdel((void**)&line);
	w = (w + 1) / 2;
	if (matrix->height != h || matrix->width != w)
		ft_puterror(3);
	close(fd);
	return (1);
}

void			validate(char *filename, t_map *matrix)
{
	validate_map_nums(matrix);
	validate_map_size(filename, matrix);
}
