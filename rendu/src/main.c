/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:27:31 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/28 18:21:39 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		put_pixel(int x, int y, t_env *e)
{
	int		*i;
	int		t;

	if (y < Y && x < X && x > 0 && y > 0)
	{
		t = x * 4 + y * e->img_line;
		i = (int *)&e->data_img[t];
		if (e->a == e->i)
			*i = 0x000000;
		else
			*i = 0x0000FF + (100000000 * e->a) / (e->i + 60);
	}
}

void		put_pixel_color(int x, int y, t_env *e)
{
	int		*i;
	int		t;

	if (y < Y && x < X && x > 0 && y > 0)
	{
		t = x * 4 + y * e->img_line;
		i = (int *)&e->data_img[t];
		if (e->rz > 0)
			*i = 0xFF0000 * e->i;
		else if ((e->rz < -0.3) && (e->iz > 0))
			*i = 0x00FF00 * e->i;
		else
			*i = 0x0000FF * e->i;
	}
}

void		init_val(t_env *e)
{
	e->bloc = 0;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->i = 18;
	e->zoom = 100;
	e->rc = 0.285;
	e->ic = 0.01;
}

void		ft_error(void)
{
	ft_putstr_fd("choose an awesome fractale.\n", 2);
	ft_putstr_fd("1 : Mandelbrot.\n", 2);
	ft_putstr_fd("2 : Julia.\n", 2);
	ft_putstr_fd("3 : Burning Ship.\n", 2);
	ft_putstr_fd("4 : Chamelon.\n", 2);
	ft_putstr_fd("5 : Tricorn.\n", 2);
	ft_putstr_fd("6 : Newton Love.\n", 2);
	ft_putstr_fd("7 : Newton.\n", 2);
	ft_putstr_fd("8 : Mandelbrot4.\n", 2);
	exit(-1);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error();
	init_val(&e);
	if (strcmp(av[1], "1") == 0 || strcmp(av[1], "2") == 0 ||
		strcmp(av[1], "3") == 0 || strcmp(av[1], "4") == 0 ||
		strcmp(av[1], "5") == 0 || strcmp(av[1], "6") == 0 ||
		strcmp(av[1], "7") == 0 || strcmp(av[1], "8") == 0)
		e.fract = ft_atoi(av[1]);
	else
		ft_error();
	e.mlx = mlx_init(e);
	e.win = mlx_new_window(e.mlx, X, Y, "FRACTOL");
	win(&e);
}
