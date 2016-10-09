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

void		param_init(t_param *p)
{
	p->fov = 2 * atan(0.66 / 1.0);
	p->posX = 22;
	p->posY = 12;
	p->dirX = -1;
	p->dirY = 0;
	p->planeX = 0;
	p->planeY = 0.66;
	p->hit = 0;
}

void		DDA(t_env *e, t_param *p)
{
	while (p->hit == 0)
	{
		if (p->sidedistX < p->sidedistY)
		{
			p->sidedistX += p->deltadistX;
			p->mapX += p->stepX;
			p->side = 0;
		}
		else
		{
			p->sidedistY += p->deltadistY;
			p->mapY += p->stepY;
			p->side = 1;
		}
		if (e->map[p->mapX][p->mapY] > 0)
		{
			// printf("%d\n", p->side);
			p->hit = 1;
		}
	}
}

void		choose_color(t_env *e, t_param *p)
{
	if (e->map[p->mapX][p->mapY] == 1)
	{
		// ft_putnbrendl(p->mapY);
		p->color = 0xff0000;
	}
	else if (e->map[p->mapX][p->mapY] == 2)
	{
		// ft_putnbrendl(p->mapY);		
		p->color = 0x00ff00;
	}
	else if (e->map[p->mapX][p->mapY] == 3)
	{
		// ft_putnbrendl(p->mapY);		
		p->color = 0x0000ff;
	}
	else if (e->map[p->mapX][p->mapY] == 4)
	{
		// ft_putnbrendl(p->mapY);		
		p->color = 0xffffff;
	}
	else
	{
		// ft_putnbrendl(p->mapY);
		p->color = 0xff00ff;
	}
}

// verLine(x, p->drawstart, p->drawend, p->color);

void		draw_vertical(t_env *e, t_param *p)
{
	int start;
	int	end;

	start = p->drawstart;
	end = p->drawend;
	// printf("start : %d, end : %d\n", p->drawstart, p->drawend);
	if (start > end && end > -1000)
	{
		while (start > end)
		{
			my_pixel_put(e, start, 64, p->color);
			start--;
		}
	}
	else if (start < end && end > -1000)
	{
		while (start < end)
		{
			my_pixel_put(e, start, 64, p->color);
			start++;
		}
	}
	else
		my_pixel_put(e, start, 64, p->color);	
}


int			test(t_env *e, t_param *p)
{
	int x;
	
	x = -1;
	display_map(e);
	p->rayposX = p->posX;
	p->rayposY = p->posY;
	p->mapX = (int)p->rayposX;
	p->mapY = (int)p->rayposY;
	ft_putnbrendl(p->mapX);
	ft_putnbrendl(p->mapY);
	while (++x < WINX)
	{
		p->cameraX = 2 * x / WINX - 1;
		p->raydirX = p->dirX + p->planeX * p->cameraX;
		p->raydirY = p->dirY + p->planeY * p->cameraX;
		p->deltadistX = sqrt(1 + (p->raydirY * p->raydirY) / (p->raydirX * p->raydirX));
		p->deltadistY = sqrt(1 + (p->raydirX * p->raydirX) / (p->raydirY * p->raydirY));
		if (p->raydirX < 0)
		{
			p->stepX = -1;
			p->sidedistX = (p->rayposX - p->mapX) * p->deltadistX;
		}
		else
		{
			p->stepX = 1;
			p->sidedistX = (p->mapX + 1.0 - p->rayposX) * p->deltadistX;
		}
		if (p->raydirY < 0)
		{
			p->stepY = -1;
			p->sidedistY = (p->rayposY - p->mapY) * p->deltadistY;
		}
		else
		{
			p->stepY = 1;
			p->sidedistY = (p->mapY + 1.0 - p->rayposY) * p->deltadistY;
		}
		DDA(e, p);
		if (p->side == 0)
			p->perpwalldist = (p->mapX - p->rayposX + (1 - p->stepX) / 2) / p->raydirX;
		else
			p->perpwalldist = (p->mapY - p->rayposY + (1 - p->stepY) / 2) / p->raydirY;
		p->lineheight = (int)(WINY / p->perpwalldist);
		p->drawstart = -(p->lineheight) / 2 + WINY / 2;
		if (p->drawstart < 0)
			p->drawstart = 0;
		p->drawend = p->lineheight / 2 + WINY / 2;
		if (p->drawend >= WINY)
			p->drawend = WINY - 1;
		choose_color(e, p);
		if (p->side == 1)
			p->color /= 2;
		draw_vertical(e, p);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}




int			main(void)
{
	t_env		e;
	t_param		p;

	env_init(&e);
	param_init(&p);
	test(&e, &p);
	mlx_hook(e.win, KeyPress, KeyPressMask, manage_key, &e);
	mlx_loop(e.mlx);
	return (0);
}
