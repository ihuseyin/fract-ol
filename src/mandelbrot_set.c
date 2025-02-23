#include "fractol.h"
#include <mlx.h>

static t_uint	mandelbrot(double real, double imag, t_uint max_iter)
{
	double	temp;
	t_comp	z;

	z.r = 0.0;
	z.i = 0.0;
	z.iter = 0;
	while ((z.r * z.r) + (z.i * z.i) < 4 && z.iter < max_iter)
	{
		temp = ((z.r * z.r) - (z.i * z.i)) + real;
		z.i = (2.0 * z.r * z.i) + imag;
		z.r = temp;
		z.iter++;
	}
	return (z.iter);
}

void	mandelbrot_set(t_data *var)
{
	t_comp	c;
	t_uint	color;
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			c.r = map(var->map.min_x, var->map.max_x, x, WIN_W);
			c.i = map(var->map.max_y, var->map.min_y, y, WIN_H);
			c.iter = mandelbrot(c.r, c.i, var->map.max_iter);
			if (c.iter == var->map.max_iter)
				color = 0x000000;
			else
				color = color_shift(c.iter, var->map.max_iter, var->map.shift);
			put_pixel(&var->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
}
