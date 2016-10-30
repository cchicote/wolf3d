/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:18:02 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/30 12:33:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/X.h"
# include "../minilibxLinux/mlx.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# define NTEX 10
# define MAPX 24
# define MAPY 24
# define TEXW 256
# define TEXH 256
# define SIZE 64.0
# define WINX 1024.0
# define WINY 760.0

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	void				*img;
	char				*data;
	int					sl;
	int					bpp;
	int					endian;
	int					map[MAPY][MAPX];
}						t_env;

typedef	struct 			s_xpm
{
	void				*img;
	char				*data;
	int					sl;
	int					bpp;
	int					width;
	int					height;
	int					endian;
}						t_xpm;

typedef	struct			s_param
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				wallx;
	double				planex;
	double				planey;
	double				camera;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	double				sidedistx;
	double				sidedisty;
	double				wallxbrut;
	double				rot_speed;
	double				move_speed;
	double				deltadistx;
	double				deltadisty;
	double				straf_speed;
	double				orientation;
	double				perpwalldist;
	int					hit;
	int					mapx;
	int					mapy;
	int					texx;
	int					texy;
	int					side;
	int					stepx;
	int					stepy;
	int					ground;
	int					texsize;
	int					reverse;
	int					drawend;
	int					drawstart;
	int					lineheight;
}						t_param;

typedef	struct			s_res
{
	double				x;
	double				y;
	double				dist;
}						t_res;

typedef	struct			s_all
{
	t_param				*pa;
	t_env				*en;
	t_xpm				*te[NTEX];
}						t_all;

/*
** MAIN.C
*/

int						main(void);
int          			destroy(int key, void *e);
t_xpm					*xpm_init(t_xpm *x, t_env *e, char *path);
void					env_init(t_env *e);
void					param_init(t_param *p);

/*
** MANAGE_KEY.C
*/

int						manage_key(int keycode, void *a);
void					check_case(t_all *a, int case_num);
void					treat_keycode(int keycode, t_all *a);

/*
** DRAW.C
*/

void					print_col(t_all *a, int x, int start, int end);
void					load_texel(t_all *a, int x, int y);
void					my_pixel_put(t_env *e, int x, int y, int color);
void					load_sky_to_data(t_all *a, int x, int y);

/*
** RAYCASTING.C
*/

void					ray_dda(t_all *a);
void					calc_dda(t_all *a);
void					init_dda(t_all *a, int x);
void					perf_dda(t_all *a);
void					prep_drawing(t_all *a);

/*
** CALC.C
*/

double					sq(double a);
double					degre_to_rad(double angle);
void					calc_walls(t_all *a);

/*
** MOVEMENTS.C
*/

void					moving(t_all *a, int fw);
void					strafing(t_all *a, int lr);
void					turning_left(t_all *a);
void					turning_right(t_all *a);
void					treat_movements(int keycode, t_all *a);

#endif