/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:18 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:47:11 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				open_file(char *file_name)
{
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_putstr("something went wrong with open");
	return (fd);
}

void			save_points(char *file_name, t_map *matrix)
{
	char		*line;
	char		**line_to_copy;
	int			fd;
	int			i;
	int			j;

	i = -1;
	matrix = set_height_width(matrix);
	fd = open(file_name, O_RDONLY);
	matrix->matrix_values = (int**)malloc(sizeof(int*) * matrix->height * 2);
	while (++i < matrix->height)
	{
		matrix->matrix_values[i] = (int*)malloc(sizeof(int)
			* matrix->width);
		get_next_line(fd, &line);
		line_to_copy = ft_strsplit(line, ' ');
		ft_memdel((void**)&line);
		j = -1;
		while (++j < matrix->width)
			matrix->matrix_values[i][j] = ft_atoi(line_to_copy[j]);
		ft_freetmp((void**)line_to_copy);
	}
	close(fd);
}

void			print_map(t_map *matrix)
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
			printf("%d ", matrix->matrix_values[i][j]);
		}
		printf("\n");
	}
}
