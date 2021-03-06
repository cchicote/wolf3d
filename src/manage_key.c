/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:58:45 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/23 13:51:48 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			manage_key(int keycode, void *a)
{
	treat_keycode(keycode, a);
	return (0);
}

void		check_case(t_all *a, int case_num)
{
	if (case_num == 5)
	{
		a->pa->posx = 9.5;
		a->pa->posy = 2.5;
	}
	else if (case_num == 6)
	{
		a->pa->posx = 7.5;
		a->pa->posy = 2.5;
	}
}

void		change_speed(int keycode, t_all *a)
{
	if ((keycode == 49 || keycode == 18) && a->pa->rot_speed < 0.5)
		a->pa->rot_speed += 0.01;
	else if ((keycode == 50 || keycode == 19) && a->pa->rot_speed > 0.01)
		a->pa->rot_speed -= 0.01;
	else if ((keycode == 51 || keycode == 20) && a->pa->move_speed < 0.5)
		a->pa->move_speed += 0.01;
	else if ((keycode == 52 || keycode == 21) && a->pa->move_speed > 0.01)
		a->pa->move_speed -= 0.01;
}

void		treat_keycode(int keycode, t_all *a)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(a->en->mlx, a->en->win);
		exit(0);
	}
	treat_movements(keycode, a);
	change_speed(keycode, a);
	check_case(a, a->en->map[(int)a->pa->posx][(int)a->pa->posy]);
	if (a->en->map[a->pa->mapx][a->pa->mapy] == 3 && (keycode == 101
		|| keycode == 14))
		a->en->map[a->pa->mapx][a->pa->mapy] = 0;
	else if (keycode == 114 || keycode == 15)
	{
		if (a->pa->reverse == 1)
			a->pa->reverse = 0;
		else
			a->pa->reverse = 1;
	}
	calc_dda(a);
	mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
}
