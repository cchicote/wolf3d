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
# define WINX 512.0
# define WINY 384.0

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
	double				posX;			//position du joueur (de la camera)
	double				posY;			//
	double				alpha;	// orientation du joueur (de la camera);
	
}						t_param;

typedef	struct			s_all
{
	t_param				*para;
	t_env				*envi;
}						t_all;



/*
** MAIN.C
*/

int						main(void);
void					env_init(t_env *e);
void					param_init(t_param *p);
int						test(t_env *e, t_param *p);


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


#endif