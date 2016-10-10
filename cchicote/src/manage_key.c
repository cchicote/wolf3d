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
		mlx_destroy_window(a->envi->mlx, a->envi->win);
		ft_putendl("goodbye");
		exit(0);
	}
	if (keycode == 126 && a->envi->map[(int)a->para->posY - 1][(int)a->para->posX] == 0)
		a->para->posY--;
	else if (keycode == 125 && a->envi->map[(int)a->para->posY + 1][(int)a->para->posX] == 0)
		a->para->posY++;
	else if (keycode == 124 && a->envi->map[(int)a->para->posY][(int)a->para->posX + 1] == 0)
		a->para->posX++;
	else if (keycode == 123 && a->envi->map[(int)a->para->posY][(int)a->para->posX - 1] == 0)
		a->para->posX--;
	display_map(a);
}