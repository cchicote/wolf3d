/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:18:02 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/30 12:33:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		env_init(t_env *e)
{
	char		tmp[MAPY][MAPX] = {
		{'1', '1', '1', '1'},
		{'0', '0', '0', '1'},
		{'0', '0', '0', '1'	}};

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINX, WINY, "wolf3d");
	e->img = mlx_new_image(e->mlx, WINX, WINY);
	e->data = mlx_get_data_addr(e->img, &(e->bpp),
		&(e->sl), &(e->endian));
	ft_memcpy(e->map, tmp, sizeof(tmp));
}

void		param_init(t_param *p)
{
	p->wall_h = 64;
	p->cam_h = p->wall_h / 2;
	p->fov = 60;
	p->pov = 45;
	p->camposx = 96;
	p->camposy = 160;
	p->col = p->fov / WINX;
}


int			main(void)
{
	t_env		e;
	t_param		p;

	env_init(&e);
	param_init(&p);
	display_map(&e);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
