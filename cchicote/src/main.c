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
  int   tmp[MAPX][MAPY] ={
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,2,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
  {1,0,3,0,1,0,2,0,2,0,2,0,0,5,1,0,1,1,1,0,5,0,5,1},
  {1,0,4,0,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,1},
  {1,0,5,0,1,0,2,0,2,0,2,0,0,3,0,0,1,2,1,0,5,0,5,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1},
  {1,2,1,0,0,0,0,0,0,0,4,0,0,0,1,1,0,2,0,1,1,0,1,1},
  {2,0,2,0,0,0,0,0,0,4,0,0,4,1,2,0,0,0,0,1,1,0,1,1},
  {2,0,2,0,0,0,0,0,4,0,0,4,0,1,1,1,0,2,0,1,1,0,0,1},
  {2,0,2,0,0,0,0,4,0,0,4,0,0,1,2,0,0,0,0,1,1,1,0,1},
  {2,0,2,0,0,0,4,0,0,4,0,0,0,1,1,1,0,2,0,1,1,1,0,1},
  {2,0,2,0,0,4,0,0,4,0,0,0,0,1,2,0,0,0,0,1,1,1,0,1},
  {2,0,2,0,4,0,0,4,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
  {1,7,1,4,0,0,4,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1},
  {1,1,0,4,6,4,0,0,0,0,0,0,0,1,1,1,1,2,1,2,1,2,1,1},
  {1,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

	// int		tmp[MAPX][MAPY] ={
 //  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
 //  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
 //  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,0,4,0,0,0,0,4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,0,4,4,4,4,4,4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 //  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINX, WINY, "wolf3d");
	e->img = mlx_new_image(e->mlx, WINX, WINY);
	e->data = mlx_get_data_addr(e->img, &(e->bpp),
		&(e->sl), &(e->endian));
	ft_memcpy(e->map, tmp, sizeof(tmp));
}

void          param_init(t_param *p)
{
	p->posx = 1.5;
	p->posy = 1.5;
  p->dirx = -1;
  p->diry = 0;
  p->planex = 0;
  p->planey = 0.66;
  p->move_speed = 0.25;
  p->rot_speed = 0.1;
  p->texsize = 256;
}

int          xpm_init(t_xpm *x, t_env *e)
{
  int       width;
  int       height;

  if (!(x->img = mlx_xpm_file_to_image(e->mlx, "src/adorablesealinthesnow.xpm", &width, &height)))
    return (-1);
  x->width = width;
  x->height = height;
  x->data = mlx_get_data_addr(x->img, &(x->bpp), &(x->sl), &(x->endian));
  return (0);
}

int		       	main(void)
{
	t_env		  e;
	t_param		p;
	t_all		  a;
  t_xpm     x;

	env_init(&e);
	param_init(&p);
  if (xpm_init(&x, &e) == -1)
  {
    ft_putendl("probleme xpm");
    return (0);
  }
	a.en = &e;
	a.pa = &p;  
  a.xp = &x;
  calc_dda(&a);
  mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
  mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &a);
	mlx_loop(e.mlx);
	return (0);
}
