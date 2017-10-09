/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:18 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:47:11 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

/*
** initialize the struct t_window by passing in a pointer. Intiialization
** will assign values that are grouped into three categories. The first
** group of variables handle setting up the mlx items, the second group
** are variables related to position of user, and the last group will
** be related to handling camera angles
*/

void	initialize_window(t_window *window, t_map *copy)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIN_W, WIN_H, "Raycaster");
	window->img = mlx_new_image(window->mlx, WIN_H, WIN_W);
	window->pixel_data = (unsigned int*)mlx_get_data_addr(window->img,
		&window->bpp, &window->size_line, &window->endian);
	window->floorxwall = 0;
	window->floorywall = 0;
	window->distwall = 0;
	window->distplayer = 0;
	window->currentdist = 0;
	window->weight = 0;
	window->currentfloorx = 0;
	window->currentfloory = 0;
	window->bpp = 0;
	window->endian = 0;
	window->size_line = 0;
	window->map = copy;
}

void	initialize_ray(t_window *window)
{
	window->sdlk_up = 0;
	window->sdlk_down = 0;
	window->sdlk_left = 0;
	window->sdlk_right = 0;
	window->posx = 22;
	window->posy = 11.5;
	window->camerax = 0;
	window->rayposx = 0;
	window->rayposy = 0;
	window->raydirx = 0;
	window->raydiry = 0;
	window->mapx = 24;
	window->mapy = 24;
	window->dirx = -1;
	window->diry = 0;
	window->planx = 0;
	window->plany = .66;
	window->sidedistx = 0;
	window->sidedisty = 0;
	window->deltadistx = 0;
	window->deltadisty = 0;
	window->prepwalldist = 0;
	window->stepy = 0;
	window->stepx = 0;
}
