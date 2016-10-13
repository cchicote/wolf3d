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
	// ft_putnbrendl(keycode);
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(a->en->mlx, a->en->win);
		ft_putendl("goodbye");
		exit(0);
	}
	if ((keycode == 126 || keycode == 65362) && a->en->map[(int)a->pa->posy - 1][(int)a->pa->posx] == 0)
		a->pa->posy -= 0.3;
	else if ((keycode == 125 || keycode == 65364) && a->en->map[(int)a->pa->posy + 1][(int)a->pa->posx] == 0)
		a->pa->posy += 0.3;
	else if ((keycode == 124 || keycode == 65363) && a->en->map[(int)a->pa->posy][(int)a->pa->posx + 1] == 0)
		a->pa->posx += 0.3;
	else if ((keycode == 123 || keycode == 65361) && a->en->map[(int)a->pa->posy][(int)a->pa->posx - 1] == 0)
		a->pa->posx -= 0.3;
	if ((keycode == 0 || keycode == 97) && a->pa->angle < 360)
	{
		if ((int)a->pa->angle == 359)
			a->pa->angle = 0;
		else
			a->pa->angle++;
	}
	else if ((keycode == 2 || keycode == 100) && a->pa->angle >= 0)
	{
		if ((int)a->pa->angle == 0)
			a->pa->angle = 359;
		else
			a->pa->angle--;
	}
	mlx_put_image_to_window(a->en->mlx, a->en->win, a->en->img, 0, 0);
	calc_dda(a);
	// display_map(a);
}