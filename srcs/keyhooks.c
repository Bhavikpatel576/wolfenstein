/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:18 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/20 20:47:11 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

/*
** function specific to the mlx_key_hook to recognize
** keyboard values. The function will reassign
** values in the t_window struct to relay where the user
** is located within the map to the program.
*/

int		key_hooks(int keycode, t_window *window)
{
	if (keycode == ESC)
	{
		ft_freemlxdata(window);
		exit(0);
	}
	else if (keycode == UP)
		window->sdlk_up = 1;
	else if (keycode == DOWN)
		window->sdlk_down = 1;
	else if (keycode == LEFT)
		window->sdlk_left = 1;
	else if (keycode == RIGHT)
		window->sdlk_right = 1;
	mlx_clear_window(window->mlx, window->win);
	ray_trace(window, window->map->matrix_values);
	return (0);
}

/*
** Set up the a function that calls the mlx loop and key hook. This
** will allow the program to recognize any exterinal values invoked
** by the mouse, keyboard, or the program. The loops will break once
** the program exits
*/

int		exit_hook(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	exit(0);
	return (0);
}

void	rerun(t_window *window)
{
	mlx_hook(window->win, 17, 0, exit_hook, window);
	mlx_key_hook(window->win, key_hooks, window);
	mlx_loop(window->mlx);
}
