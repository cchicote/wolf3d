/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:58:45 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/03 10:58:56 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			manage_key(int keycode, void *a)
{
	treat_keycode(keycode, a);
	return (0);
}

void		treat_keycode(int keycode, t_all *a)
{
	double	olddirx;
	double	oldplanex;

	// ft_putnbrendl(keycode);
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(a->en->mlx, a->en->win);
		ft_putendl("goodbye");
		exit(0);
	}
	if (keycode == 65362)
	{
		if (a->en->map[(int)(a->pa->posx + a->pa->dirx * 0.25)][(int)a->pa->posy] == 0)
			a->pa->posx += a->pa->dirx * 0.25;
		if (a->en->map[(int)a->pa->posx][(int)(a->pa->posy + a->pa->diry * 0.25)] == 0)
			a->pa->posy += a->pa->diry * 0.25;
	}
	else if (keycode == 65364)
	{
		if (a->en->map[(int)(a->pa->posx - a->pa->dirx * 0.25)][(int)a->pa->posy] == 0)
			a->pa->posx -= a->pa->dirx * 0.25;
		if (a->en->map[(int)a->pa->posx][(int)(a->pa->posy - a->pa->diry * 0.25)] == 0)
			a->pa->posy -= a->pa->diry * 0.25;
	}
	else if (keycode == 65363)
	{
		olddirx = a->pa->dirx;
		a->pa->dirx = a->pa->dirx * cos(-0.05) - a->pa->diry * sin(-0.05);
		a->pa->diry = olddirx * sin(-0.05) + a->pa->diry * cos(-0.05);
		oldplanex = a->pa->planex;
		a->pa->planex = a->pa->planex * cos(-0.05) - a->pa->planey * sin(-0.05);
		a->pa->planey = oldplanex * sin(-0.05) + a->pa->planey * cos(-0.05);
	}
	else if (keycode == 65361)
	{
		olddirx = a->pa->dirx;
		a->pa->dirx = a->pa->dirx * cos(0.05) - a->pa->diry * sin(0.05);
		a->pa->diry = olddirx * sin(0.05) + a->pa->diry * cos(0.05);
		oldplanex = a->pa->planex;
		a->pa->planex = a->pa->planex * cos(0.05) - a->pa->planey * sin(0.05);
		a->pa->planey = oldplanex * sin(0.05) + a->pa->planey * cos(0.05);
	}
	mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
	calc_dda(a);
// 	// display_map(a);
}