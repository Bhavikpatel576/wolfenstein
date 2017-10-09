/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:58:37 by bpatel            #+#    #+#             */
/*   Updated: 2017/03/22 16:42:19 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <libft.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# define RGB_RED 0xff0000;
# define RGB_GREEN 0xff00;
# define RGB_BLUE 0x87cefa;
# define RGB_WHITE 0xbebebe;
# define RGB_YELLOW 0x9acd32;
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define SHIFTRIGHT	2
# define SHIFTLEFT 0
# define SHIFTUP 13
# define SHIFTDOWN 1
# define ZOOMOUT 6
# define ZOOMIN	7
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define WIN_H 500
# define WIN_W 800

typedef	struct		s_map
{
	int				height;
	int				width;
	int				**matrix_values;
}					t_map;

typedef	struct		s_vect
{
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texnum;
	double			wallx;
	unsigned int	color;
	int				texx;
}					t_vect;

typedef	struct		s_window
{
	int				id;
	void			*mlx;
	void			*win;
	void			*img;
	int				sdlk_up;
	int				sdlk_right;
	int				sdlk_down;
	int				sdlk_left;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			prepwalldist;
	int				stepy;
	int				stepx;
	int				bpp;
	int				endian;
	int				size_line;
	unsigned int	*pixel_data;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	int				**texture;
	t_map			*map;
}					t_window;

int					done(int ret);
void				verline(int x, int drawstart, int drawend,
	int color, t_window *win);
int					get_width(char *line);
t_map				*get_height_width(int fd, char **line, t_map *matrix);
t_map				*set_height_width(t_map *matrix);
void				rerun(t_window *window);
void				initialize_window(t_window *window, t_map *copy);
int					key_hooks(int keycode, t_window *t);
void				ray_trace_loop(t_window *tmp);
void				ray_trace(t_window *window, int **worldmap);
void				save_points(char *file_name, t_map *matrix);
void				save_matrix_points(t_map *matrix, t_window *window);
void				print_map(t_map *matrix);
void				rt_texture(t_window *tmp);
void				initialize_ray(t_window *window);
void				move_right(t_window *window, double rotspeed);
void				move_left(t_window *window, double rotspeed);
void				move_up(t_window *window, int **worldmap, double movespeed);
void				move_down(t_window *window, int **worldmap,
	double movespeed);
void				rt_floor(t_window *window, t_vect *ray, int x);
void				rt_texture(t_window *tmp);
void				ray_calculation(t_vect *ray, t_window *window);
void				ray_trace(t_window *window, int **worldmap);
int					dda_algo(t_window *window);
void				ft_freetmp(void **tmp);
void				ft_linecleanup(void **tmp);
void				ft_cleanall(void **tmp);
void				ft_puterror(int code);
void				ft_freemlxdata(t_window *d);
int					validate_map_nums(t_map *matrix);
int					validate_map_size(char *filename, t_map *matrix);
void				validate(char *filename, t_map *matrix);

#endif
