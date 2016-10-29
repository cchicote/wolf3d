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

int           main(void)
{
  t_env     e;
  t_param   p;
  t_all     a;
  t_xpm     sky;
  t_xpm     wal;

  env_init(&e);
  if (xpm_init(&sky, &e, "xpm_files/sky360.xpm") == -1 ||
    xpm_init(&wal, &e, "xpm_files/wall1.xpm") == -1)
  {
    ft_putendl("probleme xpm");
    return (0);
  }
  param_init(&p);
  a.en = &e;
  a.pa = &p;  
  a.sky = &sky;
  a.wal = &wal;
  calc_dda(&a);
  mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
  mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &a);
  mlx_hook(e.win, 17, 0, destroy, &e);
  mlx_loop(e.mlx);
  return (0);
}

int          destroy(int key, void *e)
{
  if (!key && !e)
  {
    key++;
    e++;
  }
  exit(0);
  return (0);
}

int           xpm_init(t_xpm *x, t_env *e, char *path)
{
  int       width;
  int       height;

  if (!(x->img = mlx_xpm_file_to_image(e->mlx, path, &width, &height)))
    return (-1);
  x->width = WINX;
  x->height = WINY;
  x->data = mlx_get_data_addr(x->img, &(x->bpp), &(x->sl), &(x->endian));
  return (0);
}

void           env_init(t_env *e)
{
  static int      tmp[MAPX][MAPY] ={
    {1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1}};
    
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
  p->rot_speed = 0.05;
  p->straf_speed = 0.125;
  p->texsize = 256;
  p->sky = 0x66CCFF;
  p->ground = 0x333333;
  p->reverse = 0;
}
