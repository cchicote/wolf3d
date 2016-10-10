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

int			manage_key(int keycode, void *e)
{
	treat_keycode(keycode, e);
	return (0);
}

int			manage_key2(int keycode, void *a)
{
	treat_keycode2(keycode, a);
	return (0);
}

void		treat_keycode2(int keycode, t_all *a)
{
	int			tmpxm;
	int			tmpym;
	int			tmpxp;
	int			tmpyp;


	tmpyp = a->para->posY + 1;
	tmpym = a->para->posY - 1;
	tmpxp = a->para->posX + 1;
	tmpxm = a->para->posX - 1;
	ft_putnbrendl(keycode);
	if (keycode == 126 && a->envi->map[tmpym][(int)a->para->posX] == 0)
		a->para->posY--;
	else if (keycode == 125 && a->envi->map[tmpyp][(int)a->para->posX] == 0)
		a->para->posY++;
	else if (keycode == 123 && a->envi->map[(int)a->para->posY][tmpxm] == 0)
		a->para->posX--;
	else if (keycode == 124 && a->envi->map[(int)a->para->posY][tmpxp] == 0)
		a->para->posX++;
	test(a->envi, a->para);
}

void		treat_keycode(int keycode, t_env *e)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_putendl("goodbye");
		exit(0);
	}
}