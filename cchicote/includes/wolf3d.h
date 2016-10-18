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
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# define MAPX 24
# define MAPY 24
# define WINX 1280.0
# define WINY 760.0
# define SIZE 64.0

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	void				*img;
	char				*data;
	int					bpp;
	int					sl;
	int					endian;
	int					map[MAPY][MAPX];
}						t_env;

typedef	struct			s_param
{
	double				posx;			//position du joueur (de la camera)
	double				posy;			//
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				cameray;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	double				move_speed;
	double				rot_speed;
	// double				angle_from_base;			// orientation du joueur en degres	
	// double				alpha_from_base;			// orientation du joueur (de la camera) en radian (c'est l'angle transforme en radian)
	// double				m;				// slope -> pente
	// double				b;				// intersection sur l'axe y
	// double				xcol;
	// int					xonmap;
	// int					yonmap;
	// int					pl_size;
	// double				fov;			// champ de vision en degres
	// double				fovrad;			// champ de vision en radian
	// double				dps;			// distance projection screen
	// double				wall_h;
	// double				hcam;
	// double				angle_haut;
	// double				angle_bas;
	// double				step;			// angle entre deux rayons (en degres)
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
}						t_all;



/*
** MAIN.C
*/

int						main(void);
void					env_init(t_env *e);
void					param_init(t_param *p);
void  			        loading_screen(t_all *a);


/*
** MANAGE_MAP.C
*/

void					display_map(t_all *a);


/*
** MANAGE_KEY.C
*/

int						manage_key(int keycode, void *a);
void					treat_keycode(int keycode, t_all *a);

/*
** DRAW.C
*/

void					my_pixel_put(t_env *e, int x, int y, int color);
t_res					ddax(t_all *a);
t_res					dday(t_all *a);
void					calc_dda(t_all *a);
double					sq(double a);
double					degre_to_rad(double angle);


#endif