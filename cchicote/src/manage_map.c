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

void		display_map(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y != MAPY)
	{
		x = -1;
		while (++x != MAPX)
		{
			ft_putchar(e->map[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
