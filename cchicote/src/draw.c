/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchicote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:53:00 by cchicote          #+#    #+#             */
/*   Updated: 2016/10/03 10:53:18 by cchicote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double			sq(double a)
{
	return (a * a);
}



void			my_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	biscolor;

	biscolor = mlx_get_color_value(e->mlx, color);
	if (x < WINX && y < WINY && x > 0 && y > 0)
	{
		e->data[y * e->sl + x * e->bpp / 8] = (biscolor & 0x0000ff);
		e->data[y * e->sl + x * e->bpp / 8 + 1] = (biscolor & 0x00ff00) >> 8;
		e->data[y * e->sl + x * e->bpp / 8 + 2] = (biscolor & 0xff0000) >> 16;
	}
}

void			calc_dda(t_all *a)
{
	t_res		ret_x;
	t_res		ret_y;

	a->pa->alpha = a->pa->angle * (M_PI / 180);
	a->pa->m = tan(a->pa->alpha);
	a->pa->b = a->pa->posy - (a->pa->m) * (a->pa->posx);
	ret_x = ddax(a);
	ret_y = dday(a);
	printf("m : %f\n", a->pa->m);
	printf("angle : %f\n", a->pa->angle);
	printf("alpha : %f\n", a->pa->alpha);
	printf("ret_x : %f / %f\n", ret_x.x, ret_x.y);
	printf("ret_y : %f / %f\n", ret_y.x, ret_y.y);
	printf("dist_retx : %f\n", ret_x.dist);
	printf("dist_rety : %f\n", ret_y.dist);
	a->pa->xonmap = ret_x.dist < ret_y.dist ? (int)ret_x.x : (int)ret_y.x;
	a->pa->yonmap = ret_x.dist < ret_y.dist ? (int)ret_x.y : (int)ret_y.y;
}

t_res			ddax(t_all *a)
{
	t_res			ret;
	double			x;
	double			y;

	if (a->pa->angle >= 270 || a->pa->angle <= 90)
		y = (int)a->pa->posy;
	else
		y = (int)a->pa->posy + 1;
	x = (y - a->pa->b) / a->pa->m;
	// printf("ddax :        x : %f / y : %f\n", x, y);
	while (x < MAPX && x >= 0 && y < MAPY && y >= 0 && a->en->map[(int)y][(int)x] == 0)
	{
		if (a->pa->angle >= 270 || a->pa->angle <= 90)
			y++;
		else
			y--;
		x = (y - a->pa->b) / a->pa->m;
		// a->pa->m * y + a->pa->b;
	}
	ret.x = x;
	ret.y = y;
	ret.dist = sqrt(sq(x - a->pa->posx) + sq(y - a->pa->posy));
	return(ret);
	// printf("x : %f // y : %f\n", x, y);
}

t_res			dday(t_all *a)
{
	t_res			ret;
	double			x;
	double			y;

	if (a->pa->angle >= 0 && a->pa->angle <= 180)
		x = (int)a->pa->posx + 1;
	else
		x = (int)a->pa->posx;
	y = a->pa->m * x + a->pa->b;
	// printf("dday :        x : %f / y : %f\n", x, y);
	while (x < MAPX && x >= 0 && y < MAPY && y >= 0 && a->en->map[(int)y][(int)x] == 0)
	{
		if (a->pa->angle >= 0 && a->pa->angle <= 180)
			x++;
		else
			x--;
		y = a->pa->m * x + a->pa->b;
	}
	ret.x = x;
	ret.y = y;
	ret.dist = sqrt(sq(x - a->pa->posx) + sq(y - a->pa->posy));
	return (ret);
	// printf("x : %f // y : %f\n", x, y);
}
