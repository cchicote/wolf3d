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
# define MAPX 5
# define MAPY 5
# define WINX 200
# define WINY 200

typedef struct			s_env
{
	void				*win;
	void				*mlx;
	void				*img;
	char				*data;
	int					bpp;
	int					sl;
	int					endian;
	char				**map;
}						t_env;

typedef	struct			s_param
{
	double				cam_h;			// hauteur de la camera
	double				cam_o;			// orientation de la camera
	double				fov;			// field of view -> champ de vision
	double				camposx;		// position x de la camera
	double				camposy;		// position y de la camera
	double				pss;			// projection screen's size -> taille de l'ecran de projection
}						t_param;


/*
** MAIN.C
*/

int						main(void);
void					env_init(t_env *e);

/*
** MANAGE_MAP.C
*/

void					put_data(t_env *e);
char					*flat_map(void);
void					map_init(t_env *e);
void					display_map(t_env *e);

/*
** MANAGE_KEY.C
*/

int						manage_key(int keycode, void *e);
void					treat_keycode(int keycode, t_env *e);

/*
** DRAW.C
*/

void					my_pixel_put(t_env *e, int x, int y, int color);


#endif