/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 18:55:25 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/18 18:55:33 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double			sq(double a)
{
	return (a * a);
}

double			degre_to_rad(double angle)
{
	return ((angle * (M_PI / 180)));
}

void			calc_walls(t_all *a)
{
	if (a->pa->side == 0)
		a->pa->wallx = a->pa->rayposy + a->pa->perpwalldist * a->pa->raydiry;
	else
		a->pa->wallx = a->pa->rayposx + a->pa->perpwalldist * a->pa->raydirx;
	a->pa->wallx -= (int)a->pa->wallx;
	a->pa->texx = (int)(a->pa->wallx * a->pa->texsize);
	if (a->pa->side == 0 && a->pa->raydirx > 0)
		a->pa->texx = a->pa->texsize - a->pa->texx - 1;
	else if (a->pa->side == 1 && a->pa->raydiry < 0)
		a->pa->texx = a->pa->texsize - a->pa->texx - 1;
	// printf("%f\n%d\n", a->pa->wallx, a->pa->texx);
}
