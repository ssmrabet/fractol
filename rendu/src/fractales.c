/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:05:13 by smrabet           #+#    #+#             */
/*   Updated: 2016/11/28 13:12:02 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			fractale_man(t_env *e)
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
				e->iz = 2 * e->iz * tmp + e->ic;
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void			fractale_jul(t_env *e)
{
	float		tmp;

	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rz = e->x / e->zoom + e->x1;
			e->iz = e->y / e->zoom + e->y1;
			e->a = 0;
			while (e->a < e->i && e->rz * e->rz + e->iz * e->iz < 4)
			{
				tmp = e->rz;
				e->rz = e->rz * e->rz - e->iz * e->iz + e->rc;
				e->iz = 2 * e->iz * tmp + e->ic;
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void			fractale_bship(t_env *e)
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
				e->rz = fabs(e->rz * e->rz - e->iz * e->iz + e->rc);
				e->iz = fabs(2 * e->iz * tmp + e->ic);
				e->a++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

static float	calcul(t_env *e, float tmp)
{
	float		rz;
	float		iz;
	float		x;
	float		r;

	r = e->rz;
	rz = e->rz * e->rz;
	iz = e->iz * e->iz;
	x = rz - iz;
	tmp = 3.0 * (x * x + 4.0 * rz * iz);
	if (tmp == 0.0)
		tmp = 0.000001;
	e->rz = (2.0 / 3.0) * r + x / tmp;
	e->iz = (2.0 / 3.0) * e->iz - 2.0 * r * e->iz / tmp;
	return (tmp);
}

void			fractale_newton(t_env *e, float r, float tmp)
{
	e->x = -1;
	while (++e->x < X)
	{
		e->y = 0;
		while (++e->y < Y)
		{
			e->rz = e->x / e->zoom + e->x1;
			e->iz = e->y / e->zoom + e->y1;
			e->a = -1;
			tmp = 1;
			while (++e->a < e->i)
				tmp = calcul(e, tmp);
			put_pixel_color(e->x, e->y, e);
		}
	}
}
