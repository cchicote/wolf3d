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

void		wall_init(t_env *e, t_param *p)
{
	int x;
	int y;
	int i;

	y = -1;
	i = 0;
	p->wallxs = ft_memalloc(sizeof(int) * MAPX);
	ft_bzero(p->wallxs, sizeof(int) * MAPX);
	p->wallxe = ft_memalloc(sizeof(int) * MAPX);
	ft_bzero(p->wallxe, sizeof(int) * MAPX);
	p->wallys = ft_memalloc(sizeof(int) * MAPY);
	ft_bzero(p->wallys, sizeof(int) * MAPY);
	p->wallye = ft_memalloc(sizeof(int) * MAPY);
	ft_bzero(p->wallye, sizeof(int) * MAPY);
	while (++y != MAPY)
	{
		x = -1;
		while (++x != MAPX)
		{
			if (e->map[y][x] == '1')
			{
				p->wallxs[i] = x * 64;
				p->wallxe[i] = (x + 1) * 64;
				p->wallys[i] = y * 64;
				p->wallye[i] = (y + 1) * 64;
				i++;
			}
		}
	}
}


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

void		param_init(t_param *p, t_env *e)
{
	p->wall_h = 64;
	p->cam_h = p->wall_h / 2;
	p->fov = 60;
	p->pov = 45;
	p->camposx = 96;
	p->camposy = 160;
	p->col = p->fov / WINX;
	wall_init(e, p);
}


int			main(void)
{
	t_env		e;
	t_param		p;

	env_init(&e);
	param_init(&p, &e);
	display_map(&e);
	ft_putnbrendl(p.wallxs[1]);
	ft_putnbrendl(p.wallxe[1]);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
