/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:05:13 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/25 19:15:36 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		put_pixel_sier(int x, int y, t_env *e, int color)
{
	int		*i;
	int		t;

	if (x > 0 && y > 0 && x < X && y < Y)
	{
		t = x * 4 + y * e->img_line;
		i = (int *)&e->data_img[t];
		*i = color;
	}
}

void		fractale_sierpenski(t_env *e)
{
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		e->c[e->x][0] = 1;
		e->c[e->x][e->y + 1] = 1;
		while (++e->y < e->x - 1)
			e->c[e->x][e->y] = (e->c[e->x - 1][e->y - 1] + e->c[e->x - 1][e->y]);
	}
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < X)
		{
			if (e->c[e->x][e->y] % 2)
				put_pixel_sier(e->x, e->y, e, 0xFFFFFF);
			else
				put_pixel_sier(e->x, e->y, e, 0xFFFFFF * e->x * e->y);
		}
	}
}
