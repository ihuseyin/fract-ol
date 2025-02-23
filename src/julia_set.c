#include "fractol.h"
#include <mlx.h>

static t_uint	julia(t_comp *z, t_comp *c, t_uint max_iter)
{
	double	temp;
	t_uint	iter;

	iter = 0;
	while ((z->r * z->r) + (z->i * z->i) < 4 && iter < max_iter)
	{
		temp = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2.0 * z->r * z->i + c->i;
		z->r = temp;
		iter++;
	}
	return (iter);
}

void	julia_set(t_data *var)
{
	t_comp	z;
	t_uint	color;
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			z.r = map(var->map.min_x, var->map.max_x, x, WIN_W);
			z.i = map(var->map.max_y, var->map.min_y, y, WIN_H);
			z.iter = julia(&z, &var->map.c, var->map.max_iter);
			if (z.iter == var->map.max_iter)
				color = 0x000000;
			else
				color = color_shift(z.iter, var->map.max_iter, var->map.shift);
			put_pixel(&var->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
