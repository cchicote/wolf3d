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

void          env_init(t_env *e)
{
	int		tmp[MAPX][MAPY] ={
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINX, WINY, "wolf3d");
	e->img = mlx_new_image(e->mlx, WINX, WINY);
	e->data = mlx_get_data_addr(e->img, &(e->bpp),
		&(e->sl), &(e->endian));
	ft_memcpy(e->map, tmp, sizeof(tmp));
}

void          param_init(t_param *p)
{
	p->posx = 22;
	p->posy = 12;
  p->dirx = -1;
  p->diry = 0;
  p->planex = 0;
  p->planey = 0.66;
  p->move_speed = 0.25;
  p->rot_speed = 0.05;
  // p->angle_from_base = 45;
  // p->alpha_from_base = degre_to_rad(p->angle_from_base);
  // p->pl_size = (int)SIZE / 2;
  // p->fov = 60.0;
  // p->fovrad = degre_to_rad(p->fov);
  // p->dps = (WINX / 2) / tan(degre_to_rad(p->fov / 2));
  // p->hcam = SIZE / 2;
  // p->angle_bas = p->angle_from_base - (p->fov / 2);
  // p->angle_haut = p->angle_from_base + (p->fov / 2);
  // p->step = p->fov / WINX;
  // printf("%f\n", p->step);
}

void          loading_screen(t_all *a)
{
  int x;
  int y;

  y = -1;
  while (++y < WINY)
  {
    x = -1;
    while (++x < WINX)
    {
      if (x % 3 == 0)
        my_pixel_put(a->en, x, y, 0xff4500);
      else
        my_pixel_put(a->en, x, y, 0x663399);
    }
  }
  mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
  mlx_string_put(a->en->mlx, a->en->win, WINX / 2 - 60, WINY / 2 - 25, 0xffffff, "PRESS ENTER");
}

int		       	main(void)
{
	t_env		  e;
	t_param		p;
	t_all		  a;

	env_init(&e);
	param_init(&p);
	a.en = &e;
	a.pa = &p;
	// display_map(&a);
  // loading_screen(&a);  
  calc_dda(&a);
  mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &a);
	mlx_loop(e.mlx);
	return (0);
}
