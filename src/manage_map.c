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

void		put_data(t_env *e)
{
	int x;
	int	y;

	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (++x < MAPX)
		{
			if ((y == 0) || (y == 1 && (x == 0 || x == MAPX - 1)))
				e->map[y][x] = '1';
		}
	}
}

char		*flat_map(void)
{
	int 	x;
	char	*tmp;
	
	x = -1;
	tmp = ft_strnew(MAPX);
	tmp[MAPX] = '\0';
	while (++x != MAPX)
		tmp[x] = '0';
	return (tmp);
}


void		map_init(t_env *e)
{
	int x;

	x = -1;
	e->map = (char**)ft_memalloc(sizeof(char*) * MAPY);
	while (++x != MAPX)
		e->map[x] = ft_strdup(flat_map());
	put_data(e);
}

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
