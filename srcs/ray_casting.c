/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#define S 65536

void				create_texture(t_window *tmp, int **t)
{
	int				x;
	int				y;
	int				xorcolor;
	int				ycolor;
	int				xycolor;

	x = 0;
	while (x < TEXWIDTH)
	{
		y = 0;
		while (y < TEXHEIGHT)
		{
			xorcolor = (x * 256 / TEXWIDTH) ^ (y * 256 / TEXHEIGHT);
			ycolor = y * 256 / TEXHEIGHT;
			xycolor = y * 128 / TEXHEIGHT + x * 128 / TEXWIDTH;
			t[0][TEXWIDTH * y + x] = S * 254 * (x != y && x != TEXWIDTH - y);
			t[1][TEXWIDTH * y + x] = xycolor + 256 * xycolor + S * xycolor;
			t[2][TEXWIDTH * y + x] = 256 * xycolor + S * xycolor;
			t[3][TEXWIDTH * y + x] = xorcolor + 256 * xorcolor + S * xorcolor;
			t[4][TEXWIDTH * y + x] = 256 * xorcolor;
			y++;
		}
		x++;
	}
	tmp->texture = t;
}

void				rt_texture(t_window *tmp)
{
	int				**t;
	int				i;

	t = (int**)ft_memalloc(sizeof(int*) * (6));
	i = 0;
	while (i < 6)
	{
		t[i] = (int*)ft_memalloc(sizeof(int) * (TEXWIDTH * TEXHEIGHT));
		i++;
	}
	create_texture(tmp, t);
}

void				ray_calculation(t_vect *ray, t_window *w)
{
	if (ray->side == 0)
		w->prepwalldist = (w->mapx - w->rayposx
			+ (1 - w->stepx) / 2) / w->raydirx;
	else
		w->prepwalldist = (w->mapy - w->rayposy
			+ (1 - w->stepy) / 2) / w->raydiry;
	ray->lineheight = (int)(WIN_H / w->prepwalldist);
	ray->drawstart = -(ray->lineheight) / 2 + WIN_H / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + WIN_H / 2;
	if (ray->drawend >= WIN_H)
		ray->drawend = WIN_H - 1;
	ray->texnum = w->map->matrix_values[w->mapx][w->mapy] - 1;
	if (ray->side == 0)
		ray->wallx = w->rayposy + w->prepwalldist * w->raydiry;
	else
		ray->wallx = w->rayposx + w->prepwalldist * w->raydirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)(TEXWIDTH));
	if (ray->side == 0 && w->raydirx > 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
	if (ray->side == 1 && w->raydiry < 0)
		ray->texx = TEXWIDTH - ray->texx - 1;
}

void				ray_trace(t_window *w, int **worldmap)
{
	double			frametime;
	double			movespeed;
	double			rotspeed;

	frametime = .50;
	movespeed = frametime * 2.0;
	rotspeed = frametime * 1.0;
	if (w->sdlk_up)
		move_up(w, worldmap, movespeed);
	if (w->sdlk_down)
		move_down(w, worldmap, movespeed);
	if (w->sdlk_right)
		move_right(w, rotspeed);
	if (w->sdlk_left)
		move_left(w, rotspeed);
	ray_trace_loop(w);
}

int					dda_algo(t_window *w)
{
	int				hit;
	int				side;

	hit = 0;
	while (hit == 0)
	{
		if (w->sidedistx < w->sidedisty)
		{
			w->sidedistx += w->deltadistx;
			w->mapx += w->stepx;
			side = 0;
		}
		else
		{
			w->sidedisty += w->deltadisty;
			w->mapy += w->stepy;
			side = 1;
		}
		if (w->map->matrix_values[w->mapx][w->mapy] > 0)
			hit = 1;
	}
	return (side);
}
