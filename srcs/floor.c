/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void				floor_points(t_window *window, t_vect *ray)
{
	if (ray->side == 0 && window->raydirx > 0)
	{
		window->floorxwall = window->mapx;
		window->floorywall = window->mapy + ray->wallx;
	}
	else if (ray->side == 0 && window->raydirx < 0)
	{
		window->floorxwall = window->mapx + 1.0;
		window->floorywall = window->mapy + ray->wallx;
	}
	else if (ray->side == 1 && window->raydiry > 0)
	{
		window->floorxwall = window->mapx + ray->wallx;
		window->floorywall = window->mapy;
	}
	else
	{
		window->floorxwall = window->mapx + ray->wallx;
		window->floorywall = window->mapy + 1.0;
	}
}

void				print_floor(t_window *window, int x, int y, int h)
{
	unsigned int color;

	color = RGB_WHITE;
	mlx_pixel_put(window->mlx, window->win, x, y, color);
	color = RGB_BLUE;
	mlx_pixel_put(window->mlx, window->win, x, h - y, color);
}

void				rt_floor(t_window *window, t_vect *ray, int x)
{
	int				floortexx;
	int				floortexy;
	int				h;
	int				y;

	h = WIN_H;
	floor_points(window, ray);
	window->distwall = window->prepwalldist;
	if (ray->drawend < 0)
		ray->drawend = h;
	y = ray->drawend + 1;
	while (y++ < h)
	{
		window->currentdist = h / (2.0 * y - h);
		window->weight = (window->currentdist - window->distplayer)
			/ (window->distwall - window->distplayer);
		window->currentfloorx = window->weight * window->floorxwall
			+ (1.0 - window->weight) * window->posx;
		window->currentfloory = window->weight * window->floorywall
			+ (1.0 - window->weight) * window->posy;
		floortexx = (int)(window->currentfloorx * TEXWIDTH) % TEXWIDTH;
		floortexy = (int)(window->currentfloory * TEXHEIGHT) % TEXHEIGHT;
		print_floor(window, x, y, h);
	}
}
