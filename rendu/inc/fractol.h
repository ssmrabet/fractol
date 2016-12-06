/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:48:30 by smrabet           #+#    #+#             */
/*   Updated: 2016/12/06 10:47:50 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define Y 400
# define X 400
# define ESC 53
# define P_ITERATION 83
# define N_ITERATION 86
# define RESET 84
# define CHANGE 85
# define BLOC 85
# define IN 5
# define OUT 4
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MOIN 78

typedef struct		s_env
{
	int				color;
	int				fract;
	int				bloc;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	int				bpp;
	int				img_line;
	int				end;
	float			zoom;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			img_x;
	float			img_y;
	float			rc;
	float			ic;
	float			rz;
	float			iz;
	int				x;
	int				y;
	int				a;
	int				i;
}					t_env;

void				put_pixel(int x, int y, t_env *e);
void				put_pixel_color(int x, int y, t_env *e);
void				init_val(t_env *e);
void				change(t_env *e);
void				menu(t_env *e);

int					key(int key, t_env *e);
int					mouse_change(int x, int y, t_env *e);
int					mouse_zoom(int key, int x, int y, t_env *e);

void				win(t_env *e);
void				submit_change(t_env *e);
void				fractale_function(t_env *e);

void				fractale_newton(t_env *e, float r, float tmp);
void				fractale_newton_love(t_env *e, float r, float tmp);

void				fractale_neg(t_env *e);
void				fractale_man(t_env *e);
void				fractale_man2(t_env *e, float tmp, float rz, float iz);
void				fractale_man4(t_env *e, float tmp, float rz, float iz);
void				fractale_bship(t_env *e);
void				fractale_jul(t_env *e);
void				fractale_tricorn(t_env *e);
void				fractale_mandelbar4(t_env *e, float tmp,
					float rz, float iz);

#endif
