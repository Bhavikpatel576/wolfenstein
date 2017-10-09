/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:51:44 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:39:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_puterror(int code)
{
	if (code == 1)
		ft_putendl_fd("Usage Reminder: ./wolf3d ./maps/map", 2);
	if (code == 2)
	{
		ft_putendl_fd("Incorrect map file", 2);
		exit(1);
	}
	if (code == 3)
	{
		ft_putendl_fd("Incorrect map size", 2);
		exit(1);
	}
}

void	ft_freetmp(void **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		ft_memdel((void**)&tmp[i]);
		i++;
	}
	ft_memdel((void**)&tmp[i]);
	ft_memdel((void**)&tmp);
}

void	ft_linecleanup(void **tmp)
{
	ft_freetmp(tmp);
	ft_puterror(2);
}

void	ft_cleanall(void **tmp)
{
	ft_linecleanup(tmp);
}

void	ft_freemlxdata(t_window *d)
{
	int		i;

	if (d->map->matrix_values)
	{
		i = 0;
		while (i < d->map->height)
		{
			ft_memdel((void**)&d->map->matrix_values[i]);
			i++;
		}
		ft_memdel((void**)&d->map->matrix_values);
	}
}
