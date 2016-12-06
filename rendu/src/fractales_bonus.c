/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:05:13 by smrabet           #+#    #+#             */
/*   Updated: 2016/11/28 13:43:18 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			fractale_mandelbar4(t_env *e, float tmp, float rz, float iz)
{
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rc = e->x / e->zoom + e->x1;
			e->ic = e->y / e->zoom + e->y1;
			e->rz = 0;
			e->iz = 0;
			e->a = 0;
			while (e->a < e->i && e->rz * e->rz + e->iz * e->iz < 4)
			{
				tmp = e->rz;
				iz = e->iz * e->iz;
				rz = e->rz * e->rz;
				e->rz = rz * e->rz - 3 * e->rz * iz + e->rc;
				e->iz = -(3 * rz * e->iz - iz * e->iz) + e->ic;
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void			fractale_tricorn(t_env *e)
{
	float		tmp;

	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rc = e->x / e->zoom + e->x1;
			e->ic = e->y / e->zoom + e->y1;
			e->rz = 0;
			e->iz = 0;
			e->a = 0;
			while (e->a < e->i && e->rz * e->rz + e->iz * e->iz < 4)
			{
				tmp = e->rz;
				e->rz = e->rz * e->rz - e->iz * e->iz + e->rc;
				e->iz = -(2 * e->iz * tmp) + e->ic;
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

static float	calcul(t_env *e, float tmp)
{
	float		r;
	float		i;
	float		rz;
	float		iz;

	r = e->rz;
	i = e->iz;
	rz = e->rz * e->rz;
	iz = e->iz * e->iz;
	tmp = (rz + iz) * (rz + iz);
	e->rz = (2 * tmp * rz * e->rz - iz) / (3 * tmp);
	e->iz = (2 * e->iz * (tmp - r)) / (3 * tmp);
	tmp = (e->rz - r) * (e->rz - r) + (e->iz - i) * (e->iz - i);
	return (tmp);
}

void			fractale_newton_love(t_env *e, float r, float tmp)
{
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rz = e->x / e->zoom + e->x1;
			e->iz = e->y / e->zoom + e->y1;
			e->a = 0;
			tmp = 1;
			while (e->a < e->i && tmp > 0.000001)
			{
				tmp = calcul(e, tmp);
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}
