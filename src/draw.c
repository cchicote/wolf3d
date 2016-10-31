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

void			print_col(t_all *a, int x, int start, int end)
{
	int i;

	i = 0;
	while (i++ < start)
	{
		if (a->pa->reverse == 1)
			my_pixel_put(a->en, x, i, a->pa->ground);
		else if (a->pa->reverse == 0)
			load_sky_to_data(a, x, i);
	}
	while (start < end)
	{
		a->pa->texy = (start * 2 - WINY + a->pa->lineheight) *
		(a->pa->texsize / 2) / a->pa->lineheight;
		load_texel(a, x, start);
		start++;
	}
	while (start < WINY)
	{
		if (a->pa->reverse == 1)
			load_sky_to_data(a, x, start);
		else if (a->pa->reverse == 0)
			my_pixel_put(a->en, x, start, a->pa->ground);
		start++;
	}
}

void			load_texel(t_all *a, int x, int y)
{
	int		n;

	n = a->en->map[a->pa->mapx][a->pa->mapy];
	if (x < WINX && y < WINY && x > 0 && y > 0)
	{
		a->en->data[y * a->en->sl + x * a->en->bpp / 8] = a->te[n]->data
			[a->pa->texy * a->te[n]->sl + a->pa->texx * a->te[n]->bpp / 8];
		a->en->data[y * a->en->sl + x * a->en->bpp / 8 + 1] = a->te[n]->data
			[a->pa->texy * a->te[n]->sl + a->pa->texx * a->te[n]->bpp / 8 + 1];
		a->en->data[y * a->en->sl + x * a->en->bpp / 8 + 2] = a->te[n]->data
			[a->pa->texy * a->te[n]->sl + a->pa->texx * a->te[n]->bpp / 8 + 2];
	}
}

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

void			load_sky_to_data(t_all *a, int x, int y)
{
	if (x < a->te[0]->width && y < a->te[0]->height && x > 0 && y > 0)
	{
		a->en->data[y * a->en->sl + x * a->en->bpp / 8] = a->te[0]->data[y
			* a->te[0]->sl + (x + (int)(a->pa->orientation
			* a->te[0]->sl / 360)) * a->te[0]->bpp / 8];
		a->en->data[y * a->en->sl + x * a->en->bpp / 8 + 1] = a->te[0]->data[y
			* a->te[0]->sl + (x + (int)(a->pa->orientation
			* a->te[0]->sl / 360)) * a->te[0]->bpp / 8 + 1];
		a->en->data[y * a->en->sl + x * a->en->bpp / 8 + 2] = a->te[0]->data[y
			* a->te[0]->sl + (x + (int)(a->pa->orientation
			* a->te[0]->sl / 360)) * a->te[0]->bpp / 8 + 2];
	}
}
