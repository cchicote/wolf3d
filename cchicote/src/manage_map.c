/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:18:02 by cchicote          #+#    #+#             */
/*   Updated: 2016/09/30 12:33:43 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		display_map(t_all *a)
{
	int		x;
	int		y;

	y = -1;
	while (++y != MAPY)
	{
		x = -1;
		while (++x != MAPX)
		{
			if (x == a->pa->xonmap && y == a->pa->yonmap)
			{
				ft_putstr("\033[35m");
				ft_putnbr(a->en->map[y][x]);
				ft_putstr("\033[0;0m");
			}
			else if (x == (int)a->pa->posx && y == (int)a->pa->posy)
			{
				ft_putstr("\033[32m");
				ft_putnbr(a->en->map[y][x]);
				ft_putstr("\033[0;0m");
			}
			else if (a->en->map[y][x] == 1)
			{
				ft_putstr("\033[31m");
				ft_putnbr(a->en->map[y][x]);
				ft_putstr("\033[0;0m");
			}
			else if (a->en->map[y][x] > 1)
			{
				ft_putstr("\033[33m");
				ft_putnbr(a->en->map[y][x]);
				ft_putstr("\033[0;0m");
			}
			else
				ft_putnbr(a->en->map[y][x]);
			ft_putstr(" ");
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
