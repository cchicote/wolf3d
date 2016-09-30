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
	e->map[0][0] = '1';
	e->map[0][1] = '1';
	e->map[0][2] = '1';
	e->map[0][3] = '1';
	e->map[0][4] = '1';
	e->map[1][0] = '1';
	e->map[1][4] = '1';
}

char		*flat_map(void)
{
	int 	x;
	char	*tmp;
	
	x = -1;
	tmp = ft_strnew(MAP_X);
	tmp[MAP_X] = '\0';
	while (++x != MAP_X)
		tmp[x] = '0';
	return (tmp);
}


void		map_init(t_env *e)
{
	int x;

	x = -1;
	e->map = (char**)ft_memalloc(sizeof(char*) * MAP_Y);
	while (++x != MAP_X)
		e->map[x] = ft_strdup(flat_map());
	put_data(e);
}

void		display_map(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y != MAP_Y)
	{
		x = -1;
		while (++x != MAP_X)
		{
			ft_putchar(e->map[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
