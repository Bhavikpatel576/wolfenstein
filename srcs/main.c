/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:11 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 21:38:14 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <time.h>
#include <math.h>

int					main(int argc, char **argv)
{
	char			*file_name;
	t_window		*window;
	t_map			*map;

	if (argc != 2)
	{
		ft_puterror(1);
		return (0);
	}
	file_name = (argv[argc - 1]);
	if (ft_strcmp("./maps/map", file_name) != 0)
	{
		ft_puterror(1);
		return (0);
	}
	map = (t_map*)ft_memalloc(sizeof(t_map));
	window = (t_window*)ft_memalloc(sizeof(t_window));
	save_points(file_name, map);
	validate(file_name, map);
	initialize_window(window, map);
	initialize_ray(window);
	rt_texture(window);
	ray_trace(window, map->matrix_values);
	rerun(window);
}
