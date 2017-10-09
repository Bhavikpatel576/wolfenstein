/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <math.h>

void				rt_ray_calculation(t_vect *ray, t_window *tmp)
{
	int				texnum;
	double			wallx;
	int				texx;

	texnum = tmp->map->matrix_values[tmp->mapx][tmp->mapy] - 1;
	if (ray->side == 0)
		wallx = tmp->rayposy + tmp->prepwalldist * tmp->raydiry;
	else
		wallx = tmp->rayposx + tmp->prepwalldist * tmp->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)(TEXWIDTH));
	if (ray->side == 0 && tmp->raydirx > 0)
		texx = TEXWIDTH - texx - 1;
	if (ray->side == 1 && tmp->raydiry < 0)
		texx = TEXWIDTH - texx - 1;
}

void				rt_draw(t_vect ray, t_window *tmp, int x)
{
	int				d;
	int				texy;
	int				y;
	unsigned int	color;

	rt_ray_calculation(&ray, tmp);
	y = ray.drawstart;
	while (y < ray.drawend)
	{
		d = y * 256 - WIN_H * 128 + ray.lineheight * 128;
		texy = ((d * TEXHEIGHT) / ray.lineheight) / 256;
		color = tmp->texture[ray.texnum][TEXHEIGHT * texy + ray.texx];
		if (ray.side == 1)
			color = (color >> 1) & 8355711;
		y++;
	}
	y = ray.drawstart;
	while (y++ < ray.drawend)
		mlx_pixel_put(tmp->mlx, tmp->win, x, y, color);
	rt_floor(tmp, &ray, x);
}

void				ray_direction(t_window *w)
{
	if (w->raydirx < 0)
	{
		w->stepx = -1;
		w->sidedistx = (w->rayposx - w->mapx) * w->deltadistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedistx = (w->mapx + 1 - w->rayposx) * w->deltadistx;
	}
	if (w->raydiry < 0)
	{
		w->stepy = -1;
		w->sidedisty = (w->rayposy - w->mapy) * w->deltadisty;
	}
	else
	{
		w->stepy = 1;
		w->sidedisty = (w->mapy + 1 - w->rayposy) * w->deltadisty;
	}
}

void				ray_trace_loop(t_window *tmp)
{
	int				x;
	t_window		w;
	t_vect			ray;

	w = *tmp;
	x = 0;
	while (x < WIN_W)
	{
		w.camerax = 2 * x / (double)WIN_W - 1;
		w.rayposx = w.posx;
		w.rayposy = w.posy;
		w.raydirx = w.dirx + w.planx * w.camerax;
		w.raydiry = w.diry + w.plany * w.camerax;
		w.mapx = (int)w.rayposx;
		w.mapy = (int)w.rayposy;
		w.deltadistx = sqrt(1 + (w.raydiry * w.raydiry)
			/ (w.raydirx * w.raydirx));
		w.deltadisty = sqrt(1 + (w.raydirx * w.raydirx)
			/ (w.raydiry * w.raydiry));
		ray_direction(&w);
		ray.side = dda_algo(&w);
		ray_calculation(&ray, &w);
		rt_draw(ray, &w, x);
		x++;
	}
}
