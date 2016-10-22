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

void		treat_movements(int keycode, t_all *a)
{
	if (keycode == 65362 || keycode == 126 || keycode == 13 || keycode == 119)
		moving(a, 1);
	else if (keycode == 65364 || keycode == 125 || keycode == 1
		|| keycode == 115)
		moving(a, -1);
	else if (keycode == 65363 || keycode == 124)
		turning_right(a);
	else if (keycode == 65361 || keycode == 123)
		turning_left(a);
	else if (keycode == 0 || keycode == 100)
		strafing(a, 1);
	else if (keycode == 2 || keycode == 97)
		strafing(a, -1);
}


void		treat_keycode(int keycode, t_all *a)
{
	ft_putnbrendl(keycode);
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(a->en->mlx, a->en->win);
		ft_putendl("goodbye");
		exit(0);
	}
	treat_movements(keycode, a);
	if (a->en->map[(int)a->pa->posx][(int)a->pa->posy] == 5)
	{
		a->pa->posx = 1.5;
		a->pa->posy = 1.5;
	}
	else if (a->en->map[a->pa->mapx][a->pa->mapy] == 3 && (keycode == 101 || keycode == 14))
		a->en->map[a->pa->mapx][a->pa->mapy] = 0;
	else if (a->en->map[(int)a->pa->posx][(int)a->pa->posy] == 6)
	{
		a->pa->posx = 8.5;
		a->pa->posy = 1.5;
	}
	calc_dda(a);
	if (a->en->map[(int)a->pa->posx][(int)a->pa->posy] == 7)
	{
		mlx_string_put(a->en->mlx, a->en->win, 0, 0, 0xffffff, "Congrats !");
		mlx_destroy_window(a->en->mlx, a->en->win);
		exit(0);
	}
	mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
	// mlx_put_image_to_window(a->en->mlx, a->en->win, a->xp->img, 0, 0);
}