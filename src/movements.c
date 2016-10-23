/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:40:59 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/23 15:41:08 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		treat_movements(int keycode, t_all *a)
{
	if (keycode == 65362 || keycode == 126 || keycode == 13 || keycode == 119)
		moving(a, 1);
	else if (keycode == 65364 || keycode == 125 || keycode == 1
		|| keycode == 115)
		moving(a, -1);
	else if (keycode == 2 || keycode == 100)
		strafing(a, 1);
	else if (keycode == 0 || keycode == 97)
		strafing(a, -1);
	else if (keycode == 65363 || keycode == 124)
		turning_right(a);
	else if (keycode == 65361 || keycode == 123)
		turning_left(a);
}

void		moving(t_all *a, int fw)
{
	int		next_posx;
	int		next_posy;

	next_posx = a->en->map[(int)(a->pa->posx + (a->pa->dirx *
		a->pa->move_speed * fw))][(int)a->pa->posy];
	next_posy = a->en->map[(int)a->pa->posx][(int)(a->pa->posy + (a->pa->diry
		* a->pa->move_speed * fw))];
	if (next_posx == 0 || next_posx == 5 || next_posx == 6 || next_posx == 7)
	{
		if (fw == 1)
			a->pa->posx += a->pa->dirx * a->pa->move_speed;
		else if (fw == -1)
			a->pa->posx -= a->pa->dirx * a->pa->move_speed;
	}
	if (next_posy == 0 || next_posy == 5 || next_posy == 6 || next_posy == 7)
	{
		if (fw == 1)
			a->pa->posy += a->pa->diry * a->pa->move_speed;
		else if (fw == -1)
			a->pa->posy -= a->pa->diry * a->pa->move_speed;
	}
}

void		strafing(t_all *a, int lr)
{
	int		next_posx;
	int		next_posy;

	next_posx = a->en->map[(int)(a->pa->posx + (a->pa->planex *
		a->pa->move_speed * lr))][(int)a->pa->posy];
	next_posy = a->en->map[(int)a->pa->posx][(int)(a->pa->posy + (a->pa->planey
		* a->pa->move_speed * lr))];
	if (next_posx == 0 || next_posx == 5 || next_posx == 6 || next_posx == 7)
	{
		if (lr == 1)
			a->pa->posx += a->pa->planex * a->pa->move_speed;
		else if (lr == -1)
			a->pa->posx -= a->pa->planex * a->pa->move_speed;
	}
	if (next_posy == 0 || next_posy == 5 || next_posy == 6 || next_posy == 7)
	{
		if (lr == 1)
			a->pa->posy += a->pa->planey * a->pa->move_speed;
		else if (lr == -1)
			a->pa->posy -= a->pa->planey * a->pa->move_speed;
	}
}

void		turning_right(t_all *a)
{
	double	olddirx;
	double	oldplanex;

	olddirx = a->pa->dirx;
	a->pa->dirx = a->pa->dirx * cos(-a->pa->rot_speed) - a->pa->diry
		* sin(-a->pa->rot_speed);
	a->pa->diry = olddirx * sin(-a->pa->rot_speed) + a->pa->diry
		* cos(-a->pa->rot_speed);
	oldplanex = a->pa->planex;
	a->pa->planex = a->pa->planex * cos(-a->pa->rot_speed) - a->pa->planey
		* sin(-a->pa->rot_speed);
	a->pa->planey = oldplanex * sin(-a->pa->rot_speed) + a->pa->planey
		* cos(-a->pa->rot_speed);
}

void		turning_left(t_all *a)
{
	double	olddirx;
	double	oldplanex;

	olddirx = a->pa->dirx;
	a->pa->dirx = a->pa->dirx * cos(a->pa->rot_speed) - a->pa->diry
		* sin(a->pa->rot_speed);
	a->pa->diry = olddirx * sin(a->pa->rot_speed) + a->pa->diry
		* cos(a->pa->rot_speed);
	oldplanex = a->pa->planex;
	a->pa->planex = a->pa->planex * cos(a->pa->rot_speed) - a->pa->planey
		* sin(a->pa->rot_speed);
	a->pa->planey = oldplanex * sin(a->pa->rot_speed) + a->pa->planey
		* cos(a->pa->rot_speed);
}
