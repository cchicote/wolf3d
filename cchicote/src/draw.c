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
			return (0xffffff / 2);
		return (0xffffff);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 2)
	{
		if (a->pa->side == 1)
			return (0xff0000 / 2);
		return (0xff0000);
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 3)
	{
		if (a->pa->side == 1)
			return (0x00ff00 / 2);
		return (0x00ff00);
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
			return (0xffff00 / 2);
		return (0xffff00);
	}
	else
		return (0x000000);
}

void			print_col(t_all *a, int x, int start, int end)
{
	int i;
	int	j;

	i = 0;
	j = start;
	while (i < start)
	{
		my_pixel_put(a->en, x, i, 0x66CCFF);
		i++;
	}
	while (start < end)
	{
		my_pixel_put(a->en, x, start, choose_color(a));
		start++;
	}
	while (start < WINY)
	{
		my_pixel_put(a->en, x, start, 0x333333);
		start++;
	}
	my_pixel_put(a->en, x, start - 1, 0x000000);
	my_pixel_put(a->en, x, j, 0x000000);
}
