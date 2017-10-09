/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:42:14 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/15 01:42:16 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move_right(t_window *window, double rotspeed)
{
	double		olddirx;
	double		oldplanx;

	olddirx = window->dirx;
	window->dirx = window->dirx * cos(-rotspeed)
		- window->diry * sin(-rotspeed);
	window->diry = olddirx * sin(-rotspeed)
		+ window->diry * cos(-rotspeed);
	oldplanx = window->planx;
	window->planx = window->planx * cos(-rotspeed)
		- window->plany * sin(-rotspeed);
	window->plany = oldplanx * sin(-rotspeed) + window->plany * cos(-rotspeed);
	window->sdlk_right = 0;
}

void			move_left(t_window *window, double rotspeed)
{
	double		olddirx;
	double		oldplanx;

	olddirx = window->dirx;
	window->dirx = window->dirx * cos(rotspeed) - window->diry * sin(rotspeed);
	window->diry = olddirx * sin(rotspeed) + window->diry * cos(rotspeed);
	oldplanx = window->planx;
	window->planx = window->planx * cos(rotspeed)
		- window->plany * sin(rotspeed);
	window->plany = oldplanx * sin(rotspeed) + window->plany * cos(rotspeed);
	window->sdlk_left = 0;
}

void			move_up(t_window *window, int **worldmap, double movespeed)
{
	if (worldmap[(int)(window->posx + window->dirx * movespeed)]
		[(int)(window->posy)] == 0)
		window->posx += window->dirx * movespeed;
	if (worldmap[(int)(window->posx)]
		[(int)(window->posy + window->diry * movespeed)] == 0)
		window->posy += window->diry * movespeed;
	window->sdlk_up = 0;
}

void			move_down(t_window *window, int **worldmap, double movespeed)
{
	if (worldmap[(int)(window->posx - window->dirx * movespeed)]
		[(int)(window->posy)] == 0)
		window->posx -= window->dirx * movespeed;
	if (worldmap[(int)(window->posx)]
		[(int)(window->posy - window->diry * movespeed)] == 0)
		window->posy -= window->diry * movespeed;
	window->sdlk_down = 0;
}
