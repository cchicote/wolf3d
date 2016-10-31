/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:18:02 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/31 17:38:54 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				main(void)
{
	t_env			e;
	t_param			p;
	t_all			a;
	t_xpm			t[NTEX];

	env_init(&e);
	param_init(&p);
	a.en = &e;
	a.pa = &p;
	a.te[0] = xpm_init(&t[0], &e, "xpm_files/sky360.xpm");
	a.te[1] = xpm_init(&t[1], &e, "xpm_files/wall1.xpm");
	a.te[2] = xpm_init(&t[2], &e, "xpm_files/dirt.xpm");
	a.te[3] = xpm_init(&t[3], &e, "xpm_files/door.xpm");
	a.te[4] = xpm_init(&t[4], &e, "xpm_files/wut.xpm");
	a.te[5] = xpm_init(&t[5], &e, "xpm_files/portal.xpm");
	a.te[6] = xpm_init(&t[6], &e, "xpm_files/portal2.xpm");
	a.te[7] = xpm_init(&t[7], &e, "xpm_files/cobble.xpm");
	a.te[8] = xpm_init(&t[8], &e, "xpm_files/infos.xpm");
	a.te[9] = xpm_init(&t[9], &e, "xpm_files/inputs.xpm");
	calc_dda(&a);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &a);
	mlx_hook(e.win, 17, 0, destroy, &e);
	mlx_loop(e.mlx);
	return (0);
}

int				destroy(int key, void *e)
{
	if (!key && !e)
	{
		key++;
		e++;
	}
	exit(0);
	return (0);
}

t_xpm			*xpm_init(t_xpm *x, t_env *e, char *path)
{
	int			width;
	int			height;

	if (!(x->img = mlx_xpm_file_to_image(e->mlx, path, &width, &height)))
		return (NULL);
	x->width = WINX;
	x->height = WINY;
	x->data = mlx_get_data_addr(x->img, &(x->bpp), &(x->sl), &(x->endian));
	return (x);
}

void			env_init(t_env *e)
{
	static int		tmp[MAPX][MAPY] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 0, 0, 0, 7, 0, 7, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 7, 0, 7, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 1, 8, 9, 1},
		{1, 6, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINX, WINY, "wolf3d");
	e->img = mlx_new_image(e->mlx, WINX, WINY);
	e->data = mlx_get_data_addr(e->img, &(e->bpp),
			&(e->sl), &(e->endian));
	ft_memcpy(e->map, tmp, sizeof(tmp));
}

void			param_init(t_param *p)
{
	p->posx = 10.5;
	p->posy = 10;
	p->dirx = -1;
	p->diry = 0;
	p->planex = 0;
	p->planey = 0.66;
	p->move_speed = 0.25;
	p->rot_speed = 0.05;
	p->straf_speed = 0.125;
	p->texsize = 256;
	p->ground = 0x333333;
	p->reverse = 0;
}
