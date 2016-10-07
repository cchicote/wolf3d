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
	double				posX;			//position du vecteur du joueur
	double				posY;				//
	double				dirX;			// direction du joueur
	double				dirY;				//
	double				planeX;			// le plan camera du joueur
	double				planeY;				//
	double				fov;			// field of fiew -> champ de vision
	// pour calculer le position et la direction du rayon
	double				cameraX;		// coordonnee X de la camera dans l'espace
	double				rayposX;		// position du rayon
	double				rayposY;			//
	double				raydirX;		// direction du rayon
	double				raydirY;			//
	int					mapX;			// dans quel carreau de la map est-on ?
	int					mapY;				//
	double				sidedistX;		// la longueur du rayon, de notre position jusqu'au prochain point x ou y
	double				sidedistY;			//
	double				deltadistX;		// la longueur du rayon, d'un point x (ou y) au x (ou y) suivant
	double				deltadistY;			//
	double				perpwalldist;		//
	int					stepX;			// dans quelle direction avancer (1 ou -1)
	int					stepY;				//
	int					hit;			// est-ce qu'un mur a ete touche ?
	int					side;			// Etait-ce au Nord/Sud ou a l'Est/Ouest ?
	int					lineheight;		// hauteur de la ligne a dessiner sur l'ecran
	int					drawstart;		// premier pixel a dessiner -> le plus bas et le plus haut pixel a dessiner sur la meme bande
	int					drawend;		// dernier pixel a dessiner
	int					color;
}						t_param;


/*
** MAIN.C
*/

int						main(void);
void					env_init(t_env *e);
void					param_init(t_param *p);

/*
** MANAGE_MAP.C
*/

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