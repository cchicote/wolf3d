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
	if (keycode == 65362 || keycode == 126)
	{
		if (a->en->map[(int)(a->pa->posx + a->pa->dirx * a->pa->move_speed)][(int)a->pa->posy] == 0 || a->en->map[(int)(a->pa->posx + a->pa->dirx * a->pa->move_speed)][(int)a->pa->posy] == 5)
			a->pa->posx += a->pa->dirx * a->pa->move_speed;
		if (a->en->map[(int)a->pa->posx][(int)(a->pa->posy + a->pa->diry * a->pa->move_speed)] == 0 || a->en->map[(int)a->pa->posx][(int)(a->pa->posy + a->pa->diry * a->pa->move_speed)] == 5)
			a->pa->posy += a->pa->diry * a->pa->move_speed;
	}
	else if (keycode == 65364 || keycode == 125)
	{
		if (a->en->map[(int)(a->pa->posx - a->pa->dirx * a->pa->move_speed)][(int)a->pa->posy] == 0 || a->en->map[(int)(a->pa->posx - a->pa->dirx * a->pa->move_speed)][(int)a->pa->posy] == 5)
			a->pa->posx -= a->pa->dirx * a->pa->move_speed;
		if (a->en->map[(int)a->pa->posx][(int)(a->pa->posy - a->pa->diry * a->pa->move_speed)] == 0 || a->en->map[(int)a->pa->posx][(int)(a->pa->posy - a->pa->diry * a->pa->move_speed)] == 5)
			a->pa->posy -= a->pa->diry * a->pa->move_speed;
	}
	else if (keycode == 65363 || keycode == 124)
	{
		olddirx = a->pa->dirx;
		a->pa->dirx = a->pa->dirx * cos(-a->pa->rot_speed) - a->pa->diry * sin(-a->pa->rot_speed);
		a->pa->diry = olddirx * sin(-a->pa->rot_speed) + a->pa->diry * cos(-a->pa->rot_speed);
		oldplanex = a->pa->planex;
		a->pa->planex = a->pa->planex * cos(-a->pa->rot_speed) - a->pa->planey * sin(-a->pa->rot_speed);
		a->pa->planey = oldplanex * sin(-a->pa->rot_speed) + a->pa->planey * cos(-a->pa->rot_speed);
	}
	else if (keycode == 65361 || keycode == 123)
	{
		olddirx = a->pa->dirx;
		a->pa->dirx = a->pa->dirx * cos(a->pa->rot_speed) - a->pa->diry * sin(a->pa->rot_speed);
		a->pa->diry = olddirx * sin(a->pa->rot_speed) + a->pa->diry * cos(a->pa->rot_speed);
		oldplanex = a->pa->planex;
		a->pa->planex = a->pa->planex * cos(a->pa->rot_speed) - a->pa->planey * sin(a->pa->rot_speed);
		a->pa->planey = oldplanex * sin(a->pa->rot_speed) + a->pa->planey * cos(a->pa->rot_speed);
	}
	calc_dda(a);
	mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
	if (a->en->map[(int)a->pa->posx][(int)a->pa->posy] == 5)
	{
		mlx_string_put(a->en->mlx, a->en->win, 0, 0, 0xffffff, "Felicitations !");
		a->en->map[(int)a->pa->posx][(int)a->pa->posy] = 0;
		// mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
		// mlx_destroy_window(a->en->mlx, a->en->win);
		// exit(0);
	}
}