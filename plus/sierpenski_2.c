#include "../inc/fractol.h"

void		fractale(t_env *e)
{
	remplit_triangle(0, 0, X / 2, e);
}

void		remplit_triangle(int x, int y, int taille, t_env *e)
{
	if (taille == 0)
		put_pixel(x, y, e);
	else
	{
		remplit_triangle(x, y, taille / 2, e);
		remplit_triangle(x + taille, y, taille / 2, e);
		remplit_triangle(x, y + taille, taille / 2, e);
	}
}
