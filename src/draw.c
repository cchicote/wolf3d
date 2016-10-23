/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:53:00 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/03 10:53:18 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			my_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	biscolor;

	biscolor = mlx_get_color_value(e->mlx, color);
	if (x < WINX && y < WINY && x > 0 && y > 0)
	{
		e->data[y * e->sl + x * e->bpp / 8] = (biscolor & 0x0000ff);
		e->data[y * e->sl + x * e->bpp / 8 + 1] = (biscolor & 0x00ff00) >> 8;
		e->data[y * e->sl + x * e->bpp / 8 + 2] = (biscolor & 0xff0000) >> 16;
	}
}

int				choose_color(t_all *a)
{
	if (a->en->map[a->pa->mapx][a->pa->mapy] == 1)
	{
		if (a->pa->side == 1)
			return (0xF8F8FF);
		return (0xffffff);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 2)
	{
		if (a->pa->side == 1)
			return (0xB22222);
		return (0xff0000);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 3)
	{
		if (a->pa->side == 1)
			return (0x663300);
		return (0x663300);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 4)
	{
		if (a->pa->side == 1)
			return (0x0000ff / 2);
		return (0x0000ff);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 5)
	{
		if (a->pa->side == 1)
			return (0x000000);
		return (0x000000);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 6)
	{
		if (a->pa->side == 1)
			return (0x3333CC);
		return (0x3333CC);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 7)
		return (0xFFFF00);
	else
		return (0xFFFF00);
}

int				choose_texture(t_all *a, int x, int y)
{
	int		color;

	color = 0xffffff;
	x++;
	y++;
	a->en->map[0][0] = 1;
	return (color);
}

void			print_col(t_all *a, int x, int start, int end)
{
	// int	j;
	int i;

	i = 0;
	// j = start;
	while (i < start)
	{
		my_pixel_put(a->en, x, i, 0x66CCFF);
		i++;
	}
	while (start < end)
	{
		a->pa->texy = (start * 2 - WINY + a->pa->lineheight) *
		(a->pa->texsize / 2) / a->pa->lineheight;
		my_pixel_put(a->en, x, start, choose_color(a));
		start++;
	}
	while (start < WINY)
	{
		my_pixel_put(a->en, x, start, 0x333333);
		start++;
	}
	// my_pixel_put(a->en, x, end, 0x000000);
	// my_pixel_put(a->en, x, j, 0x000000);
}
