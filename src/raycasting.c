/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 18:51:38 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/18 18:51:52 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			ray_dda(t_all *a)
{
	if (a->pa->raydirx < 0)
	{
		a->pa->stepx = -1;
		a->pa->sidedistx = (a->pa->rayposx - a->pa->mapx)
			* a->pa->deltadistx;
	}
	else
	{
		a->pa->stepx = 1;
		a->pa->sidedistx = (a->pa->mapx + 1.0 - a->pa->rayposx)
			* a->pa->deltadistx;
	}
	if (a->pa->raydiry < 0)
	{
		a->pa->stepy = -1;
		a->pa->sidedisty = (a->pa->rayposy - a->pa->mapy)
			* a->pa->deltadisty;
	}
	else
	{
		a->pa->stepy = 1;
		a->pa->sidedisty = (a->pa->mapy + 1.0 - a->pa->rayposy)
			* a->pa->deltadisty;
	}
}

void			calc_dda(t_all *a)
{
	int		x;

	x = 0;
	a->pa->rayposx = a->pa->posx;
	a->pa->rayposy = a->pa->posy;
	a->pa->orientation = acos(a->pa->dirx) * 360 / M_PI;
	if (isnan(a->pa->orientation) != 0)
		a->pa->orientation = 360;
	if (a->en->data)
		ft_bzero(a->en->data, a->en->sl * WINY);
	while (x < (int)WINX)
	{
		init_dda(a, x);
		ray_dda(a);
		perf_dda(a);
		prep_drawing(a);
		calc_walls(a);
		print_col(a, x, a->pa->drawstart, a->pa->drawend);
		x++;
	}
}

void			init_dda(t_all *a, int x)
{
	a->pa->mapx = (int)a->pa->rayposx;
	a->pa->mapy = (int)a->pa->rayposy;
	a->pa->camera = 2 * x / WINX - 1;
	a->pa->raydirx = a->pa->dirx + a->pa->planex * a->pa->camera;
	a->pa->raydiry = a->pa->diry + a->pa->planey * a->pa->camera;
	a->pa->deltadistx = sqrt(1 + sq(a->pa->raydiry) / sq(a->pa->raydirx));
	a->pa->deltadisty = sqrt(1 + sq(a->pa->raydirx) / sq(a->pa->raydiry));
	a->pa->hit = 0;
	a->pa->perpwalldist = -1;
	a->pa->side = -1;
}

void			perf_dda(t_all *a)
{
	while (a->pa->hit == 0)
	{
		if (a->pa->sidedistx < a->pa->sidedisty)
		{
			a->pa->sidedistx += a->pa->deltadistx;
			a->pa->mapx += a->pa->stepx;
			a->pa->side = 0;
		}
		else
		{
			a->pa->sidedisty += a->pa->deltadisty;
			a->pa->mapy += a->pa->stepy;
			a->pa->side = 1;
		}
		if (a->en->map[a->pa->mapx][a->pa->mapy] > 0)
		{
			a->pa->hit = 1;
			if (a->pa->side == 0)
				a->pa->perpwalldist = (a->pa->mapx - a->pa->rayposx
					+ (1 - a->pa->stepx) / 2) / a->pa->raydirx;
			else
				a->pa->perpwalldist = (a->pa->mapy - a->pa->rayposy
					+ (1 - a->pa->stepy) / 2) / a->pa->raydiry;
		}
	}
}

void			prep_drawing(t_all *a)
{
	a->pa->lineheight = (int)(WINY / a->pa->perpwalldist);
	a->pa->drawstart = (-a->pa->lineheight / 2 + WINY / 2);
	if (a->pa->drawstart < 0)
		a->pa->drawstart = 0;
	a->pa->drawend = (a->pa->lineheight / 2 + WINY / 2);
	if (a->pa->drawend >= WINY)
		a->pa->drawend = WINY - 1;
}
